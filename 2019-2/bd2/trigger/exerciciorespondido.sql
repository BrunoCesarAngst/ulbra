create database estoque;

create table produtos (
  cod_produto serial primary key,
  nome_produto text,
  qtd_estoque numeric,
  estoque_min numeric,
  valor_produto money
);

create table vendas (
  cod_venda serial primary key,
  data_venda date
);

create table itens_venda (
  cod_produto_fk int not null,
  cod_venda_fk int not null,
  quantidade numeric,
  constraint cod_produto_fk
    foreign key(cod_produto_fk) references produtos (cod_produto),
  constraint cod_vendas_fk
    foreign key(cod_venda_fk)  references vendas (cod_venda),
      primary key(cod_produto_fk, cod_venda_fk)
);

create or replace function estoque_gatilho()
  returns trigger as $estoque_gatilho$
declare
  estoqueMin integer;
  estoque integer;
begin
  --atualiza estoque
  update produtos set qtd_estoque=qtd_estoque-new.quantidade
    where cod_produto = new.cod_produto_fk;

  estoqueMin = (select estoque_min
    from produtos 
      where cod_produto=new.cod_produto_fk);

  estoque = (select qtd_estoque
    from produtos
      where cod_produto=new.cod_produto_fk);

  if estoque < estoqueMin then
    raise notice 'Estoque do % abaixo do minimo', (select nome_produto
      from produtos
        where cod_produto=new.cod_produto_fk);
  end if;
  return new;
end;
$estoque_gatilho$ language plpgsql;

create trigger estoque_gatilho after insert on itens_venda for each row execute procedure estoque_gatilho();


------------ default a data....
  alter table vendas
  alter column data_venda set default current_timestamp;
-----------

insert into produtos values (1, 'Arroz', 50, 20, 3.5);
insert into produtos values (2, 'Feijão', 40, 20, 4.5);
insert into produtos values (3, 'Massa', 30, 10, 2.5);
insert into produtos values (4, 'Farinha', 50, 20, 3.6);

select * from produtos;

insert into vendas values(1, now());
insert into vendas values(2, now());
insert into vendas values(3, now());

select * from vendas;

insert into itens_venda values(2,3,30);
insert into itens_venda values(1,2,5);

select * from itens_venda;
