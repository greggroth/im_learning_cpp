/*
  Computer Exam Solultion
  Greggory Rothmeier
  greggroth@gmail.com
  

  This is a bomb-proof solution to the take-home exam.  Much of the code is 
  dedicated to verifying that appropiate input is given.  I've added 
  comments to aid in understanding.  In order to campure the difference in 
  values between the exact and series solutions, I'm using a library which 
  allows for quadruple-double precision (~64 decimal digits) available at 
  (http://crd.lbl.gov/~dhbailey/mpdist/qd-2.3.12.tar.gz).
*/

#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <sstream>
#include <qd/qd_real.h>

using namespace std;

bool checkForDouble(string s) {
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
  
  // Get and verify a valid s
  while (1) {
    cout << "S (must be between 0 and 1):  ";
    getline(cin, inS);
    
    // Make sure the string is a number
    if (!checkForDouble(inS)) {
      cout << "I need a number for this to work.  Try again." << endl;
      continue;
    }
    
    // Convert the string to double
    doubS = atof ( inS.c_str() );
    
    // Check that the number is between 0 and 1
    if (doubS < 0 || doubS > 1) {
      cout << "It must be between 0 and 1.  Try again." << endl;
      continue;
    }
    
    break;
  }
  
  // Get and verify a valid n
  while (1) {
    cout << "N (must be an integer >= 0):  ";
    getline(cin, inN);
    
    // Makes sure it's an integer
    if (!checkForInteger(inN)) {
      cout << "I need an integer for this to work.  Keep trying." << endl;
      continue;
    }
    
    // If it is an integer, convert the string to int
    intN = atoi ( inN.c_str() );
    
    // Criticize the user if they don't read the instructions
    if (intN < 0) {
      cout << "It's not that hard.  Just enter a number larger than 0 or equal to 0." << endl;
      continue;
    }
    
    break;
  }
  
  //  Now that we have good inputs for s and n, we can do some math
  
  // Using quad-double for extra precision
  qd_real seriesValue = 0, realValue, percentError;
  
  // Get the exact solution
  realValue = 1/(1-doubS);
  
  // Get the series solution
  for (int i = 0; i <= intN; i++) {
    seriesValue += pow(doubS, i);
  }
  
  // Compare them
  percentError = ((abs (realValue - seriesValue))/realValue) * 100;
  
  // Output the result
  cout.precision(64);
  cout << "Real Value:    " << realValue << endl;
  cout << "Series Value:  " << seriesValue << endl;
  cout << "Percent Error: " << percentError << '%' << endl;
    
  return 0;
}