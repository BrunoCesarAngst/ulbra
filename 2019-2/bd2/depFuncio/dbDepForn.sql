create database dep_func;

create table departamentos(
  cod_dep serial primary key,
  nome_dep varchar(20) not null
);

create table funcionarios(
  cod_func serial primary key,
  nome_func varchar(30) not null,
  cod_dep_fk int not null references departamentos (cod_dep)
);

insert into departamentos (nome_dep) values ('Recursos Humanos');
insert into departamentos (nome_dep) values ('Financeiro');
insert into departamentos (nome_dep) values ('Vendas');
insert into departamentos (nome_dep) values ('Compras');

insert into funcionarios (nome_func, cod_dep_fk) values ('João', 1);
insert into funcionarios (nome_func, cod_dep_fk) values ('Maria', 1);
insert into funcionarios (nome_func, cod_dep_fk) values ('Pedro', 1);
insert into funcionarios (nome_func, cod_dep_fk) values ('Carlos', 1);
insert into funcionarios (nome_func, cod_dep_fk) values ('Antônio', 2);
insert into funcionarios (nome_func, cod_dep_fk) values ('Ricardo', 2);
insert into funcionarios (nome_func, cod_dep_fk) values ('Bianca', 2);
insert into funcionarios (nome_func, cod_dep_fk) values ('Roberto', 2);
insert into funcionarios (nome_func, cod_dep_fk) values ('Sofia', 3);
insert into funcionarios (nome_func, cod_dep_fk) values ('Diogo', 3);
insert into funcionarios (nome_func, cod_dep_fk) values ('Júnior', 3);
insert into funcionarios (nome_func, cod_dep_fk) values ('Eduardo', 3);
insert into funcionarios (nome_func, cod_dep_fk) values ('Ramon', 4);
insert into funcionarios (nome_func, cod_dep_fk) values ('Rafael', 4);
insert into funcionarios (nome_func, cod_dep_fk) values ('Gustavo', 4);

select nome_func
from funcionarios inner join departamentos
  on cod_dep_fk = cod_dep
where nome_dep = 'Recursos Humanos';

select nome_func, nome_dep
from funcionarios inner join departamentos
  on cod_dep_fk = cod_dep;

select nome_dep, count(cod_func)
from departamentos inner join funcionarios
  on cod_dep = cod_dep_fk
group by nome_dep;

select nome_dep, count(cod_func)
from departamentos inner join funcionarios
  on cod_dep = cod_dep_fk
group by nome_dep
having count(cod_func) > 3;
