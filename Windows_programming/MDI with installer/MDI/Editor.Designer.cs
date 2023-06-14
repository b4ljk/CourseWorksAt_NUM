namespace MDI
{
    partial class Editor
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            MainRichTextEditor = new RichTextBox();
            SuspendLayout();
            // 
            // MainRichTextEditor
            // 
            MainRichTextEditor.Location = new Point(2, 2);
            MainRichTextEditor.Name = "MainRichTextEditor";
            MainRichTextEditor.Size = new Size(798, 446);
            MainRichTextEditor.TabIndex = 0;
            MainRichTextEditor.Text = "";
            MainRichTextEditor.TextChanged += MainRichTextEditor_TextChanged;
            // 
            // Editor
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(MainRichTextEditor);
            Name = "Editor";
            Text = "Editor";
            ResumeLayout(false);
        }

        #endregion

        private RichTextBox MainRichTextEditor;
    }
}