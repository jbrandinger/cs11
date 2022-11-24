/* Guess.cpp
 * 
 * Purpose: Generate a random number (5-15) and have the user
 *          try to guess what the number is
 * 
 * By: Joel Brandinger
 *
 * Date: 22 February 2021
 */ 

#include <iostream>

// The following are for srand() and time()
// for random numbers. Leave them 
// in your program.
#include <cstdlib>
#include <ctime>

using namespace std;

string high_or_low(int guess, int num);
int prompt();
 
int main()
{
        
         srand(time(nullptr));
        
         int randNum = rand() % 11 + 5;
        
         string result = high_or_low(prompt(),randNum);
        
         cout << result;
        
         if (result == "You guessed it! Good job!") {        
         } else {
            result = high_or_low(prompt(),randNum);
            cout << result;
                if (result == "You guessed it! Good job!") {
                    
                } else {
                    result = high_or_low(prompt(),randNum);
                        if (result == "You guessed it! Good job!") {
                        cout << result << endl;
                        
                        } else {
                            cout << "The number was " << randNum 
                                 << ". Better luck next time!" << endl;
                        }
                    
                }
        }
            
        
        return 0;
}

string high_or_low(int guess, int num)
{
         string high, low, correct, answer;

         high = "That was too high. ";
         low = "That was too low. ";
         correct = "You guessed it! Good job!";


         if (guess > num) {
                answer = high;
         }

         if (guess < num) {
                answer = low;
         }

         if (guess == num) {
                answer = correct;
         }

         return answer;

}

int prompt()
{
      int guess;
    
      cout << "Enter a guess: ";
      cin >> guess;
    
     return guess;
}