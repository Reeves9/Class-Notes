//wap to input user information such as id and name and display the user information.
using System;

namespace Prgrams{
    public class User{
        int id;
        string name;
        User(int id , string name){
            this.id = id;
            this.name = name;
        }
        public void display(){
            Console.WriteLine($"ID: {id}   Name: {name}");
        }
        public static void Main(string[] args){
            Console.Write("Enter your ID:");
            int id = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter your Name:");
            string name = Console.ReadLine();
            User user = new User(id,name);
            user.display();
        }
    }
}