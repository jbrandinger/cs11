/*
 * Preliminary program that reads in the standard input one whitespace 
 * delimited string at a time and prints the lowercase version of those 
 * that begin with a letter.
 * 
 * Only works for ASCII --- Real text is hard!
 *
 * Name: Joel Brandinger
 * Date: 20 April 2021 
 * Notes:
 */

#include <iostream>

using namespace std;

bool check_word(string word);
string lowercase_word(string word);

int main() 
{        
        string word;
    
        while (cin >> word) {
            
            if (check_word(word)) {
                cout << lowercase_word(word) << endl;
            }
        } 
        return 0;
}

/* check_word
 * parameters: string word 
 * purpose: checks to see if first character of a word is a letter 
 * returns: true if first character starts with a letter 
 */
bool check_word(string word) {
    
        if ((word[0] >= 65 && word[0] <= 90) || 
            (word[0] >= 97 && word[0] <= 122)) {
                return true;
        } else {
                return false;
        }
}

/* lowercase_word
 * parameters: string word 
 * purpose: converts all uppercase letters to lowercase 
 * returns: lowercase version of the word 
 */
string lowercase_word(string word) {

        for (size_t i = 0; i < word.length(); i++){
            if (word[i] >= 65 && word[i] <= 90) {
                word[i] = word[i] + 32;
            }
        }
        return word;
}
