#include <iostream>
using namespace std;

double add (double a, double b ) {
  return a + b;
}

int add (int a = 0, int b = 0) {
  return a + b;
}



int main (void)
{
  cout << add(1,2) << endl;
  cout << add(50.3,20.2) << endl;
  cout << add(1) << endl;
  cout << add() << endl;
  return 0;
}