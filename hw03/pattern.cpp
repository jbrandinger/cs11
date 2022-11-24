// pattern.cpp
//
// Purpose: create a pattern using two strings, each repeated 5 times
//          per row for n lines
//
// By: Joel Brandinger
//
// Date: 2 March 2021
//

#include <iostream>

using namespace std;

void output_pattern(string s1, string s2, int n);

int main()
{
        string s1, s2;
        int n;
            
        cin >> s1 >> s2 >> n;
        
        output_pattern(s1, s2, n);    
}

void output_pattern(string s1, string s2, int n)
{        
        if (n == 0) {
                return;    
        } else {
                cout << s1 << s2 << s1 << s2 << s1 << s2
                     << s1 << s2 << s1 << s2 << endl;
                return output_pattern(s2, s1, n - 1);
        
        }
}