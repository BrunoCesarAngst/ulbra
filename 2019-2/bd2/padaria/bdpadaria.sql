-- bd padaria

create table tipoDeEnderecos (
  codTipoDeEndereco serial primary key,
  descricao text not null
);

create table enderecos(
  codEndereco serial primary key,
  cep varchar(10) not null,
  cidade varchar(50) not null,
  rua varchar(100) not null,
  numero int not null,
  complemento varchar(30) not null,
  codTipoDeEndereco int not null references tipoDeEnderecos(codTipoDeEndereco)
);

create table funcionarios(
  codFuncionario serial primary key,
  nome varchar(20) not null,
  funcao varchar(20) not null,
  dependente varchar(50)
);

alter table funcionarios rename column dependente to dependentes;

create table enderecoDosFuncionarios(
  codEndereco int not null references enderecos (codEndereco),
  codFuncionario int not null references funcionarios (codFuncionario)
);

create table clientes(
  codCliente serial primary key,
  nome varchar (50) not null,
  email varchar (30),
  cpf varchar (12),
  cnpj varchar (15)
);

create table enderecoClientes(
  codEndereco int not null references enderecos (codEndereco),
  codCliente int not null references clientes (codCliente)
);

create table telefones(
  codTelefone serial primary key,
  numero varchar(12),
  codFuncionario int not null references funcionarios (codFuncionario),
  codCliente int not null references clientes (codCliente)
);

alter table telefones alter column codFuncionario drop not null, alter column codCliente drop not null;

create table produtos(
  codProduto serial primary key,
  nome varchar (50) not null,
  unidade varchar (20) not null,
  valor decimal (5,2) not null,
  descricao text,
  validade date not null,
  fabricante varchar (30) not null
);

alter table produtos alter column validade drop not null, alter column fabricante drop not null;

create table encomendas(
  codEmcomendas serial primary key,
  dataPedido date not null,
  dataEntrega date not null,
  horaEntrega time not null,
  codFuncionario int not null references funcionarios (codFuncionario),
  codCliente int not null references clientes (codCliente)
);

create table podutoEncomendas(
  codPodutoEncomendas serial primary key,
  codProduto int not null references produtos (codProduto),
  codEmcomendas int not null references encomendas (codEmcomendas),
  quantidade float not null
);

alter table podutoEncomendas rename to produtoEncomendas;
alter table produtoEncomendas rename column codEmcomendas to codEncomendas;

create table vendas(
  codVenda serial primary key,
  dataHora date not null,
  codFuncionario int not null references funcionarios (codFuncionario),
  codEmcomendas int not null references encomendas (codEmcomendas)
);

alter table vendas rename column codEmcomendas to codEncomendas;
alter table vendas alter column codEncomendas drop not null;
-- alter table vendas set data type date not null using current_time
alter table vendas drop column dataHora;
alter table vendas add column dataHora timestamp;


create table produtoVendas(
  codProduto int not null references produtos (codProduto),
  codVenda int not null references vendas (codVenda),
  quantidade float not null
);
