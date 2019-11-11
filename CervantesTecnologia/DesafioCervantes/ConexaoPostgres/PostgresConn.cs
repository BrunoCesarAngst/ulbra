using Npgsql;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DesafioCervantes.ConexaoPostgres
{
    public class PostgresConn
    {

        private static string _nomeBanco = "desafio_cervantes";
        private static string _nomeServidor = "localhost";
        private static string _senha = "postgres";        
        private static NpgsqlConnection _conn;
        private static NpgsqlDataAdapter DA;

        private static DataTable DT = new DataTable();
        private static NpgsqlCommand CM = new NpgsqlCommand();

     

     
        public static string connString
        {
            get
            {
                return "Server=" + _nomeServidor + ";" +
                        "Port=5432;" +
                        "UserId=postgres;" +
                        "Password='" + _senha + "';" +
                        "Database=" + _nomeBanco;
            }
        }

        
        /// <summary>
        /// Constroi o objeto para conectar no psql
        /// </summary>
        /// <param name="pNomeServidor">Passar o nome do servidor</param>
        /// <param name="pNomeBanco">Passar o nome do banco</param>
        /// <param name="pSenha">Passar a senha do usuário</param>
        public PostgresConn(string pNomeServidor, string pNomeBanco, string pSenha)
        {
            _nomeServidor = pNomeServidor;
            _senha = pSenha;
            _nomeBanco = pNomeBanco;
        }

        public PostgresConn()
        { }

        /// <summary>
        /// Método para conectar com o BD Postgres SQL
        /// Passe os parametros corretos no construtor.
        /// </summary>
        public static void Conectar()
        {
            try
            {
                _conn = new NpgsqlConnection(connString);
                _conn.Open();
            }
            catch (NpgsqlException ex)
            {
                throw ex;
            }
        }

        /// <summary>
        /// Método para desconectar com o BD Postgres SQL
        /// </summary>
        public static void Desconectar()
        {
            _conn.Close();
        }

        public static DataTable getDataTable(string pSql)
        {
            Conectar();
            if (DT != null)
                DT = new DataTable();
            DA = new NpgsqlDataAdapter(pSql, _conn);
            DA.Fill(DT);
            Desconectar();
            return DT;
        }
               
        public static void ExecutarComando(string pSql)
        {

            Conectar();
            CM = new NpgsqlCommand(pSql, _conn);
            int i = CM.ExecuteNonQuery();
            if (i > 0)
                Desconectar();


        }

        
    }
}
