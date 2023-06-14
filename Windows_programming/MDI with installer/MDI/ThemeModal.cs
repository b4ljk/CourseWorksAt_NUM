using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MDI
{
    public partial class ThemeModal : Form
    {
        Form1 _parent { get; set; }

        public ThemeModal(Form1 parent)
        {
            this.MdiParent = null;
            _parent = parent;
            InitializeComponent();

            Label label1 = new Label();
            this.Text = "Modal Dialog";
            this.StartPosition = FormStartPosition.CenterParent;
            label1.Text = "Select a theme:";
            label1.Location = new Point(10, 10);
            this.Controls.Add(label1);

            ComboBox comboBox1 = new ComboBox();
            comboBox1.Items.Add("Dark");
            comboBox1.Items.Add("Light");
            comboBox1.SelectedIndex = 0;
            comboBox1.Location = new Point(10, 30);
            this.Controls.Add(comboBox1);

            Button buttonOk = new Button();
            buttonOk.Text = "OK";
            buttonOk.DialogResult = DialogResult.OK;
            buttonOk.Location = new Point(10, 60);
            this.Controls.Add(buttonOk);

            Button buttonCancel = new Button();
            buttonCancel.Text = "Cancel";
            buttonCancel.DialogResult = DialogResult.Cancel;
            buttonCancel.Location = new Point(90, 60);
            this.Controls.Add(buttonCancel);

            DialogResult result = this.ShowDialog();

            if (result == DialogResult.OK)
            {
                string selectedTheme = comboBox1.SelectedItem.ToString();
                if (selectedTheme == "Dark")
                {
                    _parent.darkMenuItem_Click(this, EventArgs.Empty);
                }
                else
                {
                    _parent.LightMenuItem_Click(this, EventArgs.Empty);
                }
            }
        }
    }
}
