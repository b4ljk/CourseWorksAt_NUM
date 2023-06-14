using System;
using System.Collections.Generic;
using System.Windows.Forms;
using CalcLib;

namespace Calculator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        MainCalculator calculator = new MainCalculator();
        private List<MemoryItemUI> memory = new List<MemoryItemUI>();

        private void btn_nine_Click(object sender, EventArgs e)
        {
            ResultBox.Text += "9";
        }

        private void btn_one_Click(object sender, EventArgs e)
        {
            ResultBox.Text += "1";
        }

        private void btn_two_Click(object sender, EventArgs e)
        {
            ResultBox.Text += "2";
        }

        private void btn_three_Click(object sender, EventArgs e)
        {
            ResultBox.Text += "3";
        }

        private void btn_four_Click(object sender, EventArgs e)
        {
            ResultBox.Text += "4";
        }

        private void btn_five_Click(object sender, EventArgs e)
        {
            ResultBox.Text += "5";
        }

        private void btn_six_Click(object sender, EventArgs e)
        {
            ResultBox.Text += "6";
        }

        private void btn_seven_Click(object sender, EventArgs e)
        {
            ResultBox.Text += "7";
        }

        private void btn_eight_Click(object sender, EventArgs e)
        {
            ResultBox.Text += "8";
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            calculator.a = Convert.ToInt32(ResultBox.Text);
            calculator.command = "Add";
            ResultBox.Clear();
        }

        private void buttonSubtract_Click(object sender, EventArgs e)
        {
            calculator.a = Convert.ToInt32(ResultBox.Text);
            calculator.command = "Subtract";
            ResultBox.Clear();
        }

        private void buttonEquals_Click(object sender, EventArgs e)
        {
            calculator.b = Convert.ToInt32(ResultBox.Text);
            switch (calculator.command)
            {
                case "Add":
                    calculator.Add(calculator.a, calculator.b);
                    break;
                case "Subtract":
                    calculator.Subtract(calculator.a, calculator.b);
                    break;
            }
            ResultBox.Text = calculator.Result.ToString();
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            ResultBox.Clear();
        }

        private void btn_memory_save_Click(object sender, EventArgs e)
        {
            MemoryItem memoryItem = new MemoryItem();
            memoryItem.Result = Convert.ToInt32(ResultBox.Text);
            calculator.AddMemoryItem(memoryItem);
            MemoryItemUI temp = new MemoryItemUI();
            temp.Text = memoryItem.Result.ToString();
            temp.MinusButton.Click += MinusButton_Click;
            temp.PlusButton.Click += PlusButton_Click;
            temp.McButton.Click += btn_MC_Click;
            memory.Add(temp);
            memoryLayoutPanel.Controls.Add(temp);
        }

        private void PlusButton_Click(object sender, EventArgs e)
        {
            Button plusButton = (Button)sender;
            Control memoryControlItem = (Control)plusButton.Tag;
            MemoryItemUI memoryItemUI = (MemoryItemUI)memoryControlItem;
            int memoryIndex = memoryLayoutPanel.Controls.IndexOf(memoryItemUI);
            if (memoryIndex >= 0)
            {
                MemoryItem memoryItem = calculator._memory._memoryItems[memoryIndex];
                memoryItem.Add(Convert.ToInt32(ResultBox.Text), Convert.ToInt32(memoryItemUI.Text));
                memoryItemUI.Text = memoryItem.Result.ToString();
            }
        }

        private void MinusButton_Click(object sender, EventArgs e)
        {
            Button minusButton = (Button)sender;
            Control memoryControlItem = (Control)minusButton.Tag;
            MemoryItemUI memoryItemUI = (MemoryItemUI)memoryControlItem;
            int memoryIndex = memoryLayoutPanel.Controls.IndexOf(memoryItemUI);
            if (memoryIndex >= 0)
            {
                MemoryItem memoryItem = calculator._memory._memoryItems[memoryIndex];
                memoryItem.Subtract(Convert.ToInt32(ResultBox.Text), Convert.ToInt32(memoryItemUI.Text));
                memoryItemUI.Text = memoryItem.Result.ToString();
            }
        }

        private void btn_MC_Click(object sender, EventArgs e)
        {
            Button mcButton = (Button)sender;
            Control memoryControlItem = (Control)mcButton.Tag;
            MemoryItemUI memoryItemUI = (MemoryItemUI)memoryControlItem;

            int memoryIndex = memoryLayoutPanel.Controls.IndexOf(memoryItemUI);
            if (memoryIndex >= 0)
            {
                MemoryItem memoryItem = calculator._memory._memoryItems[memoryIndex];
                calculator.RemoveMemoryItem(memoryItem);
                memoryLayoutPanel.Controls.RemoveAt(memoryIndex);
                memory.RemoveAt(memoryIndex);
            }
        }

    }
}
