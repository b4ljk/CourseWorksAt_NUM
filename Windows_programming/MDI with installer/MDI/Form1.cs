using Microsoft.Win32;
using System.IO;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace MDI
{
    public partial class Form1 : Form
    {
        private string _currentFile;
        private MenuStrip menuStrip1;
        private bool _unsavedChanges = false;
        public Editor mainEditor;
        public FileManager fileManager;
        SplitContainer myContainer;

        public Form1()
        {
            InitializeComponent();
            placeComponents();
            initEditor();
            initFileManager();
        }

        public void initEditor()
        {
            mainEditor = new Editor(this);

            mainEditor.TopLevel = false;
            mainEditor.Visible = true;
            splitContainer1.Panel2.Controls.Add(mainEditor);

        }

        public void initFileManager()
        {
            fileManager = new FileManager(this);
            fileManager.TopLevel = false;
            fileManager.Visible = true;
            splitContainer1.Panel1.Controls.Add(fileManager);

        }

        private void placeComponents()
        {
            menuStrip1 = new MenuStrip();
            ToolStripMenuItem fileMenu = new ToolStripMenuItem("Файл");
            ToolStripMenuItem openMenuItem = new ToolStripMenuItem("Нээх");
            ToolStripMenuItem saveMenuItem = new ToolStripMenuItem("Хадгалах");
            ToolStripMenuItem settingsMenu = new ToolStripMenuItem("Тохиргоо");
            ToolStripMenuItem fontMenuItem = new ToolStripMenuItem("Үсгийн хэлбэр");
            ToolStripMenuItem themeMenuItem = new ToolStripMenuItem("Төрөл");

            openMenuItem.Click += OpenMenuItem_Click;
            saveMenuItem.Click += SaveMenuItem_Click;
            fontMenuItem.Click += FontMenuItem_Click;
            themeMenuItem.Click += ThemeMenuItem_Click;



            //themeMenuItem.DropDownItems.AddRange(new ToolStripItem[] { darkMenuItem, lightMenuItem });


            fileMenu.DropDownItems.AddRange(new ToolStripItem[] { openMenuItem, saveMenuItem });
            settingsMenu.DropDownItems.Add(fontMenuItem);
            menuStrip1.Items.AddRange(new ToolStripItem[] { fileMenu, settingsMenu, themeMenuItem });
            menuStrip1.Dock = DockStyle.Top;
            Controls.Add(menuStrip1);

            MainMenuStrip = menuStrip1;

            this.IsMdiContainer = true;
        }

        private void ThemeMenuItem_Click(object sender, EventArgs e)
        {
            ThemeModal themeModal = new ThemeModal(this);
            //themeModal.Show();
        }


        private void OpenMenuItem_Click(object sender, EventArgs e)
        {
            fileManager.showOpenFileModal();
        }

        private void SaveMenuItem_Click(object sender, EventArgs e)
        {
            fileManager.showSaveFileModal();
        }
        private void FontMenuItem_Click(object sender, EventArgs e)
        {
            mainEditor.showFontModal();
        }


        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (_unsavedChanges)
            {
                using (var dialog = new SaveChangesDialog())
                {
                    var result = dialog.ShowDialog();
                    if (result == DialogResult.Yes)
                    {
                        SaveMenuItem_Click(sender, e);
                    }
                    else if (result == DialogResult.Cancel)
                    {
                        return;
                    }
                }
            }

            _currentFile = null;
            mainEditor.clearText();
            _unsavedChanges = false;
            RegistryKey key = Registry.CurrentUser.CreateSubKey("Software\\MyAppName");
            if (key != null)
            {
                key.SetValue("Position", string.Format("{0},{1}", this.Location.X, this.Location.Y));
            }

        }

        public void darkMenuItem_Click(object sender, EventArgs e)
        {
            mainEditor.DarkMenuItem_Click();
        }

        public void LightMenuItem_Click(object sender, EventArgs e)
        {
            mainEditor.LightMenuItem_Click();

        }


        public void setCurrentFile(string filePath)
        {
            _currentFile = filePath;

        }

        public string getCurrentFile()
        {
            return _currentFile;
        }

        public void setEditorText(string text)
        {
            mainEditor.setTextValue(text);
        }

        public string getEditorText()
        {
            return mainEditor.getTextValue();
        }

        public void setUnsavedChanges(bool o)
        {
            _unsavedChanges = o;
        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            RegistryKey key = Registry.CurrentUser.OpenSubKey("Software\\MyAppName");
            if (key != null)
            {
                string positionString = key.GetValue("Position") as string;
                if (positionString != null)
                {
                    string[] parts = positionString.Split(',');
                    if (parts.Length == 2)
                    {
                        int x, y;
                        if (int.TryParse(parts[0], out x) && int.TryParse(parts[1], out y))
                        {
                            this.Location = new Point(x, y);
                            
                        }
                    }
                }
            }
        }
    }
}