using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Reflection.Metadata;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CustomControl
{
    public partial class CustomControl1 : Control
    {
        private int _numSlices = 4;
        private int _selectedSlice = -1;
        
        public CustomControl1()
        {
            InitializeComponent();
            this.MouseDown += CustomControl1_MouseDown;
        }

        [Category("Appearance")]
        [Description("The number of slices in the circle.")]
        public int NumSlices
        {
            get { return _numSlices; }
            set
            {
                if (value > 0 && value != _numSlices)
                {
                    _numSlices = value;
                    Invalidate();
                }
            }
        }

        protected override void OnPaint(PaintEventArgs pe)
        {
            base.OnPaint(pe);
            DrawDividedCircle(pe.Graphics, _numSlices);
        }

        private void DrawDividedCircle(Graphics graphics, int slices)
        {
            int width = ClientSize.Width;
            int height = ClientSize.Height;
            int radius = Math.Min(width, height) / 2;

            Point center = new Point(width / 2, height / 2);

            double sliceAngle = 360.0 / slices;
            for (int i = 0; i < slices; i++)
            {
                double startAngle = i * sliceAngle;

                Brush sliceBrush = _selectedSlice == i ? Brushes.Red : Brushes.White;

                graphics.FillPie(sliceBrush, new Rectangle(center.X - radius, center.Y - radius, radius * 2, radius * 2), (float)startAngle, (float)sliceAngle);
                graphics.DrawPie(Pens.Black, new Rectangle(center.X - radius, center.Y - radius, radius * 2, radius * 2), (float)startAngle, (float)sliceAngle);
            }

            int innerRadius = radius / 3;
            Rectangle innerCircleRect = new Rectangle(center.X - innerRadius, center.Y - innerRadius, innerRadius * 2, innerRadius * 2);
            graphics.FillEllipse(Brushes.White, innerCircleRect);
            graphics.DrawEllipse(Pens.Black, innerCircleRect);
        }

        public static double CalculateAngle(double x1, double y1, double x2, double y2)
        {
            double dx = x2 - x1;
            double dy = y2 - y1;
            double angle = Math.Atan2(dy, dx) * 180 / Math.PI;
            
            if (angle < 0)
            {
                angle += 360;
            }
            
            return angle;
        }

        private bool IsInsideCircle(Point mouseLocation, Point circleCenter, int circleRadius)
        {
            int dx = mouseLocation.X - circleCenter.X;
            int dy = mouseLocation.Y - circleCenter.Y;
            int distanceSquared = dx * dx + dy * dy;
            int radiusSquared = circleRadius * circleRadius;
            return distanceSquared <= radiusSquared;
        }

        private void CustomControl1_MouseDown(object sender, MouseEventArgs e)
        {
            Point relativePoint = PointToClient(e.Location);

            int width = ClientSize.Width;
            int height = ClientSize.Height;
            int radius = Math.Min(width, height) / 2;
            Point center = new(width / 2, height / 2);
            int innerRadius = radius / 3;
            if (!IsInsideCircle(e.Location, center, radius))
            {
                return;
            }
            if (IsInsideCircle(e.Location, center, innerRadius))
            {
                return;
            }
            else
            {
                double clikedAngle = CalculateAngle(center.X, center.Y, relativePoint.X, relativePoint.Y);
                Debug.WriteLine(clikedAngle);
                double angle = 360.0 / _numSlices;

                int slice = (int)Math.Floor(clikedAngle / angle);
                Debug.WriteLine(slice);

                _selectedSlice = slice;
                Invalidate();
            }
        }

    }
}
