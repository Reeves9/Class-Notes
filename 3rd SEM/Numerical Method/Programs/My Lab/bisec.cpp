#include <iostream>
#include <cmath>
using namespace std;

float f(float x)
{
  return pow(x,3)-x-1;
}

float bisec(float a , float b , int n)
{
  float mid , res;
  while (n != 0)
  {
    mid = (a + b) / 2;
    res = f(mid);
    if (res < 0) 
    {
      a = mid;
    }
    else if (res > 0)
    {
      b = mid;
    }
    else 
    {
      break;
    }
    n--;
  }
  return mid;
}

int main()
{
  float a = 1, b = 2;
  int n = (log(b-a)-log(0.00001))/log(2);
  float res = bisec(a , b , n);
  cout << res << endl;
  return 0;
}
