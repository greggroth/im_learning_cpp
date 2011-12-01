#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
#include <sstream>
#include <qd/qd_real.h>

using std::cout;
using std::endl;
using namespace std ;

bool checkForDouble(string const& s) {
  istringstream ss(s);
  double d;
  return (ss >> d) && (ss >> std::ws).eof();
}

bool checkForInteger(string s) {
  bool isValid = true;
  for (unsigned int nInd = 0; nInd < s.length(); nInd++) {
    if (!isdigit(s[nInd])) {
      isValid = false;
      break;
    }
    if (!isValid)
      continue;
  }
  return isValid;
}

int main (void) {
  string inS, inN;
  double doubS;
  int intN;
  
  while (1) {
    cout << "S (must be between 0 and 1):  ";
    getline(cin, inS);
    
    if (!checkForDouble(inS)) {
      cout << "I need a number for this to work.  Try again." << endl;
      continue;
    }
    stringstream strStream;
    strStream << inS;
    strStream >> doubS;
    if (doubS < 0 || doubS > 1) {
      cout << "It must be between 0 and 1.  Try again." << endl;
      continue;
    }
    
    break;
  }
  
  while (1) {
    cout << "N (must be an integer greater than 0):  ";
    getline(cin, inN);
    
    if (!checkForInteger(inN)) {
      cout << "I need an integer for this to work.  Keep trying." << endl;
      continue;
    }
    
    stringstream strStream;
    strStream << inN;
    strStream >> intN;
    if (intN < 0) {
      cout << "It's not that hard.  Just enter a number larger than 0." << endl;
      continue;
    }
    
    break;
  }
  
  //  Now that we have good inputs for s and n, we can do some math
  qd_real seriesValue = 0, realValue, percentError, qdS = doubS;
  realValue = 1/(1-qdS);
  
  for (int i = 0; i <= intN; i++) {
    seriesValue += pow(qdS, i);
  }
  percentError = ((abs (realValue - seriesValue))/realValue) * 100;
  
  cout.precision(64);
  cout << "Real Value:    " << realValue << endl;
  cout << "Series Value:  " << seriesValue << endl;
  cout << "Percent Error: " << percentError << '%' << endl;
    
  return 0;
}