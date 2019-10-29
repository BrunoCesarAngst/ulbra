-- Criando o Banco de dados escola.
create database escola;

-- Criando as tabelas.
  create table cidades(
    id_cidade serial primary key,
    nome_cidade varchar(25) not null,
    UF varchar(3) not null
  );
  create table cursos(
    id_curso serial primary key,
    nome_curso varchar(25) not null,
    valor_credito money not null
  );
  create table disciplinas(
    id_disciplina serial primary key,
    nome_disciplina varchar(25) not null
  );
  create table professores(
    id_professor serial primary key,
    nome_professor varchar(25) not null,
    email_professor varchar(25) not null,
    endereco_professor varchar(25) not null,
    cpf_professor varchar(15) not null,
    id_cidade_fk int not null references cidades(id_cidade)
  );
  create table turmas(
    id_turma serial primary key,
    sala_turma int not null,
    capacidade int not null,
    id_professor_fk int not null references professores(id_professor),
    id_curso_fk int not null references cursos(id_curso)
  );
  alter table turmas rename column capacidade to capacidade_turma;

  create table turmas_por_disciplinas(
    id_turmas_por_disciplinas serial primary key,
    id_turma_fk int not null references turmas(id_turma),
    id_disciplina_fk int not null references disciplinas(id_disciplina)
  );
  create table alunos(
    id_aluno serial primary key,
    nome_aluno varchar(25) not null,
    endereco_aluno varchar(25) not null,
    telefone_aluno varchar(13) not null,
    id_cidade_fk int not null references cidades(id_cidade)
  );
  alter table alunos alter column telefone_aluno type varchar(20);

  create table matriculas(
    id_matriculas serial primary key,
    id_aluno_fk int not null references alunos(id_aluno),
    id_turma_fk int not null references turmas(id_turma)
  );

-- Populando as tabelas.
  insert into matriculas (id_aluno_fk, id_turma_fk) values
    (1, 5),
    (2, 4),
    (3, 3),
    (4, 2),
    (5, 1);
  insert into alunos (nome_aluno, endereco_aluno, telefone_aluno, id_cidade_fk) values
    ('Rafael Cruz', 'rua Núpcias', '(51) 111 111 111', 1),
    ('Bruno Angst', 'rua Rolante', '(51) 222 222 222', 2),
    ('Ramon Apolinario', 'rua Linux Debian', '(51) 333 333 333', 3),
    ('Gustavo da Rosa', 'rua Visão', '(48) 444 444 444', 4),
    ('Fulano de Amanhã', 'rua Destino', '(48) 555 555 555', 5);
  alter table alunos alter column id_cidade_fk drop not null;

  insert into turmas_por_disciplinas (id_turma_fk, id_disciplina_fk) values
    (1, 1),
    (2, 2),
    (3, 3),
    (4, 4),
    (5, 5);
  insert into turmas (sala_turma, capacidade_turma, id_professor_fk, id_curso_fk) values
      (001, 25, 1, 1),
      (010, 24, 2, 2),
      (011, 23, 3, 3),
      (100, 22, 4, 4),
      (101, 21, 5, 5);
  insert into professores ( nome_professor, email_professor, endereco_professor, cpf_professor, id_cidade_fk) values
    ('Adriana da Silva', 'a@ulbra.br', 'rua do Portugol', '999.999.999-99', 1),
    ('Breno', 'b@ulbra.br', 'rua do Engenho', '888.888.888-88', 2),
    ('Marcos', 'm@ulbra.br', 'rua do Sopranos', '777.777.777-77', 3),
    ('Sininho', 's@ulbra.br', 'rua do Travesseiros', '666.666.666-66', 4),
    ('Lutero', 'l@ulbra.br', 'rua do Protesto', '555.555.555-55', 5);
  insert into disciplinas (nome_disciplina) values
    ('Banco de Dados'),
    ('Arquitetura Contemporânia'),
    ('Forma, espaço e ordem'),
    ('A fada dos dentes'),
    ('Não erre');
  insert into cursos (nome_curso, valor_credito) values
    ('ADS', 557.71),
    ('Arquitetura e Urbanismo', 701),
    ('Disign Gráfico', 548.48),
    ('Odontologia', 1189.68),
    ('Direito', 564.32);
    alter table cursos alter column valor_credito type numeric;

  insert into cidades (nome_cidade, UF) values
    ('Capão da Canoa', 'RS'),
    ('Arroio do Sal', 'RS'),
    ('Torres', 'RS'),
    ('Passo de Torres', 'SC'),
    ('Bella Torres', 'SC');

-- Listagens
  -- 3. Listar todas os nomes dos alunos juntamente com o nome da cidade onde moram, ordenado pelo nome do aluno.
    select nome_aluno, nome_cidade
      from alunos a inner join cidades c on c.id_cidade = a.id_cidade_fk
        order by nome_aluno;
  -- 4. Atualizar o valor do crédito do curso de nome “ADS” com o DESCONTO de 10%.
    update cursos set valor_credito = valor_credito - (valor_credito * 0.1)
      where nome_curso = 'ADS';

  -- 5. Listar os códigos das turmas com o nome da disciplina e a sala.
    select id_turma, nome_disciplina, sala_turma
    from turmas t inner join turmas_por_disciplinas td on t.id_turma = td.id_turma_fk inner join disciplinas d on d.id_disciplina = td.id_disciplina_fk;

  -- 6. Comando SQL para listar o código das disciplinas que não tem turmas cadastrada.
    -- Inserir mais duas disciplinas
    insert into disciplinas (nome_disciplina) values
      ('Estrutura de Dados'),
      ('Paradigmas de Programação');

    select id_disciplina, nome_disciplina
      from disciplinas
        where not exists
    (select *
      from turmas_por_disciplinas
        where id_disciplina = turmas_por_disciplinas.id_disciplina_fk);

  -- 7. Listar os códigos dos professores que são de Torres ou tem turmas no curso de código = 1
    select id_professor, nome_professor
      from professores p, cidades c
        where c.nome_cidade = 'Torres' and c.id_cidade = p.id_cidade_fk
    union
    select id_professor, nome_professor
      from professores p inner join turmas t on p.id_professor = t.id_professor_fk inner join cursos c on t.id_curso_fk = c.id_curso
      where c.id_curso = 1;
  -- 8. Listar os códigos dos professores que tem turma no curso 2 mas não são da cidade de 'Capão da Canoa'.
    select id_professor, nome_professor
      from professores p inner join turmas t on p.id_professor = t.id_professor_fk inner join cursos c on t.id_curso_fk = c.id_curso
        where not exists
      (select *
        from cidades c inner join professores p on c.id_cidade = p.id_cidade_fk
          where nome_cidade = 'Capão da Canoa');
  -- 9. Listar os nomes de todos os professores que dão aula no curso 'ADS'.
    select nome_professor
      from professores
        where id_professor
    in
    (select id_professor_fk
      from cursos c inner join turmas t on c.id_curso =  t.id_curso_fk inner join turmas_por_disciplinas td on t.id_turma = td.id_turma_fk inner join disciplinas d on d.id_disciplina = td.id_disciplina_fk
        where nome_curso = 'ADS');
  -- 10. Listar o código dos alunos que não tem matrícula
    -- Criando um aluno sem matricula-lo
    insert into alunos (nome_aluno, endereco_aluno, telefone_aluno, id_cidade_fk) values
    ('Aluno Sem Matrícula', 'rua Estudo', '(48) 666 666 666', 5);
    select id_aluno, nome_aluno
      from alunos
        where not exists
    (select * 
      from matriculas 
        where id_aluno = id_aluno_fk);
  -- 11. Listar o código da turma com o nome do professor e o nome do curso.
    select id_turma, nome_professor, nome_curso
      from turmas t inner join professores p on t.id_professor_fk = p.id_professor inner join cursos c on t.id_curso_fk = c.id_curso;
  -- 12. Listar os códigos das cidades que não tem alunos.
    -- criar duas cidades sem alunos
    insert into cidades (nome_cidade, UF) values
      ('Terra de Areia', 'RS'),
      ('Praia Grande', 'SC');
    select id_cidade, nome_cidade
      from cidades
        where not exists
    (select *
      from alunos
        where id_cidade = id_cidade_fk);
  -- 13. Listar os códigos das  cidades que tem professores ou os códigos das cidades que tem alunos.
    select id_cidade, nome_cidade
      from cidades c inner join professores p on c.id_cidade = p.id_cidade_fk
    union
    select id_cidade, nome_cidade
      from cidades c inner join alunos a on c.id_cidade = a.id_cidade_fk;
  -- 14. Listar os códigos das cidades que tem professores e tem alunos.
    select id_cidade, nome_cidade
      from cidades c inner join professores p on c.id_cidade = p.id_cidade_fk
    intersect
    select id_cidade, nome_cidade
      from cidades c inner join alunos a on c.id_cidade = a.id_cidade_fk;
  -- 15. Listar o nome do curso mais caro(maior valor de crédito)
    select nome_curso, valor_credito
      from cursos
        where valor_credito = (
          select max(valor_credito)
          from cursos
        );
  -- 16. Listar o nome dos cursos que tem valor do crédito abaixo da média.
    select nome_curso, valor_credito
      from cursos
        where valor_credito < (
          select avg(valor_credito)
          from cursos
        );
  -- 17. Listar o nome da disciplina com o número total de  turmas(contar as turmas)  que ela tem(use group by).
    select nome_disciplina, count(id_disciplina)
      from disciplinas d inner join turmas_por_disciplinas td on d.id_disciplina = td.id_disciplina_fk inner join turmas t on td.id_turma_fk = t.id_turma
      group by id_disciplina;
  -- 18. Listar o nome das disciplinas como número total de turmas (contar as turmas), para as disciplinas que tem mais de 2 turmas. (usa group by)
    -- Criando uma segunda turma para ADS
    insert into turmas (sala_turma, capacidade_turma, id_professor_fk, id_curso_fk) values
      (110, 26, 1, 1);
    insert into turmas_por_disciplinas (id_turma_fk, id_disciplina_fk) values
    (6, 1);
    select nome_disciplina, count(id_disciplina)
      from disciplinas d inner join turmas_por_disciplinas td on d.id_disciplina = td.id_disciplina_fk inner join turmas t on td.id_turma_fk = t.id_turma
      group by id_disciplina
      having count(id_disciplina) >= 2;    
