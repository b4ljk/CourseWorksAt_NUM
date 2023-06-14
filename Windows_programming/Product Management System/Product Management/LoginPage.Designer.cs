namespace Product_Management
{
    partial class LoginPage
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
            panel1 = new Panel();
            loginButton = new Button();
            passwordInput = new TextBox();
            label3 = new Label();
            usernameInput = new TextBox();
            label2 = new Label();
            label1 = new Label();
            errorText = new Label();
            panel1.SuspendLayout();
            SuspendLayout();
            // 
            // panel1
            // 
            panel1.BackColor = Color.FromArgb(224, 224, 224);
            panel1.Controls.Add(errorText);
            panel1.Controls.Add(loginButton);
            panel1.Controls.Add(passwordInput);
            panel1.Controls.Add(label3);
            panel1.Controls.Add(usernameInput);
            panel1.Controls.Add(label2);
            panel1.Controls.Add(label1);
            panel1.Location = new Point(173, 62);
            panel1.Name = "panel1";
            panel1.Size = new Size(424, 339);
            panel1.TabIndex = 1;
            // 
            // loginButton
            // 
            loginButton.BackColor = Color.Teal;
            loginButton.ForeColor = SystemColors.ControlLightLight;
            loginButton.Location = new Point(75, 252);
            loginButton.Name = "loginButton";
            loginButton.Size = new Size(271, 40);
            loginButton.TabIndex = 5;
            loginButton.Text = "Log In";
            loginButton.UseVisualStyleBackColor = false;
            loginButton.Click += loginButton_Click;
            // 
            // passwordInput
            // 
            passwordInput.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point);
            passwordInput.Location = new Point(75, 194);
            passwordInput.Name = "passwordInput";
            passwordInput.Size = new Size(271, 29);
            passwordInput.TabIndex = 4;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point);
            label3.Location = new Point(75, 166);
            label3.Name = "label3";
            label3.Size = new Size(76, 21);
            label3.TabIndex = 3;
            label3.Text = "Password";
            // 
            // usernameInput
            // 
            usernameInput.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point);
            usernameInput.Location = new Point(75, 117);
            usernameInput.Name = "usernameInput";
            usernameInput.Size = new Size(271, 29);
            usernameInput.TabIndex = 2;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point);
            label2.Location = new Point(75, 89);
            label2.Name = "label2";
            label2.Size = new Size(88, 21);
            label2.TabIndex = 1;
            label2.Text = "User Name";
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 18F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.Teal;
            label1.Location = new Point(166, 20);
            label1.Name = "label1";
            label1.Size = new Size(87, 32);
            label1.TabIndex = 0;
            label1.Text = "LOGIN";
            // 
            // errorText
            // 
            errorText.AutoSize = true;
            errorText.ForeColor = Color.Firebrick;
            errorText.Location = new Point(78, 299);
            errorText.Name = "errorText";
            errorText.Size = new Size(0, 15);
            errorText.TabIndex = 6;
            // 
            // LoginPage
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(panel1);
            Name = "LoginPage";
            Text = "LoginPage";
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private Panel panel1;
        private Button loginButton;
        private TextBox passwordInput;
        private Label label3;
        private TextBox usernameInput;
        private Label label2;
        private Label label1;
        private Label errorText;
    }
}