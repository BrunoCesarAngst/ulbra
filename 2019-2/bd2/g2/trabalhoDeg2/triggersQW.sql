-- calendar checker
  CREATE OR REPLACE FUNCTION calendar_checker() 
    RETURNS TRIGGER AS
    $BODY$
      BEGIN
        IF (NEW.visit_schedule_code_fk = ( SELECT visit_schedule_code_fk FROM  professional_appointments WHERE professional_code_fk = NEW.professional_code_fk AND NEW.visit_schedule_code_fk = visit_schedule_code_fk) ) THEN
          RAISE EXCEPTION 'Data já está selecionada para este profissional!';
        END IF;
        RETURN NEW;
      END;
    $BODY$ language plpgsql;

  create trigger calendar_checker_insert
    before insert on professional_appointments
    for each row
    execute procedure calendar_checker();

  create trigger calendar_checker_update
    before update on professional_appointments
    for each row
    execute procedure calendar_checker();

-- sum of score
  create or replace function sum_of_score()
    returns trigger as
    $body$
    declare
    @current_score int;
    @added_score int;
    @total_score int;
      begin
        @current_score = (
            select score_value
              from professionals, score, type_score
                where professional_code = professional_code_fk
                and type_score_code = type_score_code_fk
          )
        @added_score = (
            select score_value
              from professionals, score, type_score
                where professional_code = new.professional_code_fk
                and type_score_code = new.type_score_code_fk
          )

        @total_score = @current_score + @added_score;

        update
        return new;
      end;
    $body$ language plpgsql;

  create trigger sum_of_score_insert
    before insert on score
    for each row
    execute procedure sum_of_score();

  create trigger sum_of_score_update
    before update on score
    for each row
    execute procedure sum_of_score();

    update score
      set score_value = score + new.score_value
        where professional_code_fk = new.professional_code_fk 

select professional_name, score_value
  from professionals p inner join score s
   on p.professional_code = s.professional_code_fk
  inner join type_score t
    on t.type_score_code = s.type_score_code_fk
    where professional_code = 1;

