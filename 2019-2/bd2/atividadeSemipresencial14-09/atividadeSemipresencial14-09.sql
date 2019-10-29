-- atividadeSemipresencial14-09
-- Banco de dados de um consultório médico

-- criando o banco de dados
  create database consultorio;

-- criandoas tabelas

  create table cidades(
    id_cidade serial primary key,
    nome_cidade varchar(25) not null,
    UF_cidade varchar(3)
  );

  create table medicamentos(
    id_medicamento serial primary key,
    nome_medicamento varchar(25) not null,
    composicao_medicamento varchar(30),
    preco_medicamento numeric not null
  );
    alter table medicamentos alter column preco_medicamento type numeric(10,2);

  create table pacientes(
    id_paciente serial primary key,
    nome_paciente varchar(25) not null,
    endereco_paciente varchar(30),
    telefone_paciente varchar(16) not null,
    id_cidade_fk int not null references cidades (id_cidade) 
  );

  create table medicos(
    id_medico serial primary key,
    nome_medico varchar(25) not null,
    endereco_medico varchar(30),
    telefone_medico varchar(16) not null,
    crm_medico int not null,
    cpf_medico varchar(14),
    id_cidade_fk int not null references cidades (id_cidade) 
  );

  create table consultas(
    id_consulta serial primary key,
    data_consulta date not null,
    hora_consulta time(0) not null,
    id_medico_fk int not null references medicos (id_medico),
    id_paciente_fk int not null references pacientes (id_paciente)
  );

  create table prescricoes(
    id_prescricao serial primary key,
    id_consulta_fk int not null references consultas (id_consulta),
    id_medicamento_fk int not null references medicamentos (id_medicamento),
    posologia_prescricao varchar(150)
  );

-- populando as tabelas
  insert into cidades
    (nome_cidade, UF_cidade) values
      ('Capão da canoa', 'RS'),
      ('Torres', 'RS'),
      ('Passo de Torres', 'SC'),
      ('Bella Torres', 'SC');

  insert into medicamentos
    (nome_medicamento, composicao_medicamento, preco_medicamento) values
      ('neocopan', 'elementos', 12.50),
      ('ibupofreno', 'químicos', 12.80),
      ('Oneprazol', 'elementos químicos', 25.00);
      update medicamentos medc set preco_medicamento = 25.00
        where medc.id_medicamento = 3;
      update medicamentos medc set preco_medicamento = 12.50
        where medc.id_medicamento = 1;

  insert into pacientes 
    (nome_paciente, endereco_paciente, telefone_paciente, id_cidade_fk) values
      ('Fulano', 'rua A', '(51) 000 000 000', 1),
      ('Siclano', 'rua B', '(51) 123 321 123', 1),
      ('Beltrano', 'rua C', '(51) 111 222 333', 1),
      ('Foo', 'rua D', '(51) 999 999 999', 2),
      ('Bar', 'rua E', '(48) 001 001 001', 3);

  insert into medicos
    (nome_medico, endereco_medico, telefone_medico, crm_medico, cpf_medico, id_cidade_fk) values
      ('Enoque', 'Rua Eterna', '(51) 777 777 777', 777, '101.010.101-01', 2),
      ('Yeshua', 'Rua Salvador', '(51) 700 700 700', 333, '777.777.777-77', 2),
      ('Otimista', 'Rua Vitória', '(51) 555 555 555', 555, '878.654.324-32', 1),
      ('Coragem', 'Rua Desbravadores', '(48) 111 111 111', 123, '222.222.222-00', 3);

  insert into consultas
    (data_consulta, hora_consulta, id_medico_fk, id_paciente_fk) values
    ('2015-05-07','08:30', 1, 3),
    ('2015-05-07','10:30', 1, 1),
    ('2015-05-07','18:30', 2, 2),
    ('2015-05-07','18:30', 3, 5),
    ('2015-05-07','18:30', 3, 4);

  insert into prescricoes
    (id_consulta_fk, id_medicamento_fk, posologia_prescricao) values
      (1, 1, 'quando dor'),
      (2, 2, '2,5ml de 6/6hs'),
      (3, 3, '2 comprimidos em jejum');

-- consultas ao banco de dados consultorio
  -- 3. Atualizar o preço do medicamento de código 1 em 20%.
   update medicamentos medc
    set preco_medicamento = preco_medicamento + (preco_medicamento * 1.2)
      where medc.id_medicamento = 1;

  -- 4. Excluir a cidade cujo código é 4.
    delete
      from cidades cid
        where cid.id_cidade = 4;

  -- 5. Listar os nomes das cidades do estado RS.
    select nome_cidade
      from cidades cid
        where cid.UF_cidade = 'RS';

  -- 6. Listar todos os nomes de medicamentos e preço.
   select nome_medicamento, preco_medicamento
    from medicamentos
      order by nome_medicamento;

  -- 7. Listar o nome e telefone dos médicos da cidade de ‘Torres’.
    select nome_medico, telefone_medico
      from cidades cid inner join medicos med on cid.id_cidade = med.id_cidade_fk
        where cid.nome_cidade = 'Torres';

  -- 8. Listar todas os nomes dos medicamentos, juntamente com a posologia, prescritos na consulta de código 1.
    select nome_medicamento, posologia_prescricao
      from medicamentos medc inner join prescricoes pre on medc.id_medicamento = pre.id_medicamento_fk inner join consultas con on con.id_consulta = pre.id_consulta_fk
       where con.id_consulta = 1;

  -- 9. Listar o nome e telefone de todos os pacientes que moram na cidade de nome ‘Capão da Canoa’.
    select nome_paciente, telefone_paciente
      from pacientes pac inner join cidades cid on cid.id_cidade = pac.id_cidade_fk
       where cid.nome_cidade = 'Capão da canoa';

  -- 10. Listar os nomes dos pacientes que tem consulta marcada.
   select nome_paciente, data_consulta
    from pacientes pac inner join consultas con on pac.id_paciente = con.id_paciente_fk;

  -- 11.Listar todos os nomes e telefones das consultas marcadas para o dia ’07/05/2015’.
    select nome_paciente, telefone_paciente, hora_consulta
       from consultas con inner join pacientes pac on con.id_paciente_fk = pac.id_paciente
        where con.data_consulta = '07/05/2015'
        order by hora_consulta;

  -- 12. Mostrar a média de preços dos medicamentos.
    select avg(preco_medicamento)
      from medicamentos

  -- 13. Mostrar o número total de consultas cadastradas.
    select count(id_consulta)
      from consultas;

  -- 14. Listar o nome do medicamento mais caro.
    select nome_medicamento, preco_medicamento
      from medicamentos
        where preco_medicamento = (
          select max(preco_medicamento)
            from medicamentos
        );
  -- 15. Listar os nomes dos medicamentos que tem preço acima da média.
    select nome_medicamento, preco_medicamento
      from medicamentos
        where preco_medicamento > (
          select avg(preco_medicamento)
            from medicamentos
        );
  -- 16. Listar todas as consultas com nome do médico, nome do paciente, data e hora.
    select nome_medico, nome_paciente, data_consulta, hora_consulta
      from consultas con inner join medicos med on con.id_medico_fk = med.id_medico inner join pacientes pac on con.id_paciente_fk = pac.id_paciente;
