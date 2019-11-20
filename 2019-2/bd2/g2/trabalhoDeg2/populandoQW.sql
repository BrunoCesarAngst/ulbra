
-- parte de clientes e profissionais
  insert into address_types(address_type_description) values
      ('Residencial'),
      ('Condominial'),
      ('Comercial');

  insert into the_address
    (in_state, city, zip, neighborhood, street, land_number, complement, address_type_code_fk)
      values
      ('RS', 'Torres'         , '1111111-111' , 'Passinho'   , 'Passo dois', 1234, 'Casa 02', 1),
      ('SC', 'Passo de Torres', '2222222-222' , 'Centro'     , 'Rua 1'     , 5678, ''       , 2),
      ('PR', 'Curitiba'       , '3333333-333' , 'Curitibanos', 'Avenida 1' , 9012, 'Loja 06', 3),
      ('RS', 'Torres'         , '4444444-444' , 'Lagoa'      , 'Beco 1'    , 3456, 'Casa 05', 1),
      ('RS', 'Arroio Do Sal'  , '5555555-666' , 'Centro'     , 'Rua 2'     , 7890, 'N/A'    , 2),
      ('PR', 'Curitiba'       , '7777777-7777', 'Centro'     , 'Avenida 2' , 9   , 'Loja 06', 3);

  insert into customers
    (client_name, client_email, client_cpf, client_cnpj) values
      ('Fulano'  , 'qwe@rty.com', '111.111.111-11', ''                  ),
      ('Ciclano' , 'uio@pas.br' , '222.222.222-22', ''                  ),
      ('Beltrano', 'dfg@hjk.com', ''              , '39.752.873/0006-92');

  insert into professionals
    (professional_name, professional_email, professional_cpf, professional_cnpj)
      values
        ('Tor'  , 'tor@ter.com'  , '001.010.100-00', ''                  ),
        ('Buz'  , 'buz@ter.com'  , '852.852.852-85', ''                  ),
        ('Foo'  , 'foo@ter.com'  , '111.111.111-11', ''                  ),
        ('Bar'  , 'bar@ser.br'   , ''              , '58.894.852/0015-87'),
        ('Lat'  , 'lat@ser.br'   , ''              , '12.394.879/0001-15'),
        ('Fubar', 'fubar@emp.com', ''              , '39.752.873/0006-92');

  insert into clients_address(client_address_code_fk, client_code_fk) values
    (1, 1),
    (2, 2),
    (3, 3);

  insert into professionals_address(address_code_fk, professional_code_fk)
    values
      (4, 1),
      (5, 2),
      (6, 3);

  insert into phones(phone_number, phone_provider) values
    ('(51) 111 111 111', 'Claro'),
    ('(48) 222 222 222', 'Vivo' ),
    ('(41) 333 333 333', 'Claro'),
    ('(51) 444 444 444', 'Claro'),
    ('(51) 555 555 555', 'Vivo' ),
    ('(51) 666 666 666', 'Claro'),
    ('(51) 777 777 777', 'Tim'  ),
    ('(41) 888 888 888', 'Claro'),
    ('(41) 999 999 999', 'Vivo' );

  insert into customers_phones(phone_code_fk, client_code_fk) values
    (1, 1),
    (2, 2),
    (3, 3);

  insert into professionals_phones(phone_code_fk, professional_code_fk) values
    (4, 1),
    (5, 1),
    (6, 2),
    (7, 2),
    (8, 3),
    (9, 3);

-- parte dos serviços
  insert into type_services(type_service, type_service_description) values
    ('Controle e processo industrial'      , 'Prestadores de serviços'),
    ('Educacional e social'                , 'Prestadores de serviços'),
    ('Gestão e negócios'                   , 'Prestadores de serviços'),
    ('Informação e comunicação'            , 'Prestadores de serviços'),
    ('Infraestrutura'                      , 'Prestadores de serviços'),
    ('Alimentício'                         , 'Prestadores de serviços'),
    ('Produção artística cultural e design', 'Prestadores de serviços'),
    ('Construção'                          , 'Prestadores de serviços'),
    ('Industrial'                          , 'Prestadores de serviços'),
    ('Recursos Naturais'                   , 'Prestadores de serviços'),
    ('Saúde e estética'                    , 'Prestadores de serviços'),
    ('Turismo, hotelaria e lazer'          , 'Prestadores de serviços');

  insert into services(service_description, type_service_code_fk) values
    ('Mecânico de automóveis'             , 1 ),
    ('Soldador'                           , 1 ),
    ('Tradutor e Interprete de Libras'    , 2 ),
    ('Orientador Comunitário'             , 2 ),
    ('Corretor Imobiliário'               , 3 ),
    ('Vendedor'                           , 3 ),
    ('Desenvolvedor de Sistemas'          , 4 ),
    ('Instalador de Redes de Computadores', 4 ),
    ('Desenhista de Construção Civil'     , 5 ),
    ('Técnico em Edificações'             , 5 ),
    ('Cervejeiro'                         , 6 ),
    ('Produtor de Alimentos'              , 6 ),
    ('Cenógrafo'                          , 7 ),
    ('Paisagista'                         , 7 ),
    ('Professor de Dança'                 , 8 ),
    ('Montador de Móveis'                 , 8 ),
    ('Coletor de Recicláveis'             , 9 ),
    ('Técnico Ambiental'                  , 9 ),
    ('Cuidador de Idosos'                 , 10),
    ('Enfermeiro'                         , 10),
    ('Cozinheiro'                         , 11),
    ('Guia de Turístico'                  , 11);

  insert into profissional_services(professional_code_fk, service_code_fk) values
    (1, 1),
    (2, 3),
    (3, 3),
    (4, 4),
    (4, 5),
    (4, 6),
    (5, 7),
    (5, 8),
    (5, 9),
    (5, 10),
    (6, 22),
    (6, 22);

  insert into visits_schedule(visit_date, client_code_fk) values
    ('2019-11-22 08:00:00', 1),
    ('2019-11-23 12:00:00', 2),
    ('2019-12-02 09:00:00', 3),
    ('2019-12-07 14:30:00', 1),
    ('2019-12-11 16:00:00', 2),
    ('2019-12-17 21:15:00', 3);

  insert into scheduled_services(service_code_fk, visit_schedule_code_fk) values 
    (7 , 1),
    (8 , 2),
    (1 , 3),
    (16, 4),
    (15, 5),
    (2 , 6);

  insert into professional_appointments
    (visit_schedule_code_fk, professional_code_fk ) values
      (1, 1),
      (2, 2),
      (3, 3),
      (4, 4),
      (5, 5),
      (6, 6);
      
-- parte das avaliações
  insert into type_score(score_value) values
    (1),
    (2),
    (3),
    (4),
    (5);

  insert into score(score_comment, type_score_code_fk, professional_code_fk) values
    ('excelente trabalho'                , 5, 1),
    ('Não chegou no horário marcado'     , 1, 2),
    ('Preço muito alto'                  , 2, 3),
    (''                                  , 4, 4),
    ('Serviço mau feito, quero reembolso', 1, 5),
    ('É profissional no que faz'         , 5, 6);
