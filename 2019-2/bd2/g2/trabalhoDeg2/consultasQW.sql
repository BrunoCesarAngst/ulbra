select professional_name as profissional, visit_date as "Data da visita", client_name as Cliente, service_description as "Descrição do serviço", phone_number as Telefone
  from 
    professional_appointments pa inner join professionals p
      on p.professional_code = pa.professional_code_fk
    inner join visits_schedule vs
      on vs.visit_schedule_code = pa.visit_schedule_code_fk
    inner join customers c
      on c.client_code = vs.client_code_fk
    inner join scheduled_services ss
      on vs.visit_schedule_code = ss.visit_schedule_code_fk
    inner join services s
      on s.service_code = ss.service_code_fk
    inner join customers_phones cp
      on c.client_code = cp.client_code_fk
    inner join phones ph
      on ph.phone_code = cp.phone_code_fk
  order by client_name;

select professional_name as Profissional, score_value as Pontos, score_comment as FeedBack
  from professionals p inner join score s 
    on p.professional_code = s.professional_code_fk
  inner join type_score ts 
    on ts.type_score_code = s.type_score_code_fk
  order by score_value desc;
