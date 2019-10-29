  create database trigger

  CREATE TABLE agendamentos (
    id          SERIAL PRIMARY KEY,
    nome        TEXT,
    evento      TEXT,
    data_inicio TIMESTAMP,
    data_fim    TIMESTAMP
  );

  CREATE FUNCTION fun_verifica_agendamentos() RETURNS "trigger" AS
  $fun_verifica_agendamentos$
    BEGIN
      --  Verificar se a data de início é maior que a data de fim 
      IF NEW.data_inicio > NEW.data_fim THEN
        RAISE EXCEPTION 'A data de início não pode ser maior que a data de fim';
      END IF;
      --  Verificar se há sobreposição com agendamentos existentes 
      IF EXISTS
        (SELECT 1
            FROM agendamentos
            WHERE nome = NEW.nome
              AND ((data_inicio, data_fim) OVERLAPS
                -- OVERLAPS Esse operador resulta em verdadeiro quando dois períodos de tempo se sobrepõem e falso quando não se sobrepõem.
                (NEW.data_inicio, NEW.data_fim))
        )
        THEN
          RAISE EXCEPTION 'impossível agendar - existe outro compromisso';
      END IF;
      RETURN NEW;
    END;
  $fun_verifica_agendamentos$ LANGUAGE plpgsql;

  COMMENT ON FUNCTION fun_verifica_agendamentos() IS
      'Verifica se o agendamento é possível';

  CREATE TRIGGER trg_agendamentos_ins
      BEFORE INSERT ON agendamentos
      FOR EACH ROW
      EXECUTE PROCEDURE fun_verifica_agendamentos();

  CREATE TRIGGER trg_agendamentos_upd
      BEFORE UPDATE ON agendamentos
      FOR EACH ROW
      EXECUTE PROCEDURE fun_verifica_agendamentos();

  INSERT INTO agendamentos 
    VALUES (DEFAULT,'Joana','Congresso','2005-08-23','2005-08-24');
  INSERT INTO agendamentos 
    VALUES (DEFAULT,'Joana','Viagem','2005-08-24','2005-08-26');
  INSERT INTO agendamentos 
    VALUES (DEFAULT,'Joana','Palestra','2005-08-23','2005-08-26');
  -- ERRO:  impossível agendar - existe outro compromisso

  INSERT INTO agendamentos 
    VALUES (DEFAULT,'Maria','Cabeleireiro','2005-08-23 14:00:00','2005-08-23 15:00:00');
  INSERT INTO agendamentos 
    VALUES (DEFAULT,'Maria','Manicure','2005-08-23 15:00:00','2005-08-23 16:00:00');
  INSERT INTO agendamentos 
    VALUES (DEFAULT,'Maria','Médico','2005-08-23 14:30:00','2005-08-23 15:00:00');
  -- ERRO:  impossível agendar - existe outro 
  
  INSERT INTO agendamentos 
    VALUES (DEFAULT,'Margarete','Médico','2005-08-23 16:30:00','2005-08-23 17:00:00');
  -- ERRO:  impossível agendar - existe outro compromisso

  INSERT INTO agendamentos 
    VALUES (DEFAULT,'Margarete','Médico','2005-08-23 17:30:00','2005-08-23 17:30:00');
  -- ERRO:  impossível agendar - existe outro compromisso

  INSERT INTO agendamentos 
    VALUES (DEFAULT,'Bruno','Médico','2005-08-23 16:30:00','2005-08-23 15:00:00');
  --  ERRO:  a data de início é maior que a data de fim

  UPDATE agendamentos 
    SET data_inicio='2005-08-24' WHERE id=2;
  -- ERRO:  impossível agendar - existe outro compromisso
  
  CREATE OR REPLACE VIEW teste
    AS
    SELECT * 
      FROM agendamentos;

  SELECT *
    FROM teste;
