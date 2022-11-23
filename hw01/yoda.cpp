// yoda.cpp
//
// purpose: rephrase 4 words backwards
// by: Joel Brandinger
// date: 15 February 2021
//

#include <iostream>

using namespace std;

int main ()
{
   
    string word1, word2, word3, word4, yoda;
    
    cout << "Type in four words: ";
    cin >> word1 >> word2 >> word3 >> word4;
    
    yoda = word4 + " " + word3 + " " + word2 + " " + word1;
  
    cout << yoda << endl;
    
    return 0;  
    
}
