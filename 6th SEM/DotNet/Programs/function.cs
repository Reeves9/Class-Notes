using System;
namespace function{
    class Program{
        //wap to input a number and calculate the sum of individual digits present on that number using resursive function
        static int sum(int number){
            if (number == 0){
                return 0;
            }
            return number % 10 + sum(number /10);
        }

        static void Main(){
            Console.Write("enter a number");
            int number = Convert.ToInt32(Console.ReadLine());
            int answer = sum(number);
            Console.WriteLine(answer);
        }
    }
}
