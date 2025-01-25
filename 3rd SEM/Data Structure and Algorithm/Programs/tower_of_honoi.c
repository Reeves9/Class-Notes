#include <stdio.h>

int tower(int n , char from_rod , char to_rod , char aux_rod)
{
  if(n == 0)
  {
    return 0;
  }
  tower(n-1,from_rod,aux_rod,to_rod);
  printf("Move disk %d from rod %c to rod %c \n",n,from_rod,to_rod);
  tower(n-1 , aux_rod, to_rod, from_rod);
}

int main()
{
  int n;
  printf("enter the no of disks\n");
  scanf("%d",&n);
  tower(n,'A','C','B');
  return 0;
}
