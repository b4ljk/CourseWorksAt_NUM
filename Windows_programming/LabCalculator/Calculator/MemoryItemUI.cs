public class MemoryItemUI : TableLayoutPanel
{
    private Label resultLabel;
    private Button mcButton;
    private Button plusButton;
    private Button minusButton;
   

    public MemoryItemUI()
    {
        this.BorderStyle = BorderStyle.FixedSingle;
        this.Height = 30;
        this.Dock = DockStyle.Top;
        this.ColumnCount = 3;
        this.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
        this.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 20F));
        this.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));

        resultLabel = new Label();
        resultLabel.AutoSize = true;
        resultLabel.Anchor = AnchorStyles.Left;
        this.Controls.Add(resultLabel, 0, 0);

        plusButton = new Button();
        plusButton.Text = "+";
        plusButton.Width = 20;
        plusButton.Anchor = AnchorStyles.Right;
        plusButton.Dock = DockStyle.Right;
        this.Controls.Add(plusButton, 1, 0);

        minusButton = new Button();
        minusButton.Text = "-";
        minusButton.Width = 20;
        minusButton.Anchor = AnchorStyles.Right;
        minusButton.Dock = DockStyle.Right;
        this.Controls.Add(minusButton, 2, 0);

        mcButton = new Button();
        mcButton.Text = "MC";
        mcButton.Width = 20;
        mcButton.Anchor = AnchorStyles.Right;
        mcButton.Dock = DockStyle.Right;
        this.Controls.Add(mcButton, 3, 0);

        this.Margin = new Padding(0, 5, 0, 5);
    }

    public string Text
    {
        get { return resultLabel.Text; }
        set { resultLabel.Text = value; }
    }

    public Button PlusButton
    {
        get { return plusButton; }
    }

    public Button MinusButton
    {
        get { return minusButton; }
    }
    public Button McButton
    {
        get { return mcButton; }
    }
}