#include <stdio.h>
#include <stdlib.h>
int main(){
  int arr[] = {2,4,1,5,3,7,5,4,7} , i , j;
  int n = sizeof(arr) / sizeof(int);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i;j++)
    {
      if (arr[j]>arr[j+1])
      {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  for (i=0;i<n;i++)
  {
    printf("%d ",arr[i]);
  }
  return 0;
}
