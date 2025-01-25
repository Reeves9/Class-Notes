#include <iostream>
#include <cmath>
using namespace std;

float f(float x)
{
  return pow(x,3)-x-1; //the given function 
}

float fd(float x)
{
  return 3*pow(x,2) - 1; //first derivative of the given function
}

float nr()
{
  float x0 = 2 , x1 = 0 , chk = 1; // x0 = 2 initail guess
  while ((chk - x1) >= 0.00001) // execute until reached desired error and 0.00001 is the error tolerance
  {
    x1 = x0 - (f( x0 ) / fd( x0 )); //the main formula
    chk = x0;
    x0 = x1;
  }
  return x1;
}

int main()
{
  float res = nr();
  cout << res << endl;
  return 0;  
}
