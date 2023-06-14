namespace Product_Management
{
    partial class CreateCategory
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
            nameInput = new TextBox();
            dropdown = new ComboBox();
            button1 = new Button();
            label1 = new Label();
            label3 = new Label();
            SuspendLayout();
            // 
            // nameInput
            // 
            nameInput.Location = new Point(34, 53);
            nameInput.Name = "nameInput";
            nameInput.Size = new Size(149, 23);
            nameInput.TabIndex = 0;
            // 
            // dropdown
            // 
            dropdown.FormattingEnabled = true;
            dropdown.Location = new Point(34, 121);
            dropdown.Name = "dropdown";
            dropdown.Size = new Size(149, 23);
            dropdown.TabIndex = 2;
            // 
            // button1
            // 
            button1.BackColor = Color.Teal;
            button1.ForeColor = SystemColors.ControlLightLight;
            button1.Location = new Point(34, 161);
            button1.Name = "button1";
            button1.Size = new Size(149, 42);
            button1.TabIndex = 3;
            button1.Text = "Save";
            button1.UseVisualStyleBackColor = false;
            button1.Click += createCategoryButton_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(34, 35);
            label1.Name = "label1";
            label1.Size = new Size(39, 15);
            label1.TabIndex = 4;
            label1.Text = "Name";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(34, 103);
            label3.Name = "label3";
            label3.Size = new Size(92, 15);
            label3.TabIndex = 6;
            label3.Text = "Parent Category";
            // 
            // CreateCategory
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(222, 259);
            Controls.Add(label3);
            Controls.Add(label1);
            Controls.Add(button1);
            Controls.Add(dropdown);
            Controls.Add(nameInput);
            Name = "CreateCategory";
            Text = "CreateDialog";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox nameInput;
        private ComboBox dropdown;
        private Button button1;
        private Label label1;
        private Label label3;
    }
}