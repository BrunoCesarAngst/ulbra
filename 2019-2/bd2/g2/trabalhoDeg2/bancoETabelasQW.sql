-- Criação do banco de dados QualityWorks
  create database qualityWorks;

-- Criação tabelas do banco de dados QualityWorks

-- parte de clientes e profissionais
    create table address_types(
      address_type_code serial primary key,
      address_type_description text not null
    );
  -- select * from address_types;

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
  -- select * from the_address;

    create table customers(
      client_code serial primary key,
      client_name text not null,
      client_email text not null,
      client_cpf text,
      client_cnpj text
    );
  -- select * from customers;

    create table professionals(
      professional_code serial primary key,
      professional_name text not null,
      professional_email text not null,
      professional_cpf text,
      professional_cnpj text
    );
  -- select * from professionals;

    create table clients_address(
      client_address_code serial primary key,
      client_address_code_fk int not null references the_address(address_code),
      client_code_fk int not null references customers(client_code)
    );
  -- select * from clients_address;

    create table professionals_address(
      professional_address_code serial primary key,
      address_code_fk int not null references the_address(address_code),
      professional_code_fk int not null references professionals(professional_code)
    );
  -- select * from professionals_address;

    create table phones(
      phone_code serial primary key,
      phone_number text not null,
      phone_provider text not null
    );
  -- select * from phones;

    create table customers_phones(
      client_phone_code serial primary key,
      phone_code_fk int not null references phones(phone_code),
      client_code_fk int not null references customers(client_code)
    );
  -- select * from customers_phones;

    create table professionals_phones(
      profissional_phone_code serial primary key,
      phone_code_fk int not null references phones(phone_code),
      professional_code_fk int not null references professionals(professional_code)
    );
  -- select * from professionals_phones;

-- parte dos serviços
    create table type_services(
      type_service_code serial primary key,
      type_service text not null,
      type_service_description text
    );
  -- select * from type_services;

    create table services(
      service_code serial primary key,
      service_description text not null,
      type_service_code_fk int not null references type_services(type_service_code) 
    );
  -- select * from services;

    create table professional_services(
      professional_service_code serial primary key,
      professional_code_fk int not null references professionals(professional_code),
      service_code_fk int not null references services(service_code)
    );
  -- select * from profissional_services;

    create table visits_schedule(
      visit_schedule_code serial primary key,
      visit_date timestamp not null,
      client_code_fk int not null references customers(client_code)
    );
  -- select * from visits_schedule;

    create table scheduled_services(
      scheduled_services_code serial primary key,
      service_code_fk int not null references services(service_code),
      visit_schedule_code_fk int not null references visits_schedule(visit_schedule_code)
    );
  -- select * from scheduled_services;

    create table professional_appointments(
      professional_scheduling_code serial primary key,
      visit_schedule_code_fk int not null references visits_schedule(visit_schedule_code),
      professional_code_fk int not null references professionals(professional_code)
    );
  -- select * from professional_appointments;

-- parte das avaliações
    create table type_score(
      type_score_code serial primary key,
      score_value int not null
    );
  -- select * from type_score;

    create table score(
      score_code serial primary key,
      score_comment text,
      type_score_code_fk int not null,
      professional_code_fk int not null references professionals(professional_code)
    );
  -- select * from score;
