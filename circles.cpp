#include <iostream>
#include <string>
#include <math.h>
using namespace std ;
int main (void)
{
  typedef float f;
  const f PI = 3.141592;
  f radius, circumference, area;
  
  cout << "Enter the radius:  ";
  cin >> radius ;
  // Do maths
  circumference = 2*PI*radius;
  area = PI*pow(radius,2);
  // Output results
  cout << endl << "Circumference:  " << circumference;
  cout << endl << "Area:           " << area;
  cout << endl;
  return 0;
}