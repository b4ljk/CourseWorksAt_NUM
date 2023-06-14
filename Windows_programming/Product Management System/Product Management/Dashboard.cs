using Database;
using System.Diagnostics;
using System.Windows.Forms;

namespace Product_Management
{
    enum CategoryMode
    {
        normal,
        edit,
        remove
    }
    public partial class Dashboard : Form
    {
        private DataAccess dataAccess;
        private CategoryMode categoryMode = CategoryMode.normal;
        private List<Product> products = new();

        List<Category> categories;

        public Dashboard()
        {
            InitializeComponent();
            dataAccess = new DataAccess();
            LoadCategories();
            productGridView.CellContentClick += DataGridView_CellContentClick;
        }

        public void LoadCategories()
        {
            categoryList.Nodes.Clear();
            categories = dataAccess.GetAllCategories();
            Debug.WriteLine(categories.Count);

            Dictionary<int, Category> categoryDictionary = new Dictionary<int, Category>();
            Debug.WriteLine(categoryDictionary.Count);

            foreach (Category category in categories)
            {
                if (category.ParentCategoryId == 0)
                {
                    AddNestedNode(categoryList.Nodes, category, categoryDictionary);
                }
            }
        }

        private void AddNestedNode(TreeNodeCollection nodes, Category category, Dictionary<int, Category> categoryDictionary)
        {
            TreeNode node = new TreeNode(category.CategoryName);
            node.Tag = category.CategoryId;
            nodes.Add(node);
            categoryDictionary.Add(category.CategoryId, category);

            foreach (Category childCategory in categories)
            {
                if (childCategory.ParentCategoryId == category.CategoryId)
                {
                    AddNestedNode(node.Nodes, childCategory, categoryDictionary);
                }
            }
        }


        private void categoryList_AfterSelect(object sender, TreeViewEventArgs e)
        {
            TreeNode selectedNode = categoryList.SelectedNode;
            int categoryId = (int)selectedNode.Tag;
            Category selectedCategory = categories.Find(x => x.CategoryId == categoryId);
            if (selectedNode != null)
            {
                switch (categoryMode)
                {
                    case CategoryMode.edit:
                        CreateCategory createCategory = new(this, selectedCategory)
                        {
                            Owner = this
                        };
                        createCategory.Show();
                        break;
                    case CategoryMode.remove:
                        dataAccess.DeleteCategory(categoryId);
                        LoadCategories();
                        break;
                    default:
                        products = dataAccess.GetProductsByCategory(categoryId);
                        productGridView.DataSource = products;
                        break;
                }


            }
        }

        private void createButton_Click(object sender, EventArgs e)
        {
            CreateProduct createProduct = new CreateProduct(this);
            createProduct.Owner = this;
            createProduct.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            CreateCategory createCategory = new(this)
            {
                Owner = this
            };
            createCategory.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (categoryMode == CategoryMode.remove)
            {
                categoryMode = CategoryMode.normal;
                removeButton.Text = "Remove";
                editButton.Enabled = true;
                editButton.Text = "Edit";

            }
            else
            {
                categoryMode = CategoryMode.remove;
                removeButton.Text = "Done";
                editButton.Enabled = false;
                editButton.Text = "Edit";
            }
        }

        private void editButton_Click(object sender, EventArgs e)
        {
            if (categoryMode == CategoryMode.edit)
            {
                categoryMode = CategoryMode.normal;
                editButton.Text = "Edit";
                removeButton.Enabled = true;
                removeButton.Text = "Remove";
            }
            else
            {
                categoryMode = CategoryMode.edit;
                editButton.Text = "Done";
                removeButton.Enabled = false;
                removeButton.Text = "Remove";
            }

        }

        private void DataGridView_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {

            var productId = (int)productGridView.Rows[e.RowIndex].Cells[3].Value;
            var name = (string)productGridView.Rows[e.RowIndex].Cells[0].Value;
            var price = (int)productGridView.Rows[e.RowIndex].Cells[1].Value;
            var code = (string)productGridView.Rows[e.RowIndex].Cells[2].Value;
            int categoryId = (int)categoryList.SelectedNode.Tag;
            Product tmp = new(productId, name, price, categoryId, code);

            dataAccess.UpdateProduct(tmp);

        }

        private void DataGridView_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.ColumnIndex == productGridView.Columns["Remove"].Index && e.RowIndex >= 0)
            {

                int productId = int.Parse(productGridView.Rows[e.RowIndex].Cells["id"].Value.ToString());

                dataAccess.DeleteProduct(productId);
                loadProducts();

            }
            if (e.ColumnIndex == productGridView.Columns["Edit"].Index && e.RowIndex >= 0)
            {

                int productId = int.Parse(productGridView.Rows[e.RowIndex].Cells["id"].Value.ToString());

                Product selectedProduct = products.Find(x => x.ProductId == productId);
                CreateProduct createProduct = new(this, selectedProduct)
                {
                    Owner = this
                };
                createProduct.Show();

            }
        }

        public void loadProducts()
        {
            int categoryId = (int)categoryList.SelectedNode.Tag;
            products = dataAccess.GetProductsByCategory(categoryId);
            productGridView.DataSource = products;
        }

    }
}
