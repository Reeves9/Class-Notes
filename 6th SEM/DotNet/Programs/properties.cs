
using System;

namespace PropertyDemo
{
    class Student
    {
        // Private backing fields
        private string _name;
        private int _age;
        private double _grade;

        // Auto-implemented property - shorter syntax when no additional logic needed
        public int StudentId { get; set; }

        // Full property with validation
        public string Name
        {
            get { return _name; }
            set 
            { 
                if (string.IsNullOrEmpty(value))
                    throw new ArgumentException("Name cannot be empty");
                _name = value; 
            }
        }

        // Property with age validation
        public int Age
        {
            get { return _age; }
            set
            {
                if (value < 0 || value > 120)
                    throw new ArgumentException("Invalid age");
                _age = value;
            }
        }

        // Read-only property - can only be set within the class
        public double Grade
        {
            get { return _grade; }
            private set { _grade = value; }
        }

        // Method to update grade (since Grade is read-only from outside)
        public void UpdateGrade(double newGrade)
        {
            if (newGrade >= 0 && newGrade <= 100)
                Grade = newGrade;
            else
                throw new ArgumentException("Grade must be between 0 and 100");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Student student = new Student();
            
            // Using properties
            student.StudentId = 101;
            student.Name = "John Doe";
            student.Age = 20;
            student.UpdateGrade(95.5);

            // Displaying values
            Console.WriteLine($"Student ID: {student.StudentId}");
            Console.WriteLine($"Name: {student.Name}");
            Console.WriteLine($"Age: {student.Age}");
            Console.WriteLine($"Grade: {student.Grade}");
        }
    }
}
