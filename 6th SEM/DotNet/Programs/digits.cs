﻿using System;

namespace digits{
    class Program{
        static int factorial(int num){
            int result = 1;
            for (int i=1;i<=num;i++){
                result *= i;
            }
            return result;
        }
        static void Main(){
            // finding strong number
            int num,proxy,rem,fac=0;
            Console.Write("Enter a number: ");
            num = Convert.ToInt32(Console.ReadLine());
            proxy = num;
            while (num != 0){
                rem = num % 10;
                fac += factorial(rem);
                num /= 10;
            }
            if (fac == proxy){
                Console.WriteLine("Strong number");
            }else{
                Console.WriteLine("Not strong number");
            }
            // fing sum of individual digits
            int sum=0;
            Console.Write("Enter a number: ");
            num = Convert.ToInt32(Console.ReadLine());
            while (num != 0){
                rem = num % 10;
                sum += rem;
                num /= 10;
            }
            Console.WriteLine($"The sum is {sum}");
            // finding dudeni number
            sum = 0;
            Console.Write("Enter a number: ");
            num = Convert.ToInt32(Console.ReadLine());
            proxy = num;
            while (num != 0){
                rem = num % 10;
                sum += rem;
                num /= 10;
            }
            sum = sum * sum * sum;
            if (sum == proxy){
                Console.WriteLine("Dudeny number");
            }else{
                Console.WriteLine("Not dudeny number");
            }
            // sum of factorial of factors
            Console.Write("Enter a number: ");
            num = Convert.ToInt32(Console.ReadLine());
            fac = 0;
            for (int i=1;i<=num;i++){
                if (num % i == 0){
                    fac += factorial(i);
                }
            }
            Console.WriteLine($"The sum is {fac}");
        }
    }
}