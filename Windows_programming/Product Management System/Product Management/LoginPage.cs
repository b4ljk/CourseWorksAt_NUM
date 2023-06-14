using Database;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Product_Management
{
    public partial class LoginPage : Form
    {
        public LoginPage()
        {
            InitializeComponent();
        }

        private void loginButton_Click(object sender, EventArgs e)
        {
            string username = usernameInput.Text;
            string password = passwordInput.Text;

            DataAccess dataAccess = new DataAccess();
            bool loggedIn = dataAccess.Login(username, password);

            if (loggedIn)
            {
                Dashboard form1 = new Dashboard();
                form1.Show();
                this.Hide();
            }
            else
            {
                errorText.Text = "Wrong";
                usernameInput.Text = "";
                passwordInput.Text = "";
            }
        }
    }
}
