#include <ctime>
#include <cstdlib>
using namespace std;

int main (void)
{
  int max = 10;
  int min = 1;
  srand(time(0));
  cout << rand() % (max - min + 1) + min;
  return 0;
}