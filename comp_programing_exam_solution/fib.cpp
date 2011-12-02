#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

int main (void) {
  vector<unsigned long int> seq (2, 1);
  
  for ( unsigned int i=2; i<100; i++) {
    seq.push_back (seq[i-2] + seq[i-1]);
  }
  
  for ( unsigned int i=0; i < seq.size(); i++) {
      cout << seq.at(i) << "  " ;
  }
  cout << endl;
  
  return 0;
}