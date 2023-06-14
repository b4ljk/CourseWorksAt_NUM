namespace Timer
{
    partial class Form1
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
            labelCountdown = new Label();
            pictureBoxProgress = new PictureBox();
            ((System.ComponentModel.ISupportInitialize)pictureBoxProgress).BeginInit();
            SuspendLayout();
            // 
            // labelCountdown
            // 
            labelCountdown.AutoSize = true;
            labelCountdown.Font = new Font("Segoe UI", 40F, FontStyle.Regular, GraphicsUnit.Point);
            labelCountdown.Location = new Point(336, 191);
            labelCountdown.Name = "labelCountdown";
            labelCountdown.Size = new Size(59, 72);
            labelCountdown.TabIndex = 0;
            labelCountdown.Text = "0";
            // 
            // pictureBoxProgress
            // 
            pictureBoxProgress.Location = new Point(219, 82);
            pictureBoxProgress.Name = "pictureBoxProgress";
            pictureBoxProgress.Size = new Size(300, 297);
            pictureBoxProgress.TabIndex = 1;
            pictureBoxProgress.TabStop = false;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(labelCountdown);
            Controls.Add(pictureBoxProgress);
            Name = "Form1";
            Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)pictureBoxProgress).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label labelCountdown;
        private PictureBox pictureBoxProgress;
    }
}