select professional_name as Profissional, score_value as Pontos, score_comment as FeedBack
  from professionals p inner join score s 
    on p.professional_code = s.professional_code_fk
  inner join type_score ts 
    on ts.type_score_code = s.type_score_code_fk
  order by score_value desc;
