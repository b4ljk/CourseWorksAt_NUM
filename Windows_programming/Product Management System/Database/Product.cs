using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Database
{
    public class Product
    {
        public int ProductId { get; set; }
        public string ProductName { get; set; }
        public int Price { get; set; }
        public int CategoryId { get; set; }
        public string Code{ get; set; }

        public Product(int productId, string productName, int price, int categoryId, string code)
        {
            ProductId = productId;
            ProductName = productName;
            Price = price;
            CategoryId = categoryId;
            Code = code;
        }
    }
}
