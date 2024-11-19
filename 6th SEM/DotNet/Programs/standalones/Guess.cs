using System;

public class Guess {

  public static void Main(){
    
    Random rnd = new Random();
    
    int guess = rnd.Next(1,50); 
    while (true){
    
      Console.WriteLine("Guess a number between 1 and 50");
      int choice = Convert.ToInt32(Console.ReadLine());
      
      if (choice == guess){
        Console.WriteLine("Correct answer!");
        break;
      }else if (choice > guess){
        Console.WriteLine("Guess lower");
      }else {
        Console.WriteLine("Guess Higher");
      }
    
    }
  
  }

}
