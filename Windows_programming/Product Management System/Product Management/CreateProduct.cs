using Database;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Product_Management
{
    public partial class CreateProduct : Form
    {
        DataAccess dataAccess;
        List<Category> categoriesList;
        Dashboard parent;
        Boolean isEdit = false;
        int productId;
        public CreateProduct(Dashboard parent)
        {
            InitializeComponent();
            dataAccess = new DataAccess();

            fillDropdownWitData();
            this.parent = parent;
        }

        public CreateProduct(Dashboard parent, Product initialValue)
        {
            InitializeComponent();
            dataAccess = new DataAccess();
            fillDropdownWitData();
            this.parent = parent;
            isEdit = true;
            fillFields(initialValue);
            productId = initialValue.ProductId;
        }

        public void fillFields(Product initialValue)
        {
            nameInput.Text = initialValue.ProductName;
            priceInput.Text = initialValue.Price.ToString();
            codeInput.Text = initialValue.Code;
            int categoryId = initialValue.CategoryId;
            Category category = categoriesList.Find(x => x.CategoryId == categoryId);
            if (category != null)
            {
                dropdown.Text = category.CategoryName;
            }

        }
        public void fillDropdownWitData()
        {
            categoriesList = dataAccess.GetAllCategories();
            foreach (Category category in categoriesList)
            {
                dropdown.Items.Add(category.CategoryName);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string productName = nameInput.Text;
            int price = int.Parse(priceInput.Text);
            string code = codeInput.Text;
            int categoryId = categoriesList[dropdown.SelectedIndex].CategoryId;
            Random random = new Random();
            if (isEdit)
            {
                dataAccess.UpdateProduct(new Product(productId, productName, price, categoryId, code));
                parent.loadProducts();
                this.Hide();
                return;
            }
            productId = random.Next(100000, 999999);

            dataAccess.AddProduct(new Product(productId, productName, price, categoryId, code));
            parent.loadProducts();
            this.Hide();
        }
    }
}
