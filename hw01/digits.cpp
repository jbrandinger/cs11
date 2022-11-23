// iftest.cpp
//      purpose: report number of digits in an integer
//        shows: use of output, input, conditional statements
//         note: has bugs, needs work
//
//  modified by: Joel Brandinger
//         date: 14 February 2021
//

#include <iostream>

using namespace std;

int main()
{
        int input;

        cout << "Enter a number: ";
        cin  >> input;

        if (input > 99) {
                cout << "input has three or more digits" << endl;
        } else if (input > 9) {
                cout << "input has two digits" << endl;
        } else if (input > 0) {
                cout << "input has one digit" << endl;
        } else if (input == 0){
                cout << "input is zero" << endl;
        } else if (input > -10){
                cout << "input has one digit" << endl;
        } else if (input > -100){
                cout << "input has two digits" << endl;
        } else {
                cout << "input has three or more digits" << endl;
        }




        if (input > 0) {
                cout << " and is positive" << endl;
        } else if (input == 0) {
                cout << "and is neither positive or negative" << endl;
        } else {
                cout << "and is negative" << endl;
        }
        return 0;
}
