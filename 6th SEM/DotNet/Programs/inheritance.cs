using System;

namespace InheritanceDemo {
    /// <summary>
    /// Base class demonstrating single inheritance
    /// Contains basic animal properties and behaviors
    /// </summary>
    class Animal {
        protected string name;
        public Animal(string name) {
            this.name = name;
        }
        public virtual void MakeSound() {
            Console.WriteLine("Animal makes sound");
        }
    }

    /// <summary>
    /// Example of Single Inheritance
    /// Dog inherits all properties and methods from Animal
    /// </summary>
    class Dog : Animal {
        public Dog(string name) : base(name) { }
        public override void MakeSound() {
            Console.WriteLine($"{name} says: Woof!");
        }
    }

    /// <summary>
    /// Base class for Hierarchical Inheritance example
    /// Parent class for both Car and Bike
    /// </summary>
    class Vehicle {
        protected string model;
        public Vehicle(string model) {
            this.model = model;
        }
        public virtual void Start() {
            Console.WriteLine("Vehicle starting");
        }
    }

    /// <summary>
    /// First child class in Hierarchical Inheritance
    /// Inherits from Vehicle base class
    /// </summary>
    class Car : Vehicle {
        public Car(string model) : base(model) { }
        public override void Start() {
            Console.WriteLine($"{model} car engine starting");
        }
    }

    /// <summary>
    /// Second child class in Hierarchical Inheritance
    /// Also inherits from Vehicle base class
    /// </summary>
    class Bike : Vehicle {
        public Bike(string model) : base(model) { }
        public override void Start() {
            Console.WriteLine($"{model} bike kickstarting");
        }
    }

    /// <summary>
    /// Base class for Multilevel Inheritance chain
    /// First level in Shape -> Rectangle -> ColoredRectangle hierarchy
    /// </summary>
    class Shape {
        protected string shapeName;
        public Shape(string name) {
            shapeName = name;
        }
    }

    /// <summary>
    /// Second level in Multilevel Inheritance
    /// Inherits from Shape and adds dimension properties
    /// </summary>
    class Rectangle : Shape {
        protected int length, width;
        public Rectangle(string name, int length, int width) : base(name) {
            this.length = length;
            this.width = width;
        }
    }

    /// <summary>
    /// Third level in Multilevel Inheritance
    /// Inherits from Rectangle and adds color property
    /// </summary>
    class ColoredRectangle : Rectangle {
        private string color;
        public ColoredRectangle(string name, int length, int width, string color) : base(name, length, width) {
            this.color = color;
        }
        public void DisplayInfo() {
            Console.WriteLine($"{color} {shapeName}: {length}x{width}");
        }
    }

    /// <summary>
    /// Interface for swimming capability
    /// Part of multiple inheritance example
    /// </summary>
    interface ISwimmable {
        void Swim();
    }

    /// <summary>
    /// Interface for flying capability
    /// Part of multiple inheritance example
    /// </summary>
    interface IFlyable {
        void Fly();
    }

    /// <summary>
    /// Example of Multiple Interface Inheritance
    /// Duck inherits from Animal and implements both ISwimmable and IFlyable
    /// </summary>
    class Duck : Animal, ISwimmable, IFlyable {
        public Duck(string name) : base(name) { }
        public void Swim() {
            Console.WriteLine($"{name} is swimming");
        }
        public void Fly() {
            Console.WriteLine($"{name} is flying");
        }
        public override void MakeSound() {
            Console.WriteLine($"{name} says: Quack!");
        }
    }

    /// <summary>
    /// Main program class demonstrating all inheritance types
    /// </summary>
    class Program {
        /// <summary>
        /// Entry point of the program
        /// Creates instances and demonstrates different inheritance behaviors
        /// </summary>
        static void Main(string[] args) {
            // Single Inheritance demonstration
            Dog dog = new Dog("Buddy");
            dog.MakeSound();

            // Hierarchical Inheritance demonstration
            Car car = new Car("Toyota");
            Bike bike = new Bike("Honda");
            car.Start();
            bike.Start();

            // Multilevel Inheritance demonstration
            ColoredRectangle coloredRect = new ColoredRectangle("Rectangle", 10, 5, "Red");
            coloredRect.DisplayInfo();

            // Multiple Interface Inheritance demonstration
            Duck duck = new Duck("Donald");
            duck.MakeSound();
            duck.Swim();
            duck.Fly();
        }
    }
}

