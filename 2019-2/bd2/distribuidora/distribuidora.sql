-- criação do banco de dados de uma distribuidora
create database distribuidora;

-- criação das tabelas
create table cidades(
  cod_cidade serial primary key,
  nome_cidade varchar(15) not null,
  uf_cidade varchar(3) not null
);

create table fornecedores(
  cod_fornecedor serial primary key,
  nome_fornecedor varchar(25) not null,
  status_fornecedor varchar(25),
  fone_fornecedor varchar(13) not null,
  cod_cidade_ int not null references cidades (cod_cidade)
);

create table pecas(
  cod_peca serial primary key,
  nome_peca varchar(15) not null,
  cor_peca varchar(15) not null,
  peso_peca int not null,
  cod_cidade_ int not null references cidades (cod_cidade)
);

alter table pecas alter column peso_peca type decimal(5,2);

create table projetos(
  cod_projeto serial primary key,
  nome_projeto varchar(15) not null,
  cod_cidade_ int not null references cidades (cod_cidade)
);

create table fornecimento(
  cod_fornecedor_ int not null references fornecedores (cod_fornecedor),
  cod_peca_ int not null references pecas (cod_peca),
  cod_projeto_ int not null references projetos (cod_projeto),
  quantidade int not null
);

-- populando as tabelas
insert into cidades (nome_cidade, uf_cidade) values ('Arroio do Sal', 'RS');
insert into cidades (nome_cidade, uf_cidade) values ('Torres', 'RS');
insert into cidades (nome_cidade, uf_cidade) values ('Passo de Torres', 'SC');

insert into fornecedores (nome_fornecedor, status_fornecedor, fone_fornecedor, cod_cidade_ ) values ('Bruno', 'Pai', '654', 1);
insert into fornecedores (nome_fornecedor, status_fornecedor, fone_fornecedor, cod_cidade_ ) values ('Marga', 'Mae', '321', 2);
insert into fornecedores (nome_fornecedor, status_fornecedor, fone_fornecedor, cod_cidade_ ) values ('Mica', 'Filha', '777', 3);

insert into pecas (nome_peca, cor_peca, peso_peca, cod_cidade_) values ('calça', 'branco', 1, 1);
insert into pecas (nome_peca, cor_peca, peso_peca, cod_cidade_) values ('blusa', 'branco', 0.6, 2);
insert into pecas (nome_peca, cor_peca, peso_peca, cod_cidade_) values ('blusa', 'azul', 0.6, 3);
insert into pecas (nome_peca, cor_peca, peso_peca, cod_cidade_) values ('camiseta', 'branco', 08, 3);
insert into pecas (nome_peca, cor_peca, peso_peca, cod_cidade_) values ('saia', 'azul', 0.3, 2);
insert into pecas (nome_peca, cor_peca, peso_peca, cod_cidade_) values ('saia', 'vermelho', 0.3, 1);

insert into projetos (nome_projeto, cod_cidade_) values ('lado RS', 1);
insert into projetos (nome_projeto, cod_cidade_) values ('lado RS', 2);
insert into projetos (nome_projeto, cod_cidade_) values ('lado SC', 3);

insert into fornecimento (cod_fornecedor_, cod_peca_, cod_projeto_, quantidade) values (3, 1, 1, 5);
insert into fornecimento (cod_fornecedor_, cod_peca_, cod_projeto_, quantidade) values (2, 2, 3, 10);
insert into fornecimento (cod_fornecedor_, cod_peca_, cod_projeto_, quantidade) values (1, 3, 2, 5);
insert into fornecimento (cod_fornecedor_, cod_peca_, cod_projeto_, quantidade) values (3, 4, 2, 10);
insert into fornecimento (cod_fornecedor_, cod_peca_, cod_projeto_, quantidade) values (2, 5, 3, 5);
insert into fornecimento (cod_fornecedor_, cod_peca_, cod_projeto_, quantidade) values (1, 6, 1, 10);

-- relatórios e consultas

select * from cidades;
select * from fornecedores;
select * from projetos;
select * from pecas;
select * from fornecimento;

select cor_peca from pecas;
select distinct cor_peca from pecas;

select nome_cidade from cidades where uf_cidade = 'RS';

select nome_peca, 1.1 * peso_peca from pecas;

select count(*) from pecas;

select nome_fornecedor, status_fornecedor
from fornecedores, cidades
where nome_cidade='Arroio do Sal' and cod_cidade_=cod_cidade;

select nome_fornecedor, status_fornecedor
from fornecedores inner join cidades on cod_cidade_=cod_cidade
where nome_cidade='Arroio do Sal';

select nome_fornecedor
from fornecedores, pecas, fornecimento
where pecas.cod_peca=fornecimento.cod_peca_
  and fornecedores.cod_fornecedor=fornecimento.cod_fornecedor_
  and nome_peca='camiseta';

select nome_fornecedor
from fornecedores f inner join fornecimento ft 
  on f.cod_fornecedor=ft.cod_fornecedor_
  inner join pecas p on ft.cod_peca_=p.cod_peca
where nome_peca='camiseta';
