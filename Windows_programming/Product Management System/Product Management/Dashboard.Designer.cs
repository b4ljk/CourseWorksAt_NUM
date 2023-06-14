namespace Product_Management
{
    partial class Dashboard
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            panel1 = new Panel();
            editButton = new Button();
            removeButton = new Button();
            button1 = new Button();
            label1 = new Label();
            categoryList = new TreeView();
            label3 = new Label();
            productGridView = new DataGridView();
            productBindingSource = new BindingSource(components);
            createButton = new Button();
            id = new DataGridViewTextBoxColumn();
            name = new DataGridViewTextBoxColumn();
            price = new DataGridViewTextBoxColumn();
            code = new DataGridViewTextBoxColumn();
            Remove = new DataGridViewButtonColumn();
            Edit = new DataGridViewButtonColumn();
            panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)productGridView).BeginInit();
            ((System.ComponentModel.ISupportInitialize)productBindingSource).BeginInit();
            SuspendLayout();
            // 
            // panel1
            // 
            panel1.BackColor = Color.Teal;
            panel1.Controls.Add(editButton);
            panel1.Controls.Add(removeButton);
            panel1.Controls.Add(button1);
            panel1.Controls.Add(label1);
            panel1.Controls.Add(categoryList);
            panel1.Location = new Point(1, 0);
            panel1.Name = "panel1";
            panel1.Size = new Size(226, 450);
            panel1.TabIndex = 0;
            // 
            // editButton
            // 
            editButton.BackColor = Color.White;
            editButton.Location = new Point(116, 61);
            editButton.Name = "editButton";
            editButton.Size = new Size(82, 23);
            editButton.TabIndex = 4;
            editButton.Text = "Edit";
            editButton.UseVisualStyleBackColor = false;
            editButton.Click += editButton_Click;
            // 
            // removeButton
            // 
            removeButton.BackColor = Color.White;
            removeButton.Location = new Point(21, 61);
            removeButton.Name = "removeButton";
            removeButton.Size = new Size(89, 23);
            removeButton.TabIndex = 3;
            removeButton.Text = "Remove";
            removeButton.UseVisualStyleBackColor = false;
            removeButton.Click += button2_Click;
            // 
            // button1
            // 
            button1.BackColor = Color.White;
            button1.Location = new Point(165, 27);
            button1.Name = "button1";
            button1.Size = new Size(33, 23);
            button1.TabIndex = 2;
            button1.Text = "+";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI Semibold", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = SystemColors.Control;
            label1.Location = new Point(21, 26);
            label1.Name = "label1";
            label1.Size = new Size(89, 21);
            label1.TabIndex = 1;
            label1.Text = "Categories";
            // 
            // categoryList
            // 
            categoryList.BackColor = Color.Teal;
            categoryList.ForeColor = SystemColors.Window;
            categoryList.LineColor = Color.White;
            categoryList.Location = new Point(21, 90);
            categoryList.Name = "categoryList";
            categoryList.Size = new Size(184, 348);
            categoryList.TabIndex = 0;
            categoryList.AfterSelect += categoryList_AfterSelect;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI Semibold", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label3.ForeColor = Color.Teal;
            label3.Location = new Point(245, 26);
            label3.Name = "label3";
            label3.Size = new Size(75, 21);
            label3.TabIndex = 3;
            label3.Text = "Products";
            // 
            // productGridView
            // 
            productGridView.AutoGenerateColumns = false;
            productGridView.BackgroundColor = Color.White;
            productGridView.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            productGridView.Columns.AddRange(new DataGridViewColumn[] { id, name, price, code, Remove, Edit });
            productGridView.DataSource = productBindingSource;
            productGridView.Location = new Point(245, 61);
            productGridView.Name = "productGridView";
            productGridView.RowTemplate.Height = 25;
            productGridView.Size = new Size(543, 377);
            productGridView.TabIndex = 4;
            // 
            // productBindingSource
            // 
            productBindingSource.DataSource = typeof(Database.Product);
            // 
            // createButton
            // 
            createButton.BackColor = Color.Teal;
            createButton.ForeColor = SystemColors.ButtonFace;
            createButton.Location = new Point(698, 26);
            createButton.Name = "createButton";
            createButton.Size = new Size(90, 29);
            createButton.TabIndex = 5;
            createButton.Text = "Create +";
            createButton.UseVisualStyleBackColor = false;
            createButton.Click += createButton_Click;
            // 
            // id
            // 
            id.DataPropertyName = "ProductId";
            id.HeaderText = "ID";
            id.Name = "id";
            // 
            // name
            // 
            name.DataPropertyName = "ProductName";
            name.HeaderText = "Name";
            name.Name = "name";
            // 
            // price
            // 
            price.DataPropertyName = "Price";
            price.HeaderText = "Price";
            price.Name = "price";
            // 
            // code
            // 
            code.DataPropertyName = "Code";
            code.HeaderText = "Code";
            code.Name = "code";
            // 
            // Remove
            // 
            Remove.FillWeight = 50F;
            Remove.HeaderText = "x";
            Remove.Name = "Remove";
            Remove.Width = 50;
            // 
            // Edit
            // 
            Edit.FillWeight = 50F;
            Edit.HeaderText = "e";
            Edit.Name = "Edit";
            Edit.Width = 50;
            // 
            // Dashboard
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(createButton);
            Controls.Add(productGridView);
            Controls.Add(label3);
            Controls.Add(panel1);
            Name = "Dashboard";
            Text = "Form1";
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)productGridView).EndInit();
            ((System.ComponentModel.ISupportInitialize)productBindingSource).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Panel panel1;
        private TreeView categoryList;
        private Label label1;
        private Label label3;
        private DataGridView productGridView;
        private BindingSource productBindingSource;
        private Button createButton;
        private Button button1;
        private Button removeButton;
        private Button editButton;
        private DataGridViewTextBoxColumn id;
        private DataGridViewTextBoxColumn name;
        private DataGridViewTextBoxColumn price;
        private DataGridViewTextBoxColumn code;
        private DataGridViewButtonColumn Remove;
        private DataGridViewButtonColumn Edit;
    }
}