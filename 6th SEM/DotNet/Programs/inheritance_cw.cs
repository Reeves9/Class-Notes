// wap how to access data methods and constructors from parent class to child class
using System;

namespace InheritanceAccess {
    // Parent/Base class
    class Parent {
        // Data members with different access modifiers
        public string publicData = "Public data";
        protected string protectedData = "Protected data";
        private string privateData = "Private data";

        // Constructor
        public Parent() {
            Console.WriteLine("Parent constructor called");
        }

        // Methods with different access modifiers
        public void PublicMethod() {
            Console.WriteLine("Parent public method");
        }

        protected void ProtectedMethod() {
            Console.WriteLine("Parent protected method");
        }

        private void PrivateMethod() {
            Console.WriteLine("Parent private method");
        }
    }

    // Child/Derived class
    class Child : Parent {
        public Child() : base() {  // Calling parent constructor
            Console.WriteLine("Child constructor called");
        }

        public void AccessParentMembers() {
            // Accessing parent's public members
            Console.WriteLine(publicData);
            PublicMethod();

            // Accessing parent's protected members
            Console.WriteLine(protectedData);
            ProtectedMethod();

            // Cannot access parent's private members
            // This would cause error:
            // Console.WriteLine(privateData);
            // PrivateMethod();
        }
    }

    class Program {
        static void Main(string[] args) {
            Child child = new Child();
            child.AccessParentMembers();

            // Can access public members through child object
            child.PublicMethod();
            Console.WriteLine(child.publicData);

            // Cannot access protected or private members from outside
            // This would cause error:
            // child.ProtectedMethod();
            // child.privateData;
        }
    }
}
