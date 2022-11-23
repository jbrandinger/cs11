// add8.cpp
// 
// purpose: find the sum of eight numbers
// by: Joel Brandinger
// date: 14 February 2021
//

#include <iostream>

using namespace std;

int main()
{
      
      // float a, b, c, d, e, f, g, h, sum;
      // 
      // 
      // cout << "Enter a floating point number: ";
      // cin >> a;
      // 
      // cout << "Enter a floating point number: ";
      // cin >> b;
      // 
      // cout << "Enter a floating point number: ";
      // cin >> c;
      // 
      // cout << "Enter a floating point number: ";
      // cin >> d;
      // 
      // cout << "Enter a floating point number: ";
      // cin >> e;
      // 
      // cout << "Enter a floating point number: ";
      // cin >> f;
      // 
      // cout << "Enter a floating point number: ";
      // cin >> g;
      // 
      // cout << "Enter a floating point number: ";
      // cin >> h;
      // 
      // sum = a + b + c + d + e + f + g + h;
      // 
      // cout << "The sum is: " << sum << endl;
      // 
      string promt = "Enter a floating point number: ";
      int input;
      int sum = 0;
      
      for (int i = 0; i < 8; i++) {
          cout << prompt;
          cin >> input;
          sum = sum + input;
      }
      
      cout << "Sum = " << sum << endl;
      return 0;    
    
}