create database desafio_cervantes;

create table clientes(
id serial primary key,
nome varchar(100) not null,
idade int
);

create table log_ocorrencias
(
 id serial primary key,
 operacao character varying
);

alter table log_ocorrencias add column data_log timestamp default current_timestamp;


select * from log_ocorrencias lo

select * from clientes lo