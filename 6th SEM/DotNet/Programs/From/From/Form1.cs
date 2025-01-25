using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace From
{
    public partial class Form1 : Form
    {
        string connectionString = "Server=MATEBOOK\\SQLEXPRESS;Database=SE;Trusted_Connection=True;";
        public Form1()
        {
            InitializeComponent();
        }
        public void LoadData()
        {
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    string query = "SELECT users_id, users_name, users_address, users_phone_number FROM users";
                    SqlDataAdapter adapter = new SqlDataAdapter(query, connection);
                    DataTable dataTable = new DataTable();
                    adapter.Fill(dataTable);
                    dataGridView1.DataSource = dataTable; 
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: " + ex.Message);
                }
            }
        }

        public void AddUser(string name, string address, string phoneNumber)
        {
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    string query = "INSERT INTO users (users_name, users_address, users_phone_number) VALUES (@name, @address, @phone)";
                    SqlCommand command = new SqlCommand(query, connection);
                    command.Parameters.AddWithValue("@name", name);
                    command.Parameters.AddWithValue("@address", address);
                    command.Parameters.AddWithValue("@phone", phoneNumber);
                    command.ExecuteNonQuery();
                    MessageBox.Show("User added successfully!");
                    LoadData();
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: " + ex.Message);
                }
            }
        }

        public void UpdateUser(int userId, string name, string address, string phoneNumber)
        {
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    string query = "UPDATE users SET users_name = @name, users_address = @address, users_phone_number = @phone WHERE users_id = @id";
                    SqlCommand command = new SqlCommand(query, connection);
                    command.Parameters.AddWithValue("@id", userId);
                    command.Parameters.AddWithValue("@name", name);
                    command.Parameters.AddWithValue("@address", address);
                    command.Parameters.AddWithValue("@phone", phoneNumber);
                    command.ExecuteNonQuery();
                    MessageBox.Show("User updated successfully!");
                    LoadData();
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: " + ex.Message);
                }
            }
        }

        public void DeleteUser(int userId)
        {
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    string query = "DELETE FROM users WHERE users_id = @id";
                    SqlCommand command = new SqlCommand(query, connection);
                    command.Parameters.AddWithValue("@id", userId);
                    command.ExecuteNonQuery();
                    MessageBox.Show("User deleted successfully!");
                    LoadData();
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: " + ex.Message);
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string name = USRName.Text;
            string address = USRAddress.Text;
            string phone = USRPhone.Text;
            AddUser(name, address, phone);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            int id = Convert.ToInt32(USRID.Text);
            string name = USRName.Text;
            string address = USRAddress.Text;
            string phone = USRPhone.Text;
            UpdateUser(id, name, address, phone);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int id = Convert.ToInt32(USRID.Text);
            DeleteUser(id);
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void richTextBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void richTextBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            LoadData();
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            USRID.Text = dataGridView1.Rows[e.RowIndex].Cells[0].Value.ToString();
            USRName.Text = dataGridView1.Rows[e.RowIndex].Cells[1].Value.ToString();
            USRAddress.Text = dataGridView1.Rows[e.RowIndex].Cells[2].Value.ToString();
            USRPhone.Text = dataGridView1.Rows[e.RowIndex].Cells[3].Value.ToString();
        }
    }
}
