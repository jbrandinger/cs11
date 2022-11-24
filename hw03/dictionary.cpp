// dictionary.cpp
//
// Purpose: define a word input by the user
//
// By: Joel Brandinger
//
// Date: 1 March 2021
//

#include <iostream>

using namespace std;

int find_word();
int define_word(int input);

int main()
{    
        define_word(find_word());
        
        return 0;        
}

int find_word()
{
        bool found = false;
        string input, none;
        string word[7] = {"Variable", "Function", "Recursion", "Pseudocode",
                           "Conditional", "Comp11", "Parameter"};
               
        cin >> input;
        
        for (int i = 0; (i < 7) and (not found); i++) {
                if (input == word[i]) {
                    found = true;
                    return i;
                }
        }
        
        return 8;
}

int define_word(int input)
{            
        string definition[7];
        
        definition[0] = "A location in the computer's memory that can store"
                        " a value";        
        definition[1] = "A named block of code that can be invoked as a"
                        " statement or within an expression";
        definition[2] = "A situation in which a definition refers to the" 
                        " term it is defining";        
        definition[3] = "Code written in plain english";
        definition[4] = "A method to execute a block of code depending on the"
                        " outcome of an expression";        
        definition[5] = "An introductory computer science course";
        definition[6] = "The names listed in a function's definition";

        bool found = false;
        
        for (int i = 0; (i < 7) and (not found); i++) {
                if (input == i) {
                    found = true;
                    cout << definition[i] << endl;
                }
        }
        
        if (not found) {
                    cout << "Definition Not Found" << endl;
        }
        return 0; 
}
