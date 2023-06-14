using System.Diagnostics;
using System.Drawing.Drawing2D;
using myTimer = System.Windows.Forms.Timer;

namespace Timer
{
    public partial class Form1 : Form
    {
        public int seconds;
        public int remainingSeconds;
        public Form1()
        {
            InitializeComponent();
            seconds = 30;

            pictureBoxProgress.SizeMode = PictureBoxSizeMode.CenterImage;
            pictureBoxProgress.BackColor = Color.Transparent;

            Bitmap bitmap = new Bitmap(pictureBoxProgress.Width, pictureBoxProgress.Height);
            using (Graphics g = Graphics.FromImage(bitmap))
            {
                g.SmoothingMode = SmoothingMode.AntiAlias;

                g.Clear(Color.Transparent);
                g.DrawEllipse(Pens.Gray, 2, 2, pictureBoxProgress.Width - 4, pictureBoxProgress.Height - 4);

                int progress = 100;
                float angle = (360 / 100.0f) * progress;
                g.DrawArc(new Pen(Color.Green, 6), 2, 2, pictureBoxProgress.Width - 4, pictureBoxProgress.Height - 4, -90, angle);
            }

            pictureBoxProgress.Image = bitmap;
            remainingSeconds = seconds;
            int elapsedSeconds = 0;
            myTimer timer = new myTimer();
            timer.Interval = 1000;
            timer.Tick += (sender, args) =>
            {
                elapsedSeconds++;
                remainingSeconds--;

                if (remainingSeconds < 0)
                {
                    timer.Stop();
                    return;
                }

                Debug.WriteLine("Elapsed: " + elapsedSeconds);
                Debug.WriteLine("Remaining: " + remainingSeconds);
                labelCountdown.Text = remainingSeconds.ToString();

                int progress = (elapsedSeconds *100)/ seconds;
                Debug.WriteLine("Progress: " + progress);
                Bitmap bitmap = new Bitmap(pictureBoxProgress.Width, pictureBoxProgress.Height);
                using (Graphics g = Graphics.FromImage(bitmap))
                {
                    g.SmoothingMode = SmoothingMode.AntiAlias;
                    g.Clear(Color.Transparent);
                    g.DrawEllipse(Pens.Gray, 2, 2, pictureBoxProgress.Width - 4, pictureBoxProgress.Height - 4);
                    float angle = (360 / 100.0f) * progress;
                    g.DrawArc(new Pen(Color.Green, 6), 2, 2, pictureBoxProgress.Width - 4, pictureBoxProgress.Height - 4, -90, angle);
                }
                pictureBoxProgress.Image = bitmap;
            };
            timer.Start();


        }
    }
}