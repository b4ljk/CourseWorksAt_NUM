using System.Windows.Forms;

namespace CustomControl
{
    public partial class Form1 : Form
    {
        private int numberOfParts = 8;

        public void setNumberOfParts(int numberOfParts)
        {

        }
        public Form1()
        {
            InitializeComponent();
        }
        /*
        private void DrawCircle(int numberOfParts)
        {
            Bitmap bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            Graphics g = Graphics.FromImage(bmp);
            g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;

            Pen pen = new Pen(Color.Black, 2);
            Rectangle rect = new Rectangle(10, 10, bmp.Width - 20, bmp.Height - 20);
            g.DrawEllipse(pen, rect);

            for (int i = 0; i < numberOfParts; i++)
            {
                float angle = i * 360.0f / numberOfParts;
                float x1 = rect.X + rect.Width / 2 + (rect.Width / 2) * (float)Math.Cos(angle * Math.PI / 180.0f);
                float y1 = rect.Y + rect.Height / 2 + (rect.Height / 2) * (float)Math.Sin(angle * Math.PI / 180.0f);
                float x2 = rect.X + rect.Width / 2 + (rect.Width / 2) * (float)Math.Cos((angle + 360.0f / numberOfParts) * Math.PI / 180.0f);
                float y2 = rect.Y + rect.Height / 2 + (rect.Height / 2) * (float)Math.Sin((angle + 360.0f / numberOfParts) * Math.PI / 180.0f);

                g.DrawLine(pen, rect.X + rect.Width / 2, rect.Y + rect.Height / 2, x1, y1);
                g.DrawLine(pen, rect.X + rect.Width / 2, rect.Y + rect.Height / 2, x2, y2);
            }

            pictureBox1.Image = bmp;
        }


        public static double CalculateAngle(double x1, double y1, double x2, double y2)
        {
            double dx = x2 - x1;
            double dy = y2 - y1;
            double angle = Math.Atan2(dy, dx) * 180 / Math.PI;
            if (angle < 0)
                angle += 360;
            return angle;
        }


        public bool IsPointInsideCircle(float x, float y, float centerX, float centerY, float radius)
        {
            float dx = x - centerX;
            float dy = y - centerY;
            float distance = (float)Math.Sqrt(dx * dx + dy * dy);
            return distance <= radius;
        }
        /*
        private void pictureBox1_Click(object sender, MouseEventArgs e)
        {
            float centerX = pictureBox1.Width / 2f;
            float centerY = pictureBox1.Height / 2f;
            float radius = Math.Min(centerX, centerY) - 10f;

            if (!IsPointInsideCircle(e.X, e.Y, centerX, centerY, radius))
            {
                DrawCircle(numberOfParts);
                return;

            }

            double angle = CalculateAngle(centerX, centerY, e.X, e.Y);

            int index = (int)Math.Floor(angle / 360.0 * numberOfParts);

            Bitmap bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            Graphics g = Graphics.FromImage(bmp);
            g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;

            Pen pen = new Pen(Color.Black, 2);
            SolidBrush brush = new SolidBrush(Color.Red);

            Rectangle rect = new Rectangle(10, 10, bmp.Width - 20, bmp.Height - 20);
            g.DrawEllipse(pen, rect);

            for (int i = 0; i < numberOfParts; i++)
            {
                float sectionAngle = i * 360.0f / numberOfParts;
                if (i == index)
                    g.FillPie(brush, rect, sectionAngle, 360.0f / numberOfParts);
                g.DrawPie(pen, rect, sectionAngle, 360.0f / numberOfParts);
            }

            pictureBox1.Image = bmp;
        }
        
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            int val;
            if (int.TryParse(textBox1.Text, out val) && val > 0)
            {
                setNumberOfParts(val);
            }
        }
        */
        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}