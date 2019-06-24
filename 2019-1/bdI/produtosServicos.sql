create database proserltda


create table clientes(
    idcliente serial,
    endereco varchar(30) not null,
    telefone varchar(14) not null,
    email varchar(25) not null,
        constraint pk_idcliente
            primary key(idcliente)
);

create table pessoasfisicas(
    idpessoafisica serial,
    idcliente int,
    cpf varchar(14) not null,
    nome varchar(45) not null,
    constraint pk_idpessoafisica
        primary key (idpessoafisica),
	constraint fk_idcliente 
        foreign key(idcliente)
            references clientes(idcliente)
);

create table pessoasjuridicas(
    idpessoajuridica serial,
    idcliente int,
    cnpj varchar(20) not null,
    razaosocial varchar(45) not null,
    constraint pk_idpessoajuridica
        primary key(idpessoajuridica),
	constraint fk_idcliente 
        foreign key(idcliente)
            references clientes(idcliente)
);

create table departamentos(
    iddepartamento serial,
    nome varchar(15) not null,
    salario money,
    constraint pk_iddepartamento
        primary key(iddepartamento)
);

create table funcionarios(
    idfuncionario serial,
    iddepartamento int,
    nome varchar(45) not null,
    telefone varchar(14) not null,
    constraint pk_idfuncionario
        primary key(idfuncionario),
    constraint fk_iddepartamento
        foreign key(iddepartamento)
            references departamentos(iddepartamento)
);

create table fornecedores(
    idfornecedor serial,
    nome varchar(45) not null,
    cnpj varchar(20) not null,
    telefone varchar(14) not null,
    email varchar(45) not null,
    endereco varchar(100) not null,
    constraint pk_idfornecedor
        primary key(idfornecedor)
);

create table compras(
    idcompra serial,
    idfornecedor int,
    data date not null,
    constraint pk_idcompra
        primary key(idcompra),
    constraint fk_idfornecedor
        foreign key(idfornecedor)
            references fornecedores(idfornecedor)
);

create table comprasitens(
    idcompraiten serial,
    idcompra int,
    idfornecedor int,
    quantidade int not null,
    valorunitario money not null,
    constraint pk_idcompraiten
        primary key(idcompraiten),
    constraint fk_idcompra
        foreign key(idcompra)
            references compras(idcompra),
    constraint fk_idfornecedor
        foreign key(idfornecedor)
            references fornecedores(idfornecedor)
);

create table produtosservicos(
    idprodutoservico serial,
    nome varchar(25) not null,
    descricao varchar(100) not null,
    quantidade int not null,
    constraint pk_idprodutoservico
        primary key(idprodutoservico)
);

create table vendas(
    idvenda serial,
    idcliente int,
    datavenda date not null,
    constraint pk_idvendas
        primary key(idvenda),
    constraint fk_idcliente
        foreign key(idcliente)
            references clientes(idcliente)
);

create table vendasitens(
    idvendaitem serial,
    idvenda int,
    idprodutoservico int,
    ehservico boolean not null default false,
    idfuncionario int,
    quantidade int not null,
    valorunitario money not null,
    constraint pk_idvendaitem
        primary key(idvendaitem),
    constraint fk_idvenda
        foreign key(idvenda)
            references vendas(idvenda),
    constraint fk_idprodutoservico
        foreign key(idprodutoservico)
            references produtosservicos(idprodutoservico),
    constraint fk_idfuncionario
        foreign key(idfuncionario)
            references funcionarios(idfuncionario)
);
