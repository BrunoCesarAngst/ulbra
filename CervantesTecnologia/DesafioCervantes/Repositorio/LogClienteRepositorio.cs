using DesafioCervantes.ConexaoPostgres;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DesafioCervantes.Repositorio
{
    public class LogClienteRepositorio
    {

        public static void Create(string operacao)
        {
            StringBuilder sql = new StringBuilder();
            sql.Append("Insert into log_ocorrencias (operacao) values ('" +  operacao + "')");

            PostgresConn.ExecutarComando(sql.ToString());
        }

    }
}
