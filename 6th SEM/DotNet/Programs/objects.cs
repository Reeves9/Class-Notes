//wap in c# to impliment constructor overloading
using System;

namespace Programs{
    public class Program{

        public Program(){
            Console.WriteLine("Default constructor");
        }
        public Program(int a){
            Console.WriteLine($"Parameterized constructor {a}");
        }
        public Program(int a,int b){
            Console.WriteLine("Parameterized constructor {0}",a+b);
        }
        public static void Main(string[] args){
            Program p = new Program();
            Program p1 = new Program(1);
            Program p2 = new Program(1,2);
        }
    }
}