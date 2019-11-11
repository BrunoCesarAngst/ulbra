using DesafioCervantes.Dominio;
using DesafioCervantes.Repositorio;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DesafioCervantes.Forms
{
    public partial class FrmCliente : Form
    {

        enum StatusOperacao
        {
            inserir,
            alterar

        }
        private StatusOperacao status;

        public FrmCliente()
        {
            InitializeComponent();
            
        }

        private void btnNovo_Click(object sender, EventArgs e)
        {
            LimparForms();

            txtNome.Focus();

            status = StatusOperacao.inserir;
           
        }

        private void btnListar_Click(object sender, EventArgs e)
        {
            dtgClientes.DataSource = ClienteRepositorio.GetAll();
        }

        private void dtgClientes_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            status = StatusOperacao.alterar;
            if (dtgClientes.SelectedRows.Count > 0) 
            {
                txtCodigo.Text = dtgClientes.SelectedRows[0].Cells[0].Value.ToString();
                txtNome.Text = dtgClientes.SelectedRows[0].Cells[1].Value.ToString();
                txtIdade.Text = dtgClientes.SelectedRows[0].Cells[2].Value.ToString();

            }
        }

        private void btnDeletar_Click(object sender, EventArgs e)
        {
            ClienteRepositorio.Delete(Convert.ToInt32(dtgClientes.SelectedRows[0].Cells[0].Value));
            btnListar.PerformClick();
            LimparForms();

            MessageBox.Show("Cliente deletado com sucesso.");
        }

        private void LimparForms()
        {
            txtCodigo.Text = "";
            txtNome.Text = "";
            txtIdade.Text = "";
            status = StatusOperacao.inserir;
        }


        private void btnSalvar_Click(object sender, EventArgs e)
        {
            if (txtNome.Text == "")
            {
                MessageBox.Show("O nome é obrigatório.", "Ops", MessageBoxButtons.OK);
                return;
            }

            if (txtIdade.Text == "")
            {
                MessageBox.Show("A idade é obrigatória.", "Ops", MessageBoxButtons.OK);
                return;
            }
            Cliente cliente = new Cliente {
                                            Id = txtCodigo.Text =="" ? 0 : Convert.ToInt32(txtCodigo.Text),
                                            Nome = txtNome.Text, 
                                            Idade = Convert.ToInt32(txtIdade.Text) 
                                          };


            switch (status)
            {
                case StatusOperacao.inserir:

                    ClienteRepositorio.Create(cliente);

                    break;
                case StatusOperacao.alterar:
                    ClienteRepositorio.Update(cliente);
                    break;
                default:
                    break;
            }
            btnListar.PerformClick();
            MessageBox.Show("Operação efetuada com Sucesso.");
        }

        private void FrmCliente_Shown(object sender, EventArgs e)
        {
            btnListar.PerformClick();
            status = StatusOperacao.inserir;


            

        }
    }
}
