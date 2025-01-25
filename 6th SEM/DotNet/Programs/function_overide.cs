//wap to impliment function overloading
using System;

namespace Program{
    public class Program{
        public static int add(int a , int b){
            return a + b;
        }
        public static int add(int a , int b, int c){
            return a + b + c;
        }
        //for area of circle
        public static double area(int radius){
            return (22/7)*radius*radius;
        }
        //for area of triangle
        public static double area(int bottom, int height){
            return (1/2)*bottom*height;
        }
        //for area of rectangle
        public static void Main(string[] args){
            int a=1,b=2,c=3;
            Console.WriteLine(add(a,b));
            Console.WriteLine(add(a,b,c));
            Console.Write("enter radius:");
            int radius = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine($"area is {area(radius)}");
            Console.Write("enter base and height:");
            int bottom = Convert.ToInt32(Console.ReadLine());
            int height = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine($"area is {area(bottom,height)}");
        }
    }
}
