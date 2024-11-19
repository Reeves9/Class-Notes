using System;
namespace patterns
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int i=1;i<=10;i++){
                Console.Write($"{i*i} ");
            }
            Console.WriteLine();
            for (int i=1;i<=20;i++){
                Console.Write($"{i*i*i} ");
            }
            Console.WriteLine();
            for (int i=1;i<=20;i++){
                Console.Write($"{(i*i)+(i*i*i)} ");
            }
            Console.WriteLine();
        }
    }
}
            