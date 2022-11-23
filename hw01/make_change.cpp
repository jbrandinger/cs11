// make_change.cpp
//
// purpose: give amount of change in quarters, dimes, nickels, and pennies
// by: Joel Brandinger
// date: 15 February 2021

#include <iostream>

using namespace std;

int main ()

{
    int change, q, d, n, p, r1, r2, r3;
    
    cout << "Amount of change in cents: ";
    cin >> change;
    
    q = change / 25;
    r1 = change % 25;
    
    d = r1 / 10;
    r2 = r1 % 10;
    
    n = r2 / 5;
    r3 = r2 % 5;
    
    p = r3 / 1;
    
    cout << q << " quarters, " << d <<  " dimes, " << n << " nickels, "
         << p << " pennies" << endl;
  
    return 0;
    
  
}