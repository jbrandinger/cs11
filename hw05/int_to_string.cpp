/*
 * int_to_string.cpp
 * Program to test the int_to_string function, whose contract appears below
 * Essential idea:  Given an integer, like 87, return the string
 * consisting of the same digits, i. e., "87".
 *
 * By: Joel Brandinger
 */

#include <iostream>

using namespace std;

string int_to_string(int num);
void testing(int num, string correct);

int main()
{
    
        testing(12, "12");
        testing(-5, "-5");
        testing(0, "0");
        testing(86, "86");
        
        return 0;
}


/* int_to_string 
* Purpose: evaluate each digit in the integer starting with the last. once
*          each digit has been idetified, add it to the string
* Parameters: integer that we wish to convert to a strng
* Returns: string version of number
*/
string int_to_string(int num)
{
    if (num == 0) {
        return "0";
    }
    
    string answer = "";
    
    bool negative = false;
    
    if (num < 0) {
        num = num / -1;
        negative = true;
    }
    
    while (num != 0) {
        
        char c = num % 10 + 48;
        answer = c + answer;
        num = num / 10;    
    } 
    if (negative) {
        answer = "-" + answer;
    }
    return answer;    
}

/* testing 
* Purpose: Test to see if the string returned from int_to_string function
*          is the same as the expected answer.
* Parameters: the integer that was input in int_to_string and the correct
*             string. 
* Returns: Void, function prints the appropraite statements.
*/
void testing(int num, string correct)
{
    if (int_to_string(num) == correct) {
        cout << "TESTING: " << num << endl;
        cout << "SUCCESS: " << correct << endl;
    } else {
        cout << "TESTING: " << num << endl;
        cout << "FALURE: " << int_to_string(num) << endl;    
    }
}

