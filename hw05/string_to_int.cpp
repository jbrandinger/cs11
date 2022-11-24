/*
 * string_to_int.cpp
 * 
 * Program to test the string_to_int function, whose contract appears below
 * 
 * Essential idea:  extract digits from a string and return the integer that
 *                  results.  E. g., "a1b2c3" should produce the integer 123
 *
 * By: Joel Brandinger
 */

#include <iostream>

using namespace std;

int string_to_int(string s);
void success_or_failure(string s, int answer);

int main()
{
        
        success_or_failure("123ab6", 1236);
        success_or_failure("comp11issoc00L", 1100);
        success_or_failure("ericmetajisgr8", 8);
        success_or_failure("cann0L15", 15);
         
        return 0;
}

/* string_to_int
 * Purpose:   extract an integer from the digit characters in a string
 * Arg:       string that may or may not contain digit characters ('0' -- '9')
 * Returns:   the integer that result from extracting digits from string s
 * Notes:     only digit characters are considered.  
 *            Sign characters ('+', '-') are non-digits and are ignored
 * 
 */
int string_to_int(string s)
{    
        int digits = 0;
        
        for (size_t i = 0; i < s.length(); i++) {
            
            if (s[i] >= 48 && s[i] <= 57) {
                digits = digits * 10 +(s[i] - 48);
            }    
        } 
        return digits;              
} 

/* success_or_failure
 * Purpose: test to see if the digits returned from string_to_int
 *          match the expected answer. Output success or failure.
 * Arguments: string that may or may not contain digits and int that
 *            is the correct output.
 * Returns: void 
 */

void success_or_failure(string s, int answer)
{
        if (string_to_int(s) == answer) {
            cout << "TESTING: " << s << endl;
            cout << "SUCCESS: " << answer << endl;
        } else {
            cout << "TESTING: " << s << endl;
            cout << "FAILURE: " << string_to_int(s) << endl;
        }
}
