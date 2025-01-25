// operations on arrays and varioous algorithms
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
            Console.Write("Sorted array is: ");
            for (int i=0;i<size;i++){
                Console.Write($" {array[i]}");
                Console.WriteLine("");
            }
            // multi dimentional array and sum of matrices
            int[,] mat1 = new int[3,3];
            int[,] mat2 = new int[3,3];
            Console.WriteLine("For first Matrix");
            for (int i=0;i<3;i++){
                for (int j=0;j<3;j++){
                    Console.Write($"enter value of position {i} {j}:");
                    mat1[i,j] = Convert.ToInt32(Console.ReadLine());
                }
            }
            Console.WriteLine("For second Matrix");
            for (int i=0;i<3;i++){
                for (int j=0;j<3;j++){
                    Console.Write($"enter value of position {i} {j}:");
                    mat2[i,j] = Convert.ToInt32(Console.ReadLine());
                }
            }
            for (int i=0;i<3;i++){
                for (int j=0;j<3;j++){
                    mat1[i,j] += mat2[i,j];
                }
            }
            for (int i=0;i<3;i++){
                for (int j=0;j<3;j++){
                    Console.Write($"{mat1[i,j]} ");
                    if (j==2){
                        Console.WriteLine("");
                    }
                }
            }
        }
    }
}
