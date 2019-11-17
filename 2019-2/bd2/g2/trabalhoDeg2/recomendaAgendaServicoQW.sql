-- Um sistema de indicação de serviço com agendamento e avaliação.

  -- um usuário pode se cadastrar como cliente do sistema, para receber a indicação de profissionais, com relação ao serviço que ele busca. Os profissionais, por sua vez, podem se cadastrar como prestadores de serviços, para fazer parte de uma lista que será recomendada ao cliente. A escolha do cliente poderá ser feita pelo status do profissional mediante ao seu ranking, que é a classificação que obteve dos serviços prestados aos seus clientes, que também passa a ser um feedback ao profissional. No sistema ficará um agendamento de visita ao cliente do profissional de sua escolha, após o profissional ter aceitado o pedido de visita.

-- me-recomenda-em
-- ## chave primária ** chave estrangeira

-- parte de clientes e profissionais

  -- tipos_endereço( ##cod_tipo_endereço, descrição_tipo_endereço);

  -- endereços
    -- ( ##cod_endereço, estado, cidade, CEP, bairro, logradouro, número, complemento, **cod_tipo_end): 
      -- **cod_tipo_end referência tipos_endereços(##cod_tipo_endereço);

  -- clientes( ##cod_cliente, client_code_fk, email, CPF, CNPJ):

  -- Profissionais( ##cod_profissional, nome, email, CPF, CNPJ):

  -- endereços_clientes( ##cod_endereço_cliente, **cod_end, **cod_cli):
    -- **cod_end referência endereços(##cod_endereço),
    -- **cod_cli referência clientes(##cod_cliente);

  -- endereços_profissionais( ##cod_endereço_cliente, **cod_end, **cod_pro):
    -- **cod_end referência endereços(##cod_endereço),
    -- **cod_pro referência profissionais(##cod_profissional);

  -- telefones( ##cod_telefone, número, prestadora);

  -- Telefones_clientes( ##cod_telefone_cliente, **cod_cli):
    -- **cod_cli referência clientes(##cod_cliente);

  -- Telefones_profissionais( ##cod_telefone_profissional, **cod_pro):
    -- **cod_pro referência profissionais(##cod_profissional);

-- parte dos serviços

  -- tipos_serviços( ##cod_tipo_serviço, descrição_tipo_serviço);

  -- serviços( ##cod_serviço, descrição_serviço, **cod_tipo_ser):
    -- **cod_tipo_ser referência tipos_serviços(##cod_cod_tipo_serviço);

  -- profissionais_serviços( ##cod_profissional_serviço, **cod_pro, **cod_ser):
    -- **cod_pro referência profissionais(##cod_profissional),
    -- **cod_ser referência serviços(##cod_serviços);  

  -- agendamentos( ##cod_agendamento, data, hora, **cod_cli):
    -- **cod_cli referência clientes(##cod_cliente);

  -- serviços_agendados( ##cod_serviços_agendados, **cod_ser, **cod_age):
    -- **cod_ser referência serviços(##cod_serviços),
    -- **cod_age referência agendamentos(##cod_agendamento);

  -- agendamentos_profissionais(##cod_agendamento_profissional, **cod_age, **cod_pro):
    -- **cod_age referência agendamentos(##cod_agendamento),
    -- **cod_pro referência profissionais(##cod_profissional);  

-- parte das avaliações

  -- tipos_avaliações( ##cod_tipo_avaliação, valor-avaliação);

  -- avaliações( ##cod_avaliação, comentário, **cod_tipo_ava, **cod_pro):
    -- **cod_tipo_ava referência tipos_avaliações(##cod_tipo_avaliação),
    -- **cod_pro referência profissionais(##cod_profissional);

-- Criação do banco de dados QualityWorks
  -- create database qualityWorks;

-- Criação tabelas do banco de dados QualityWorks

-- parte de clientes e profissionais
    create table address_types(
      address_type_code serial primary key,
      address_type_description text not null
    );
  select * from address_types;

    create table the_address(
      address_code serial primary key,
      in_state text not null,
      city text not null,
      zip text not null,
      neighborhood text not null,
      street text not null,
      land_number int not null,
      complement text,
      address_type_code_fk int not null references address_types(address_type_code)
    );
  select * from the_address;

    create table customers(
      client_code serial primary key,
      client_name text not null,
      client_email text not null,
      client_cpf text,
      client_cnpj text
    );
  select * from customers;

    create table professionals(
      professional_code serial primary key,
      professional_name text not null,
      professional_email text not null,
      professional_cpf text,
      professional_cnpj text
    );
  select * from professionals;

    create table clients_address(
      client_address_code serial primary key,
      client_address_code_fk int not null references the_address(address_code),
      client_code_fk int not null references customers(client_code)
    );
  select * from clients_address;

    create table professionals_address(
      professional_address_code serial primary key,
      address_code_fk int not null references the_address(address_code),
      professional_code_fk int not null references professionals(professional_code)
    );
  select * from professionals_address;

    create table phones(
      phone_code serial primary key,
      phone_number text not null,
      phone_provider text not null
    );
  select * from phones;

    create table customers_phones(
      client_phone_code serial primary key,
      phone_code_fk int not null references phones(phone_code),
      client_code_fk int not null references customers(client_code)
    );
  select * from customers_phones;

    create table professionals_phones(
      profissional_phone_code serial primary key,
      phone_code_fk int not null references phones(phone_code),
      professional_code_fk int not null references professionals(professional_code)
    );
  select * from professionals_phones;

-- parte dos serviços
    create table type_services(
      type_service_code serial primary key,
      type_service text not null,
      type_service_description text
    );
  select * from type_services;

    create table services(
      service_code serial primary key,
      service_description text not null,
      type_service_code_fk int not null references type_services(type_service_code) 
    );
  select * from services;

    create table profissional_services(
      professional_service_code serial primary key,
      professional_code_fk int not null references professionals(professional_code),
      service_code_fk int not null references services(service_code)
    );
  select * from profissional_services;

    create table visits_schedule(
      visit_schedule_code serial primary key,
      visit_date timestamp not null,
      client_code_fk int not null references customers(client_code)
    );
  select * from visits_schedule;

    create table scheduled_services(
      scheduled_services_code serial primary key,
      service_code_fk int not null references services(service_code),
      visit_schedule_code_fk int not null references visits_schedule(visit_schedule_code)
    );
  select * from scheduled_services;

    create table professional_appointments(
      professional_scheduling_code serial primary key,
      visit_schedule_code_fk int not null references visits_schedule(visit_schedule_code),
      professional_code_fk int not null references professionals(professional_code)
    );
  select * from professional_appointments;

-- parte das avaliações
    create table type_score(
      type_score_code serial primary key,
      score_value int not null
    );
  select * from type_score;

    create table score(
      score_code serial primary key,
      score_comment text,
      type_score_code_fk int not null,
      professional_code_fk int not null references professionals(professional_code)
    );
  select * from score;

-- parte da população

-- parte das funções

  create function fun_verifica_agendamentos() returns "trigger" as
  $fun_verifica_agendamentos$
    begin
      --  verificar se a data de início é maior que a data de fim 
      if new.data_inicio > new.data_fim then
        raise exception 'a data de início não pode ser maior que a data de fim';
      end if;
      --  verificar se há sobreposição com visits_schedule existentes 
      if exists
        (select 1
            from visits_schedule
            where client_code_fk = new.client_code_fk
              and ((data_inicio, data_fim) overlaps
                -- overlaps esse operador resulta em verdadeiro quando dois períodos de tempo se sobrepõem e falso quando não se sobrepõem.
                (new.data_inicio, new.data_fim))
        )
        then
          raise exception 'impossível agendar - existe outro compromisso';
      end if;
      return new;
    end;
  $fun_verifica_agendamentos$ language plpgsql;

  comment on function fun_verifica_agendamentos() is
      'verifica se o agendamento é possível';

  create trigger trg_agendamentos_ins
      before insert on visits_schedule
      for each row
      execute procedure fun_verifica_agendamentos();

  create trigger trg_agendamentos_upd
      before update on visits_schedule
      for each row
      execute procedure fun_verifica_agendamentos();

