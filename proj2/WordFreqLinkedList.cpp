/*
 * A linked-list based implementation of a class that keeps track of 
 * word-frequecy data.
 * 
 * The data are stored as a singly-linked sequence of nodes accessed
 * from a single pointer (in the data member 'front') to the first
 * node in the list (or the nullptr if the list is empty).  Each node
 * has a word (stored as a string), and an integer representing the
 * number of times that word has been counted.
 *
 * IMPORTANT INVARIANT:
 * The words are in the list in alphabetical order. 
 *
 * Mark A. Sheldon, Tufts Uiversity, Spring 2021
 *
 * Student name: Joel Brandinger 
 * Date: 22 April 2021 
 */

/*************  Fill in the TODO items below  *************/
/***  You may add additional private member functions   ***/
/**********************************************************/
#include <iostream>
#include <string>
#include <cstdlib>

#include "WordFreqLinkedList.h"

using namespace std;

/*
 * Purpose:  Constructor initializes an empty list
 */
WordFreqLinkedList::WordFreqLinkedList()
{
        front = nullptr;
}

/*
 * Purpose:  Destructor recycles the space associated with all nodes
 *           in the list
 */
WordFreqLinkedList::~WordFreqLinkedList()
{
        while (front != nullptr) {
            front = removeFirst(front);
        }
}

/*
 * Purpose: remove first element from the list 
 */
WordFreqLinkedList::Node *WordFreqLinkedList::removeFirst(Node *firstNode)
{
        Node *toDiscard = firstNode;
        Node *newFirstNode = firstNode->next;
        
        delete toDiscard;
        
        return newFirstNode;
}
/*
 * Purpose:  Return the current size of the list, 
 *           i. e., the number of words/nodes in the list
 */
int WordFreqLinkedList::size()
{
        numElements = 0;
        
        Node *curr = front;
        
        while (curr != nullptr) {
                numElements++;
                curr = curr->next;
        }
        
        return numElements;
}

/*
 * Purpose:  Register one more occurrence of the given word
 *           If word is already in list, it's frequency is incremented by one
 *           If word is not in list, it is added with a frequency of 1
 *           Words are always added in alphabetical order, that is
 *           adding a new word means it goes in front of the first
 *           word that compares > than the new word, or at the end of
 *           the list if this word comes after all the words in the
 *           list alphabetically.
 * Params:   The string word to be added to the list
 * Effects:  Modifies a frequency in the list or adds a new element
 */
void WordFreqLinkedList::countOccurrence(string word)
{
        Node *curr = front;
        
        while (curr != nullptr) {
            
            if (curr->data.word == word) {
                curr->data.freq++;
                return;
            }
            curr = curr->next;
        }
        
        insertInOrder(word);     
}

/*
 * Purpose: Insert the new word in alphabetical order 
 */
void WordFreqLinkedList::insertInOrder(string word)
{
        
        if (isEmpty() or word < front->data.word) {
                Node *newFront = newNode(word);
                newFront->next = front;
                front = newFront; 
                return; 
        } else {
                Node *curr = front->next;
                Node *prev = front;
        
            while (curr != nullptr) {
                if (word < curr->data.word) {
                        Node *newN = newNode(word);
                        newN->next = curr;
                        prev->next = newN;
                        return;
            }
                    curr = curr->next;
                    prev = prev->next;    
            }    
            prev->next = newNode(word);               
        }
}

/*
 * Purpose: Create a new Node 
 */
WordFreqLinkedList::Node* WordFreqLinkedList::newNode(string word)
{
        Node *newNode = new Node;
        newNode->next = nullptr;
        newNode->data.word = word;
        newNode->data.freq = 1;
        return newNode;
}

/*
 * Purpose:  check if list is empty 
 */
bool WordFreqLinkedList::isEmpty() 
{
        if (front == nullptr) {
            return true;
        }
        return false;
}
/*
 * Purpose:  Return the index-th element of the list
 * Params:   index must be in range [0 .. size) where
 *           size is the number of words stored in the list
 * Effects:  if index is out of range, prints error message and exits program
 *           otherwise, none
 */
WordFreq WordFreqLinkedList::get(int index)
{
        if ((index < 0) || (index >= size())) {
            cout << "index " << index << " out of range [0, " << size() 
                 << ")" << endl;
                 exit(1);
        }
        
        Node *curr = front;
        int counter = 0;
        
        while (counter != index) {
            counter++;
            curr = curr->next;
        }  
        return curr->data;   
}

/*
 * Purpose:  Remove word from the list.  That is, it removes and 
 *           recycles the node containing the word (and its count)
 */
void WordFreqLinkedList::remove(string word)
{
        front = removeRec(word, front);
}

/*
 * Purpose: Remove first occurrence of word from list starting at firstNode
 *          and return pointer to first Node of result
 */
WordFreqLinkedList::Node *WordFreqLinkedList::
                          removeRec(string word, Node *firstNode)
{
        if (firstNode == nullptr) {
            return nullptr;
        } else if (firstNode->data.word == word) {
            return removeFirst(firstNode);
        } else {
            firstNode->next = removeRec(word, firstNode->next);
            return firstNode;
        }
}
/*
 * Purpose:  print out the underlying list on cout
 * Effects:  prints to cout
 * Notes:    this function is here for debugging purposes.
 *           It will not be called in the final version of the wordfreq
 *           program.
 *           Still LEAVE IT AS-IS:  WE WILL USE IT FOR TESTING.
 */
void WordFreqLinkedList::debugPrint()
{
        Node *curr = front;

        cout << "[";
        while (curr != nullptr) {
                cout << "{" << curr->data.word << ", "
                     << curr->data.freq << "}";
                if (curr->next != nullptr)
                        cout << ", ";
                curr = curr->next;
        }
        cout << "]";
}
