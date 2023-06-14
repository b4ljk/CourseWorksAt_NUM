
using System.Diagnostics;
using System.Net;
using System.Reflection;

namespace Drawing
{
    public partial class Form1 : Form
    {
        private Bitmap graphBitmap = new Bitmap(1200, 1400);

        // Option image paths
        private readonly string sinImagePath = "images/sin_image.png";
        private readonly string cosImagePath = "images/cos_image.png";
        private readonly string xSquaredImagePath = "images/x_squared_image.png";

        public Form1()
        {
            InitializeComponent();
            LoadExpressionImages();

            comboBox1.DrawMode = DrawMode.OwnerDrawFixed;
            comboBox1.DrawItem += comboBox1_DrawItem;
            comboBox1.DropDownStyle = ComboBoxStyle.DropDownList;
            comboBox1.SelectedIndex = 0;
            graphBitmap = new Bitmap(pictureBox1.Width, pictureBox1.Height);

            pictureBox1.Image = graphBitmap;
            Image expressionImage = (Image)comboBox1.SelectedItem;

            //initial value a = 1
            double a = 1;
            textBox1.Text = 1.ToString();
            
            Func<double, double> f = x => EvaluateExpression(expressionImage, a, x);
            DrawGraph(f);
        }

        private void comboBox1_SelectionChangeCommitted(object sender, EventArgs e)
        {
            Image expressionImage = (Image)comboBox1.SelectedItem;
            double a;

            //if the input is not a number, do nothing
            if (!double.TryParse(textBox1.Text, out a))
            {
                return;
            }
            Func<double, double> f = x => EvaluateExpression(expressionImage, a, x);
            pictureBox1.Refresh();

            DrawGraph(f);
        }

        private void LoadExpressionImages()
        {
            comboBox1.Items.Add(LoadImageFromPath(sinImagePath));
            comboBox1.Items.Add(LoadImageFromPath(cosImagePath));
            comboBox1.Items.Add(LoadImageFromPath(xSquaredImagePath));
        }

        private void comboBox1_DrawItem(object sender, DrawItemEventArgs e)
        {
            e.DrawBackground();

            if (e.Index >= 0)
            {
                Image expressionImage = (Image)comboBox1.Items[e.Index];
                Rectangle imageRect = new Rectangle(e.Bounds.Left, e.Bounds.Top, e.Bounds.Width, e.Bounds.Height);

                e.Graphics.DrawImage(expressionImage, imageRect);
            }
        }



        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            Image expressionImage = (Image)comboBox1.SelectedItem;
            double a;
            if (!double.TryParse(textBox1.Text, out a))
            {
                return;
            }
            Func<double, double> f = x => EvaluateExpression(expressionImage, a, x);
            pictureBox1.Refresh();

            DrawGraph(f);
        }
        /// <summary>
        /// Evaluates the expression based on the selected image
        /// </summary>
        /// <param name="expressionImage"></param>
        /// <param name="a"></param>
        /// <param name="x"></param>
        /// <returns></returns>
        /// <exception cref="ArgumentException"></exception>
        private double EvaluateExpression(Image expressionImage, double a, double x)
        {
            // Comparing paths to determine which expression is selected
            if (string.Equals(expressionImage.Tag.ToString(), sinImagePath))
            {
                return Math.Sin(a * x);
            }
            else if (string.Equals(expressionImage.Tag.ToString(), cosImagePath))
            {
                return Math.Cos(a * x);
            }
            else if (string.Equals(expressionImage.Tag.ToString(), xSquaredImagePath))
            {
                return a * x * x;
            }
            else
            {
                throw new ArgumentException("Invalid expression");
            }
        }


        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            comboBox1_SelectedIndexChanged(sender, e);
        }
        /// <summary>
        /// Draws the graph based on the function
        /// </summary>
        /// <param name="f"></param>
        private void DrawGraph(Func<double, double> f)
        {
            using (Graphics g = Graphics.FromImage(graphBitmap))
            {
                // Clear the graph before drawing new one
                g.Clear(Color.White);

                // Set up coordinate map variables
                int width = pictureBox1.Width;
                int height = pictureBox1.Height;
                int axisPadding = 40;
                int tickSize = 5;
                int gridSize = 20;
                Font font = new Font("Arial", 8);
                Pen axisPen = new Pen(Color.Black, 2);
                Pen gridPen = new Pen(Color.LightGray, 1);
                Brush axisBrush = new SolidBrush(Color.Black);
                Brush tickLabelBrush = new SolidBrush(Color.Black);

                // Draw the grid
                for (int x = -10; x <= 10; x++)
                {
                    int screenX = (int)(x * ((width - 2 * axisPadding) / 20.0) + width / 2);
                    g.DrawLine(gridPen, screenX, axisPadding, screenX, height - axisPadding);
                }
                for (int y = -5; y <= 5; y++)
                {
                    int screenY = (int)(-y * ((height - 2 * axisPadding) / 10.0) + height / 2);
                    g.DrawLine(gridPen, axisPadding, screenY, width - axisPadding, screenY);
                }

                // Draw x-axis
                g.DrawLine(axisPen, axisPadding, height / 2, width - axisPadding, height / 2);
                for (int i = -10; i <= 10; i++)
                {
                    int x = (int)(i * ((width - 2 * axisPadding) / 20.0) + width / 2);
                    g.DrawLine(axisPen, x, height / 2 - tickSize, x, height / 2 + tickSize);
                    g.DrawString(i.ToString(), font, tickLabelBrush, x - 6, height / 2 + tickSize);
                }

                // Draw y-axis
                g.DrawLine(axisPen, width / 2, axisPadding, width / 2, height - axisPadding);
                for (int i = -5; i <= 5; i++)
                {
                    int y = (int)(-i * ((height - 2 * axisPadding) / 10.0) + height / 2);
                    g.DrawLine(axisPen, width / 2 - tickSize, y, width / 2 + tickSize, y);
                    g.DrawString(i.ToString(), font, tickLabelBrush, width / 2 + tickSize, y - 6);
                }

                // Draw graph
                Pen graphPen = new Pen(Color.Blue, 2);
                Point prevPoint = new Point(-1, -1);
                for (double x = -10; x <= 10; x += 0.1)
                {
                    double y = f(x);
                    int screenX = (int)(x * ((width - 2 * axisPadding) / 20.0) + width / 2);
                    int screenY = (int)(-y * ((height - 2 * axisPadding) / 10.0) + height / 2);
                    if (prevPoint.X != -1 && prevPoint.Y != -1)
                    {
                        g.DrawLine(graphPen, prevPoint.X, prevPoint.Y, screenX, screenY);
                    }
                    prevPoint = new Point(screenX, screenY);
                }
            }
            pictureBox1.Refresh();
        }
        /// <summary>
        /// Loads the image from the path
        /// </summary>
        /// <param name="imagePath"></param>
        /// <returns></returns>
        private Image LoadImageFromPath(string imagePath)
        {
            string currentDirectory = "C:\\Users\\Fibo\\Desktop\\personal\\.net\\Drawing\\Drawing\\";
            string fullPath = Path.Combine(currentDirectory, imagePath);
            Image image = Image.FromFile(fullPath);
            // Set the Tag image path
            image.Tag = imagePath; 
            return image;
        }
    }
}