using System;
namespace patterns
{
    class Program
    {
        static int sum(int number){
            if (number == 0){
                return 0;
            }
            return number % 10 + sum(number /10);
        }
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
            
            int ans = sum(125);
            Console.Write(ans);
        }
    }
}
            