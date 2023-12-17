#include <stdio.h>

int gcd(int num1 , int num2)
{
  if (num2 != 0)
  {
    return gcd(num2 , num1 % num2);
  }
  else 
  {
    return num1;
  }
}

int main()
{
  int num1 , num2 , ans;
  printf("enter two numbwrs\n");
  scanf("%d%d",&num1,&num2);
  if (num1 > num2)
  {
    ans = gcd(num1,num2);
  }
  else
  {
    ans = gcd(num2,num1);
  }
  printf("gcd of %d and %d is %d", num1 , num2 , ans);
  return 0;
}
