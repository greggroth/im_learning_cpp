#include <iostream>
#include <string>
using namespace std;
int main (void)
{
  int menuChoice = 1;
  cout << "Choose and option:" << endl;
  cout << "(1)  Option 1" << endl;
  cout << "(2)  Option 2" << endl;
  cout << "(3)  Option 3" << endl;
  cout << endl << "Choose:  ";
  cin >> menuChoice;
  switch(menuChoice)
  {
    case 1:
    cout << "Good choice!  Number 1 it is!" << endl;
    break;
    case 2:
    cout << "Not bad!  Number 2 it is!" << endl;
    break;
    case 3:
    cout << "Terrible!!  Just kidding.  Number 3 it is!" << endl;
    break;    
    default:
    cout << "That's not an option!!" << endl;
    break;
  }
  return 0;
}