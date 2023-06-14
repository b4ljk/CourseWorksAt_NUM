using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace MDI
{
    public partial class Editor : Form
    {
        Form1 _parent { get; set; }

        public Editor()
        {
            InitializeComponent();


        }
        public Editor(Form1 parent)
        {
            InitializeComponent();
            MdiParent = parent;
            _parent = parent;
            Dock = DockStyle.Fill;

        }

        public void setTextValue(string value)
        {
            MainRichTextEditor.Text = value;
        }

        public void showFontModal()
        {
            FontDialog fontDialog = new FontDialog();
            fontDialog.Font = MainRichTextEditor.Font;
            fontDialog.Color = MainRichTextEditor.ForeColor;

            if (fontDialog.ShowDialog() == DialogResult.OK)
            {
                MainRichTextEditor.Font = fontDialog.Font;
                MainRichTextEditor.ForeColor = fontDialog.Color;
            }
        }

        public string getTextValue()
        {
            return MainRichTextEditor.Text;
        }

        public void MainRichTextEditor_TextChanged(object sender, EventArgs e)
        {
            _parent.setUnsavedChanges(true);
        }

        public void DarkMenuItem_Click()
        {
            
            BackColor = Color.FromArgb(45, 45, 48);
            ForeColor = Color.White;
            
            MainRichTextEditor.BackColor = Color.FromArgb(69, 69, 74);
            MainRichTextEditor.ForeColor = Color.White;
            
        }

        public void LightMenuItem_Click()
        {
            
            BackColor = SystemColors.Control;
            ForeColor = SystemColors.ControlText;
           
            MainRichTextEditor.BackColor = SystemColors.Window;
            MainRichTextEditor.ForeColor = SystemColors.WindowText;
            
        }

        public void clearText()
        {
            MainRichTextEditor.Text = "";
        }

    }
}
