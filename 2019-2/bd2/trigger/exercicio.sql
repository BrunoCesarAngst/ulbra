create database exerTrigger;

create table produto(
  cod_produto serial primary key,
  nome_produto text,
  qtd_estoque number,
  estoque_min number,
  valor_produto money
);

create table vendas(
  cod_venda serial primary key,
  data_venda date,
);

create table itens_vendas(
  cod_produto_fk int not null references produto(cod_produto),
  cod_venda_fk int not null references vendas(cod_venda),
  quantidade_itens number
);

create or replace function atualiza_estoque() return "trigger" as $atualiza_estoque$
 begin
  update 
  if new.qtd_estoque <= estoque_min then
    update produto set qtd_estoque =  
    raise exception 'Venda cancelada, por falte de Estoque'
  end if
  if 
 end
