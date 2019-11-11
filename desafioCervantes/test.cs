using Gtk;
using System;
using System.Drawing;
using System.Windows.Forms;

 namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.Text = "Change Properties Through Coding";
            this.BackColor = Color.Brown;
            this.Size = new Size(350, 125);
            this.Location = new Point(300, 300);
            this.MaximizeBox = false;
        }
    }
}
