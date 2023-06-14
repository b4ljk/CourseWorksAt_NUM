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
    public partial class FileManager : Form
    {
        Form1 _parent { get; set; }

        public FileManager()
        {
            InitializeComponent();
            getFiles(@"C:\Users\Fibo\Desktop");
        }

        public FileManager(Form1 parent)
        {
            MdiParent = parent;
            _parent = parent;
            InitializeComponent();
            getFiles(@"C:\Users\Fibo\Desktop");
            Dock = DockStyle.Fill;


        }

        public void getFiles(string path)
        {
            string[] files = Directory.GetFiles(path, "*.bichig");
            foreach (string file in files)
            {
                listBox1.Items.Add(Path.GetFileName(file));
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex >= 0)
            {
                string path = @"C:\Users\Fibo\Desktop";
                string fileName = listBox1.SelectedItem.ToString();
                string filePath = Path.Combine(path, fileName);
                Console.Out.WriteLine(filePath);
                Console.Out.WriteLine(File.ReadAllText(filePath));
                Console.WriteLine("PAAAATH" + filePath);
                Console.WriteLine(File.ReadAllText(filePath));

                _parent.setEditorText(File.ReadAllText(filePath));
                _parent.setCurrentFile(filePath);

            }
        }

        public void showOpenFileModal()
        {
            if(_parent.mainEditor != null)
            {
                _parent.initEditor();
            }
            if (_parent.fileManager != null)
            {
                _parent.initFileManager();
            }
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Bichig files (*.bichig)|*.bichig|All files (*.*)|*.*";
            openFileDialog.FilterIndex = 1;
            openFileDialog.RestoreDirectory = true;

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    _parent.setCurrentFile(openFileDialog.FileName);
                    using (StreamReader reader = new StreamReader(_parent.getCurrentFile()))
                    {
                        _parent.setEditorText(reader.ReadToEnd());
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show($"Алдаа: {ex.Message}");
                }
            }
        }

        public void showSaveFileModal()
        {
            if (_parent.getCurrentFile() == null)
            {
                SaveFileDialog saveFileDialog = new SaveFileDialog();
                saveFileDialog.Filter = "Bichig files (*.bichig)|*.bichig|All files (*.*)|*.*";
                saveFileDialog.FilterIndex = 1;
                saveFileDialog.RestoreDirectory = true;
                //_unsavedChanges = false;
                _parent.setUnsavedChanges(false);

                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    _parent.setCurrentFile(saveFileDialog.FileName);
                }
                else
                {
                    return;
                }
            }

            try
            {
                using (StreamWriter writer = new StreamWriter(_parent.getCurrentFile()))
                {
                    writer.Write(_parent.getEditorText());
                    _parent.setUnsavedChanges(false);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Алдаа: {ex.Message}");
            }
        }

    }
}
