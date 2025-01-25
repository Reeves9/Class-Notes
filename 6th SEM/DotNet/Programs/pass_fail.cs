using System;

class Program{
    public static void Main(String[] args) {
        float[] marks = new float[5];
        string grade;
        bool flag = false; 
        Console.WriteLine("enter marks of 5 subjects: ");
        for(int i=0; i<5; i++) {
            marks[i] = float.Parse(Console.ReadLine());
        }
        for(int i=0;i<5;i++){
            if (marks[i] < 40){
                flag = true;
            }
        }
        if(flag == false){
            float sum = 0;
            float total = 500;
            for(int i=0;i<5;i++){
                sum += marks[i];
            }
            float percentage = (sum/total)*100;
            if(percentage > 90){
                grade = "A+";
            }else if (percentage >80){
                grade = "A";
            }else if (percentage >70){
                grade = "B+";
            }else if (percentage >60){
                grade = "B";
            }else if (percentage >50){
                grade = "C+";
            }else if (percentage >40){
                grade = "C";
            }else{
                grade = "D";
            }
        }else{
            grade = "Fail";
        }
        Console.WriteLine(grade);
    }
}