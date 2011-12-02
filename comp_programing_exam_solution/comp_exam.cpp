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

bool isDouble(string s) {
  istringstream ss(s);
  double d;
  return (ss >> d) && (ss >> std::ws).eof();
}

bool isInteger(string s) {
  istringstream ss(s);
  int d;
  return (ss >> d) && (ss >> std::ws).eof();
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
    if (!isDouble(inS)) {
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
    if (!isInteger(inN)) {
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

/*
  Sample outputs for s = 0.5 and 0.9 with n = 10, 100, 200.  
  
  S (must be between 0 and 1):  .5
  N (must be an integer >= 0):  10
  Real Value:    2.0000000000000000000000000000000000000000000000000000000000000000e+00
  Series Value:  1.9990234375000000000000000000000000000000000000000000000000000000e+00
  Percent Error: 4.8828125000000000000000000000000000000000000000000000000000000000e-02%
  
  S (must be between 0 and 1):  .5
  N (must be an integer >= 0):  100
  Real Value:    2.0000000000000000000000000000000000000000000000000000000000000000e+00
  Series Value:  1.9999999999999999999999999999992111390947789881945882714347172138e+00
  Percent Error: 3.9443045261050590270586428264139311483660321755451150238513946543e-29%
  
  S (must be between 0 and 1):  .5
  N (must be an integer >= 0):  200
  Real Value:    2.0000000000000000000000000000000000000000000000000000000000000000e+00
  Series Value:  1.9999999999999999999999999999999999999999999999999999999999993777e+00
  Percent Error: 3.1115076389305708535720320268900621202951260843605835665505583073e-59%
  
  S (must be between 0 and 1):  .9
  N (must be an integer >= 0):  10
  Real Value:    1.0000000000000001776356839400250464677810668945312500000000000000e+01
  Series Value:  6.8618940391000012302136212838377105072140693664550781250000000000e+00
  Percent Error: 3.1381059608999999887036194756717597613936242467929529109894831874e+01%
  
  S (must be between 0 and 1):  .9
  N (must be an integer >= 0):  100
  Real Value:    1.0000000000000001776356839400250464677810668945312500000000000000e+01
  Series Value:  9.9997609474100159669828651910761241339287153095938265323638916016e+00
  Percent Error: 2.3905258998580933150993885457692096175839421034208922407163371878e-03%
  
  S (must be between 0 and 1):  .9
  N (must be an integer >= 0):  200
  Real Value:    1.0000000000000001776356839400250464677810668945312500000000000000e+01
  Series Value:  9.9999999936504330577557589697347636478058380965494578163088590372e+00
  Percent Error: 6.3495687186010793026057189771136746398838153890987286083075621870e-08%
*/