#include <iostream>
#include <string>
using namespace std;
int main (void)
{
  string greeting = "Hello, ";
  string name = "";
  cout << "What's your name?"
  cin >> name ;
  cout << endl << greeting << name.c_str() << endl ;
  return 0;
}