using DesafioCervantes.ConexaoPostgres;
using DesafioCervantes.Dominio;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DesafioCervantes.Repositorio
{
   public class ClienteRepositorio
    {


        public static void Create(Cliente cliente)
        {
            StringBuilder sql = new StringBuilder();
            sql.Append("Insert into clientes (nome, idade) values ('");
            sql.Append(cliente.Nome + "'," + cliente.Idade + ")");
            PostgresConn.ExecutarComando(sql.ToString());

            //insere o log
            LogClienteRepositorio.Create("Inseriu o cliente " +  cliente.Nome);

        }

        public static  void Update (Cliente cliente)
        {
            StringBuilder sql = new StringBuilder();
            sql.Append("update clientes set nome = '" + cliente.Nome + "',");
            sql.Append("idade = " + cliente.Idade) ;
            sql.Append(" where id = " + cliente.Id);

            PostgresConn.ExecutarComando(sql.ToString());

            //insere o log
            LogClienteRepositorio.Create("Atualizou o cliente " + cliente.Nome);
        }

        public static void Delete(int Id)
        {
            StringBuilder sql = new StringBuilder();
            sql.Append("delete from clientes ");
            
            sql.Append(" where id = " + Id);

            PostgresConn.ExecutarComando(sql.ToString());

            //insere o log
            LogClienteRepositorio.Create("delete do id " + Id);

        }

        public static  DataTable GetAll()
        {
            StringBuilder sql = new StringBuilder();
            sql.Append("select * from clientes ");

            return PostgresConn.getDataTable(sql.ToString());

        }        
    
    }
}
