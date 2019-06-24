-- esquemas das tabelas

create table cidades (
	codcid serial, 
	nome varchar(50) not null, 
	uf varchar(2) not null,
		constraint pkcodcid
			primary key (codcid)
);
create table medicos (
	codmed serial,
	nome varchar(50) not null, 
	endereco varchar(50) not null, 
	telefone varchar(11) not null, 
	crm varchar(10) not null, 
	cpf varchar(11) not null, 
	codcid int not null,
		constraint pkmedico
			primary key (codmed),
		constraint fkcodcid
			foreign key (codcid)
				references cidades (codcid)
);
create table pacientes (
	codpac serial, 
	nome varchar(50) not null, 
	endereco varchar(50) not null, 
	telefone varchar(11) not null, 
	codcid int not null,
		constraint pkcodpac
			primary key (codpac),
		constraint fkcodcid
			foreign key (codcid)
				references cidades (codcid)
);
create table consultas (
	codconsulta serial,
	codmed int not null, 
	codpac int not null, 
	data date not null, 
	hora time not null,
		constraint fkcodconsulta
			primary key (codconsulta),
		constraint fkcodmed
			foreign key (codmed)
				references medicos (codmed),
		constraint fkcodpaciente
			foreign key (codpac)
				references pacientes (codpac)
);
create table medicamentos (
	codmedicamento serial, 
	nome varchar(50) not null, 
	composicao varchar(100) not null, 
	preco money not null,
		constraint pkcodmedicamento
			primary key (codmedicamento)
);
create table prescricoes (
	codconsulta int not null, 
	codmedicamento int not null, 
	posologia varchar(100),
		constraint pkccodconsultacodmedicamento
			primary key (codconsulta, codmedicamento),
		constraint fkcodconsulta
			foreign key (codconsulta)
				references consultas (codconsulta),
		constraint fkcodmedicamento
			foreign key (codmedicamento)
				references medicamentos (codmedicamento)
);
-- 3 registros em cada tabela.

insert into cidades values (default, 'Caxias do Sul', 'RS');
insert into cidades values (default, 'Passo de Torres', 'SC');
insert into cidades values (default, 'Arroio do Sal', 'RS');

insert into medicos values (default, 'Oscar', 'rua a', '11111111111', '111111', '11111111111', 1);
insert into medicos values (default, 'Marlon', 'rua b', '22222222222', '222222', '22222222222', 2);
insert into medicos values (default, 'Marcos', 'rua c', '33333333333', '333333', '33333333333', 3);

insert into pacientes values (default, 'Micaela', 'rua d', '44444444444', 1);
insert into pacientes values (default, 'Margarete', 'rua e', '55555555555', 2);
insert into pacientes values (default, 'Bruno', 'rua f', '66666666666', 3);

insert into consultas values (default, 1, 1, '2019-06-16', 08:32);
insert into consultas values (default, 2, 2, '2019-06-15', 16:50);
insert into consultas values (default, 3, 3, '2019-06-14', 09:07);

insert into medicamentos values (default, 'neocopan', 'elementos', 12.50);
insert into medicamentos values (default, 'ibupofreno', 'químicos', 12.80);
insert into medicamentos values (default, 'Oneprazol', 'elementos químicos', 25.00);

insert into prescricoes values (1, 1, 'quando dor');
insert into prescricoes values (2, 2, '2,5ml de 6/6hs');
insert into prescricoes values (3, 3, '2 comprimidos em jejum');

-- atualizar o preço do medicamento de código 1 em 20%.
update medicamentos where codmedicamento = 1 set preco = preco + (20*preco)/100;

-- excluir a cidade cujo código é 3.
delete from cidades where codcid = 3;

-- listar os nomes das cidades do estado RS.
select nome from cidades where rf = 'RS';

-- listar todos os nomes de medicamentos e preço.
select nome, preco from medicamentos;

-- listar o nome e telefone dos médicos da cidade de 'Arroio do Sal'
select medicos.nome, telefone from medicos join cidades on medicos.codcid = cidades.codcid where cidades.nome = 'Arroio do Sal';

-- listar todos os nomes dos medicamentos, juntamente com a posologia, prescritos na consulta de código 1.
select nome, posologia from prescricoes join medicamentos on prescricoes.codmedicamento = medicamentos.codmedicamento where codconsulta = 1; 

-- listar o nome e telefone de todos os pacientes que moram na cidade de nome 'Passo de Torres'.
select pacientes.nome, pacientes.telefone from pacientes join cidades on pacientes.codcid = cidades.codcid where cidades.nome = 'Passo de Torres';

-- listar os nomes dos pacientes que tem consulta marcada.
select nome from pacientes join consultas on consultas.codpac = pacientes.codpac;

--listar todos os nomes e telefones das consultas marcadas para o dia '2019-06-16'.
select nome, telefone from pacientes join consultas on consultas.codpac = pacientes.codpac where data = '2019-06-16';

-- mostrar a média de preços dos medicamentos.
select sum(preco)/count(*) from medicamentos;

-- mostrar o número total de consultas cadastradas.
select count(*) from consultas;

-- listar o nome do medicamento mais caro.
select nome from medicamentos where preco = (select max(preco) from medicamentos);

-- listar os nomes dos medicamentos que tem preço acima da média.
select nome from medicamentos where preco > (select sum(preco)/count(*) from medicamentos);

-- listar todas as consultas com nome do médico, nome do paciente, data e hora.
select medicos.nome, pacientes.nome, data, hora from consultas join medicos on consultas.codmed = medicos.codmed join pacientes on consultas.codpac = pacientes.codpac;
