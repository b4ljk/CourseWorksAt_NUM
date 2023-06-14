using Database;
using System.CodeDom.Compiler;
using System.Diagnostics;

namespace Product_Management
{
    public partial class CreateCategory : Form
    {
        private Dashboard parent;
        private Category category;
        private List<Category> categoriesList = new List<Category>();
        private bool isEdit = false;
        private int categoryId;
        public CreateCategory(Dashboard parent)
        {
            InitializeComponent();
            fillDropdownWitData();
            this.parent = parent;
            isEdit = false;
        }

        public CreateCategory(Dashboard parent, Category initialValue)
        {

            InitializeComponent();
            fillDropdownWitData();
            this.parent = parent;
            category = initialValue;
            isEdit = true;
            fillFields();
            categoryId = initialValue.CategoryId;
        }


        public async void fillFields()
        {
            nameInput.Text = category.CategoryName;
            int parentCategoryId = category.ParentCategoryId;
            Category parentCategory = await Task.Run(() => categoriesList.Find(x => x.CategoryId == parentCategoryId));
            if (parentCategory != null)
            {
                dropdown.Text = parentCategory.CategoryName;
            }
        }

        public void fillDropdownWitData()
        {
            DataAccess dataAccess = new();
            categoriesList = dataAccess.GetAllCategories();
            foreach (Category category in categoriesList)
            {
                dropdown.Items.Add(category.CategoryName);
            }
        }

        public void createCategoryButton_Click(object sender, EventArgs e)
        {
            string categoryName = nameInput.Text;
            Random random = new Random();
            if (isEdit)
            {
                categoryId = category.CategoryId;
            }
            else
            {
                categoryId = random.Next(100000, 999999);
            }

            string parentCategoryName = dropdown.Text;
            DataAccess dataAccess = new();
            int parentCategoryId = 0;
            foreach (Category category in categoriesList)
            {
                if (category.CategoryName == parentCategoryName)
                {
                    parentCategoryId = category.CategoryId;
                }
            }
            Category tmp = new Category(categoryId, categoryName, parentCategoryId);
            if (isEdit)
            {
                dataAccess.UpdateCategory(tmp);
            }
            else
            {
                dataAccess.AddCategory(tmp);
            }
            parent.LoadCategories();
            Hide();
        }
    }
}
