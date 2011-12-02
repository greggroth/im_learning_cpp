#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

int main (void) {
  vector<float> data;
  float x;
  
  cout << "Enter each number followed by <enter>.  Enter a letter to stop input:  " << endl ;
  while ( cin >> x) data.push_back (x);
  float data_max = data.front(), data_min = data.front();

  for ( unsigned int i = 0; i < data.size(); i++) {
    if ( data.at(i) > data_max )
      data_max = data.at(i);
    else if ( data.at(i) < data_min )
      data_min = data.at(i);
  }

  cout << "Max:  " << data_max << endl;
  cout << "Min:  " << data_min << endl;
  
  return 0;
}