// input size of array and find sum of elements
using System;

namespace array
{ 
    class Program {
        static void Main(string[] args){
            int sum = 0;
            Console.Write("Enter size of array: ");
            int size = Convert.ToInt32(Console.ReadLine());
            int[] array = new int[size];
            for (int i=0;i<size;i++){
                Console.Write($"Enter value of index {i}: ");
                array[i] = Convert.ToInt32(Console.ReadLine());    
            }
            // finding the sum
            for (int i=0;i<size;i++){
                sum +=array[i];
            }
            Console.WriteLine($"Sum of array is {sum}");
            //finding the greatest
            int greatest = 0;
            for (int i=0;i<size;i++){
                if (greatest < array[i]){
                    greatest = array[i];
                }
            }
            Console.WriteLine($"Greatest is {greatest}");
            //sorting the values
            for (int i=0;i<size;i++){
                for (int j=0; j<i;j++){
                    if (array[j] > array[i]){
                        int temp = array[i];
                        array[i] = array[j];
                        array[j] = temp;
                    }
                }
            }
            Console.Write("Sortes array is: ");
            for (int i=0;i<size;i++){
                Console.Write($" {array[i]}");
            }
        }
    }
}
