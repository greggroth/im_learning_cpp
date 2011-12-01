#include <iostream>
#include <ctime>
using namespace std;

//function declarations
int main(void);
int race(int, int);
void race(void);
int menu(void);
int placeBet(int);
void ini(void);

//variables
int money = 200;

//the main function
int main(void)
{
     ini();

     int userResponse;
     cout<< "Welcome to the snail races!!!" <<endl;
     while(userResponse = menu())
     {
          switch(userResponse)
          {
          case 1:
          case 2:
          case 3:
               ::money += 
               race(placeBet(userResponse), userResponse);
               break;
          case 4: //the user did not bet
               race();
               break;
          }
     }
     return 0;
}

//displays the main menu and 
//returns the user’s selection
int menu(void)
{
  // Kicks 'em out if they're out of money
  if(::money <= 0) {
    cout << "You're out of money!!  Try again tomorrow." << endl;
    return 0;
  }
  int userResponse;
  cout << "You have " << money << " dollars."<< endl;
  do {
    cout<< "Races Menu" <<endl
         << "1) Bet on snail 1" << endl
         << "2) Bet on snail 2" << endl
         << "3) Bet on snail 3" << endl
         << "4) Just Watch" << endl
         << "0) leave the races" << endl;
    cin>> userResponse;
  }
  while(userResponse < 0 && userResponse > 4); 
  return userResponse;
}

//decides how much a person will bet on the snail
int placeBet(int userResponse)
{
     int betAmount;
     cout<< "Snail " << userResponse << " is a good choice!"
          << endl;
     cout<< "How much would you like to bet on your snail "
          << userResponse <<"?    ";
     cin >> betAmount;
     return betAmount;
}
//if they are just watching the race
void race (void)
{
     race(0, 0);
}

//if they are betting money
int race (int money, int userResponse)
{
     //stores the random number
     int winner = rand() % 3 + 1;
     cout<< "And the snails are off" << endl
          << "Look at them GO!!!" << endl
          << "The winner is snail " << winner << endl;
     if(winner == userResponse)
     {
          cout<< "You Win!" <<endl;
          return 2 * money;
     }
     cout<<"You loose " << money << " dollars." <<endl;
     return -1 * money;
}

//handles program initializations
void ini(void)
{
     srand(time(0));
}