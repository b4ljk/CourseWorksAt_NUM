using System;
using System.Collections.Generic;
using System.Data.SQLite;
using System.Diagnostics;

namespace Database
{
    public class DataAccess
    {
        private string _connectionString;

        public DataAccess(string connectionString)
        {
            _connectionString = connectionString;
        }

        public DataAccess()
        {
            _connectionString = "Data Source=C:\\Users\\Fibo\\Downloads\\product_management.db;";
        }

        private void ExecuteQuery(Action<SQLiteCommand> action)
        {
            using (SQLiteConnection connection = new SQLiteConnection(_connectionString))
            {
                connection.Open();
                using (SQLiteCommand command = connection.CreateCommand())
                {
                    action.Invoke(command);
                }
            }
        }

        public bool Login(string username, string password)
        {
            Debug.WriteLine(_connectionString);
            bool result = false;

            ExecuteQuery(command =>
            {
                command.CommandText = "SELECT COUNT(*) FROM Users WHERE username = @Username AND password = @Password";
                command.Parameters.AddWithValue("@Username", username);
                command.Parameters.AddWithValue("@Password", password);
                int count = Convert.ToInt32(command.ExecuteScalar());
                result = count > 0;
            });

            return result;
        }

        public List<Product> GetAllProducts()
        {
            List<Product> products = new List<Product>();

            ExecuteQuery(command =>
            {
                command.CommandText = "SELECT * FROM Product";
                using (SQLiteDataReader reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        int productId = Convert.ToInt32(reader["id"]);
                        string productName = reader["name"].ToString();
                        int price = Convert.ToInt32(reader["price"]);
                        int categoryId = Convert.ToInt32(reader["category_id"]);
                        string code = reader["code"].ToString();    
                        Product product = new Product(productId, productName, price, categoryId, code);
                        products.Add(product);
                    }
                }
            });

            return products;
        }

        public List<Product> GetProductsByCategory(int categoryId)
        {
            List<Product> products = new List<Product>();

            ExecuteQuery(command =>
            {
                command.CommandText = "SELECT * FROM products WHERE category_id = @CategoryId";
                command.Parameters.AddWithValue("@CategoryId", categoryId);
                using (SQLiteDataReader reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        int productId = Convert.ToInt32(reader["id"]);
                        string productName = reader["name"].ToString();
                        int price = Convert.ToInt32(reader["price"]);
                        string code = reader["code"].ToString();
                        Product product = new Product(productId, productName, price, categoryId, code);
                        products.Add(product);
                    }
                }
            });

            return products;
        }

        public List<Category> GetAllCategories()
        {
            List<Category> categories = new List<Category>();

            ExecuteQuery(command =>
            {
                command.CommandText = "SELECT * FROM categories";
                using (SQLiteDataReader reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        int categoryId = Convert.ToInt32(reader["id"]);
                        string categoryName = reader["name"].ToString();
                        int parentCategoryId = Convert.ToInt32(reader["parent_id"]);

                        Category category = new Category(categoryId, categoryName, parentCategoryId);
                        categories.Add(category);
                    }
                }
            });

            return categories;
        }

        public Task<Category> GetCategoryById(int categoryId)
        {
            Category category = null;
            Func<Category> function = () =>
                        {
                            ExecuteQuery(command =>
                            {
                                command.CommandText = "SELECT * FROM categories WHERE id = @CategoryId";
                                command.Parameters.AddWithValue("@CategoryId", categoryId);
                                using (SQLiteDataReader reader = command.ExecuteReader())
                                {
                                    while (reader.Read())
                                    {
                                        int id = Convert.ToInt32(reader["id"]);
                                        string categoryName = reader["name"].ToString();
                                        int parentCategoryId = Convert.ToInt32(reader["parent_id"]);
                                        category = new Category(id, categoryName, parentCategoryId);
                                    }
                                }
                            });
                            return category;
                        };
            return Task.Run(function);
            
        }

        public void AddProduct(Product product)
        {
            ExecuteQuery(command =>
            {
                command.CommandText = "INSERT INTO products (id, name, price, category_id, code) VALUES (@Id, @Name, @Price, @CategoryId, @Code)";
                command.Parameters.AddWithValue("@Name", product.ProductName);
                command.Parameters.AddWithValue("@Price", product.Price);
                command.Parameters.AddWithValue("@CategoryId", product.CategoryId);
                command.Parameters.AddWithValue("@Code", product.Code);
                command.Parameters.AddWithValue("@Id", product.ProductId);
                command.ExecuteNonQuery();
            });
        }

        public void AddCategory(Category category)
        {
            ExecuteQuery(command =>
            {
                command.CommandText = "INSERT INTO categories (id, name, parent_id) VALUES (@Id, @Name, @ParentId)";
                command.Parameters.AddWithValue("@Name", category.CategoryName);
                command.Parameters.AddWithValue("@ParentId", category.ParentCategoryId);
                command.Parameters.AddWithValue("@Id", category.CategoryId);
                command.ExecuteNonQuery();
            });
        }

        public void DeleteProduct(int productId)
        {
            ExecuteQuery(command =>
            {
                command.CommandText = "DELETE FROM products WHERE id = @Id";
                command.Parameters.AddWithValue("@Id", productId);
                command.ExecuteNonQuery();
            });
        }

        public void DeleteCategory(int categoryId)
        {
            ExecuteQuery(command =>
            {
                command.CommandText = "DELETE FROM categories WHERE id = @Id";
                command.Parameters.AddWithValue("@Id", categoryId);
                command.ExecuteNonQuery();
            });
        }

        public void UpdateProduct(Product product)
        {
            ExecuteQuery(command =>
            {
                command.CommandText = "UPDATE products SET name = @Name, price = @Price, category_id = @CategoryId, code = @Code WHERE id = @Id";
                command.Parameters.AddWithValue("@Name", product.ProductName);
                command.Parameters.AddWithValue("@Price", product.Price);
                command.Parameters.AddWithValue("@CategoryId", product.CategoryId);
                command.Parameters.AddWithValue("@Code", product.Code);
                command.Parameters.AddWithValue("@Id", product.ProductId);
                command.ExecuteNonQuery();
            });
        }

        

        public void UpdateCategory(Category category)
        {
            ExecuteQuery(command =>
            {
                command.CommandText = "UPDATE categories SET name = @Name, parent_id = @ParentId WHERE id = @Id";
                command.Parameters.AddWithValue("@Name", category.CategoryName);
                command.Parameters.AddWithValue("@ParentId", category.ParentCategoryId);
                command.Parameters.AddWithValue("@Id", category.CategoryId);
                command.ExecuteNonQuery();
            });
        }


    }
}
