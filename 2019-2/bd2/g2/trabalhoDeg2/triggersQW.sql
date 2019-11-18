  create or replace function verificador_de_agenda()
  returns "trigger"
  as $verificador_de_agenda$
  declare
    professional_already_has_set_date date;
    new_appointment_date date; 
  begin
    professional_already_has_set_date = (select visit_date
      from 
        professional_appointments pa inner join professionals p
          on p.professional_code = pa.professional_code_fk
        inner join visits_schedule vs
          on vs.visit_schedule_code = pa.visit_schedule_code_fk);

    new_appointment_date = (select visit_date
      from 
        professional_appointments pa inner join professionals p
          on p.professional_code = pa.professional_code_fk
        inner join visits_schedule vs
          on vs.visit_schedule_code = pa.visit_schedule_code_fk
        inner join customers c
          on c.client_code = vs.client_code_fk
        inner join scheduled_services ss
          on vs.visit_schedule_code = ss.visit_schedule_code_fk
        where visit_schedule_code = new.visit_schedule_code_fk);

    if professional_already_has_set_date = new_appointment_date
      then
      raise notice 'Essa data está ocupada';
    end if;
    return new;
  end;  
  $verificador_de_agenda$ language plpgsql;

  create trigger verificador_de_agenda_insert
    before insert on visits_schedule
    for each row
    execute procedure verificador_de_agenda();

  create trigger verificador_de_agenda_update
    before update on visits_schedule
    for each row
    execute procedure verificador_de_agenda();
