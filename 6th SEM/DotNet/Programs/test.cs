using System;

public class test {

  public static void Main()
  {
    Console.Write("Enter a number:");
    int num = Convert.ToInt32(Console.ReadLine());
    int proxy = num;
    int rem, ans = 0;
    while(num != 0){
      rem = num % 10;
      ans = ans * 10 + rem;
      num = num / 10;
    }
    if (ans == proxy){
      Console.WriteLine("Palindrome");
    }else{
      Console.WriteLine("Not Plaindrome");
    }
  }

}
