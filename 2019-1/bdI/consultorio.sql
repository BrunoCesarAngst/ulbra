:
-- Criando banco de dados de um consultório médico.

create database consultorio;

create table cidades(
    codCid serial not null,
    nome varchar(20) not null,
    UF varchar(2) not null,
        constraint codigoCidadade
            primary key(codCid)
);
create table medicos(
    codMed serial,
    nome varchar(35) not null,
    endereco varchar(15) not null,
    telefone varchar(15) not null,
    CRM varchar(13) not null,
    CPF varchar(13) not null,
    codCid serial,
        constraint codigoMedico
            primary key(codMed),
        constraint cidadeMedico
            foreign key(codCid) references cidades(codCid)
);
create table pacientes(
    codPac serial,
    nome varchar(20) not null,
    endereco varchar(15) not null,
    telefone varchar(15) not null,
    codCid serail,
        constraint codigoPaciente
            primary key(codPac),
        constrait cidadePaciente
            foreign key(codCid) references cidades(codCid)

);
create table medicamento(
    codMedicamento serial,
    nome varchar(20) not null,
    composicao varchar(100) not null,
    preco money
);
