namespace Product_Management
{
    partial class CreateProduct
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
            label1 = new Label();
            nameInput = new TextBox();
            priceInput = new TextBox();
            codeInput = new TextBox();
            dropdown = new ComboBox();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            button1 = new Button();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(30, 27);
            label1.Name = "label1";
            label1.Size = new Size(39, 15);
            label1.TabIndex = 0;
            label1.Text = "Name";
            // 
            // nameInput
            // 
            nameInput.Location = new Point(30, 45);
            nameInput.Name = "nameInput";
            nameInput.Size = new Size(161, 23);
            nameInput.TabIndex = 1;
            // 
            // priceInput
            // 
            priceInput.Location = new Point(30, 109);
            priceInput.Name = "priceInput";
            priceInput.Size = new Size(161, 23);
            priceInput.TabIndex = 2;
            // 
            // codeInput
            // 
            codeInput.Location = new Point(30, 183);
            codeInput.Name = "codeInput";
            codeInput.Size = new Size(161, 23);
            codeInput.TabIndex = 3;
            // 
            // dropdown
            // 
            dropdown.FormattingEnabled = true;
            dropdown.Location = new Point(30, 255);
            dropdown.Name = "dropdown";
            dropdown.Size = new Size(161, 23);
            dropdown.TabIndex = 4;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(30, 91);
            label2.Name = "label2";
            label2.Size = new Size(33, 15);
            label2.TabIndex = 5;
            label2.Text = "Price";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(30, 165);
            label3.Name = "label3";
            label3.Size = new Size(35, 15);
            label3.TabIndex = 6;
            label3.Text = "Code";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(30, 237);
            label4.Name = "label4";
            label4.Size = new Size(55, 15);
            label4.TabIndex = 7;
            label4.Text = "Category";
            // 
            // button1
            // 
            button1.BackColor = Color.Teal;
            button1.ForeColor = SystemColors.ControlLightLight;
            button1.Location = new Point(30, 300);
            button1.Name = "button1";
            button1.Size = new Size(161, 33);
            button1.TabIndex = 8;
            button1.Text = "Save";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // CreateProduct
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(246, 385);
            Controls.Add(button1);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(dropdown);
            Controls.Add(codeInput);
            Controls.Add(priceInput);
            Controls.Add(nameInput);
            Controls.Add(label1);
            Name = "CreateProduct";
            Text = "CreateProduct";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private TextBox nameInput;
        private TextBox priceInput;
        private TextBox codeInput;
        private ComboBox dropdown;
        private Label label2;
        private Label label3;
        private Label label4;
        private Button button1;
    }
}