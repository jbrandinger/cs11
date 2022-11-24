/*
 * wordfreq
 *
 * 1. Reads in strings from the standard input (cin)
 *    Ignores non-words (where a "word" is a sequence of non-whitespace
 *    characters beginnig with an upper or lowercase letter
 * 2. Converts each word to lower case
 * 3. Inserts each word into a WordFreqList to track the number of
 *    times each word is seen

 * 4. When the input is fully processed, prints a line for each word
 *    in the WordFreqList formatted thus:
 *    the interger number of occurrences of the word, a single space,
 *    the word itself, a newline.  E. g., "14 we\n"
 *
 * Only works for ASCII --- Real text is hard!
 *
 * Mark A. Sheldon, Tufts University, Spring 2021
 *
 *
 * Student name: Joel Brandinger
 * Date: 27 April 2021 
 *
 * Anything else you would like to include
 */

#include <iostream>
#include <string>
#include <cctype>

// The following file will be a copy of the file you want
// DON'T CHANGE THIS!
#include "WordFreqList.h"
// Seriously, Don't change the line above.  It's important!

using namespace std;

bool   check_word(string word);
string lowercase_word(string word);
void   printWordFreq(WordFreq wf);

int main() 
{        
        string word;
        WordFreqList list;
    
        while (cin >> word) {
            
            if (check_word(word)) {
                list.countOccurrence(lowercase_word(word));
            }
        }
        
        for (int i = 0; i < list.size(); i++) {
                printWordFreq(list.get(i));
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

/*
 * Purpose:  Print the word and frequency in a WordFreq struct
 *           on cout followed by a single newline
 */
void printWordFreq(WordFreq wf)
{
        cout << wf.freq << " " << wf.word << endl;
}

