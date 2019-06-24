create table departamentos(
	id serial not null,
	nome varchar(30) not null,
		constraint id_departamento_pk
			primary key (id)
);

create table funcionarios(
	id serial not null,
	nome varchar(100) not null,
	telefone varchar(11) not null,
	id_departamento int not null,
		constraint id_funcionario_pk
			primary key (id),
		constraint id_departamento_fk
			foreign key (id_departamento)
				references departamentos (id)
);

create table servicos(
	id serial not null,
	valor money not null,
	prazo_estimado int,
		constraint id_servico_pk
			primary key (id)
);

create table funcionarios_servicos(
	id serial not null,
	id_funcionario int not null,
	id_servico int not null, 
	data date not null,
	constraint id_funcionario_servico_pk
		primary key (id),
	constraint id_funcionario_fk
		foreign key (id_funcionario)
			references funcionarios (id),
	constraint id_servico_fk
		foreign key (id_servico)
			references servicos (id)
);

create table pessoas_juridicas(
	id serial not null,
	razao_social varchar(30) not null,
	cnpj varchar(18),
		constraint id_pessoa_juridica_pk
			primary key (id)
);

create table pessoas_fisicas(
	id serial not null,
	nome varchar(100) not null,
	cpf varchar(14) not null,
		constraint id_pessoa_fisica_pk
			primary key (id)	
);

create table clientes(
	id serial not null,
	id_pessoa_fisica int,
	id_pessoa_juridica int,
	endereco varchar(100) not null,
	telefone varchar(11) not null,
	email varchar(50) not null,
		constraint id_cliente_pk
			primary key (id),
		constraint id_pessoa_juridica_fk
			foreign key (id_pessoa_juridica)
				references pessoas_juridicas (id),
		constraint id_pessoa_fisica_fk
			foreign key (id_pessoa_fisica)
				references pessoas_fisicas (id)
);

create table vendas(
	id serial not null,
	id_cliente int not null,
	data date not null,
	valor_total money not null,
		constraint id_veda_pk
			primary key (id),
		constraint id_cliente_fk
			foreign key (id)
				references clientes (id)
);

create table servicos_vendidos(
	id serial not null,
	id_veda int not null,
	valor_servico money not null,
	descricao varchar(200),
		constraint id_servico_vendido_pk
			primary key (id),
		constraint id_veda_fk
			foreign key (id_veda)
				references vendas (id)
);

create table produtos(
	id serial not null,
	nome varchar(30) not null,
	marca varchar(30) not null,
	quantidade int not null,
	valor_unitario money not null,
	descricao varchar(500) not null,
		constraint id_produto_pk
			primary key (id) 
);

create table produtos_vendidos(
	id serial not null,
	id_venda int not null,
	valor_unitario money not null,
		constraint id_produto_vendido_pk
			primary key (id),
		constraint id_venda_fk
			foreign key (id_venda)
				references vendas (id)
);

create table fornecedores(
	id serial not null,
	matricula int not null,
	nome varchar(100) not null,
	empresa varchar(100) not null,
	email varchar(100) not null,
	marca varchar(50) not null,
	telefone varchar(11) not null,
		constraint id_fornecedor_pk
			primary key (id)
);

create table compras(
	id serial not null,
	id_fornecedor int not null,
	valor_total money not null,
	data date not null,
		constraint id_compra_pk
			primary key (id),
		constraint id_fornecedor_fk
			foreign key (id_fornecedor)
				references fornecedores (id)
);

create table produtos_comprados(
	id serial not null,
	id_compra int not null,
	valor_unitario money not null,
	marca varchar(30) not null,
		constraint id_produto_comprado_pk
			primary key (id),
		constraint id_compra_fk
			foreign key (id_compra)
				references compras (id)
);
