using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Database
{
    public class Category
    {
        public int CategoryId { get; set; }
        public string CategoryName { get; set; }
        public int ParentCategoryId { get; set; }

        public Category(int categoryId, string categoryName, int parentCategoryId)
        {
            CategoryId = categoryId;
            CategoryName = categoryName;
            ParentCategoryId = parentCategoryId;
        }
    }
}
