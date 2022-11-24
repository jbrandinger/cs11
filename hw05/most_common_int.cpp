// most_common_int.cpp
//
// Purpose: identify most common integer in an array of integers
//
// By: Joel Brandinger
//
// Date: 16 March 2021

#include <iostream>

using namespace std;

int most_common_int(int numbers[], int length);
void testing(int numbers[], int length, int correct);
void print_array (int numbers[], int length);

int main()
{
        int array1_len = 10;
        int array1[] = {1, 4, 5, 2, 1, 9, 8, 1, 7, 6};
        
        int array2_len = 6;
        int array2[] = {99, 20, 99, 1, 3, 9};
        
        int array3_len = 4;
        int array3[] = {7, 7, 9, 9};
        
        int array4_len = 7;
        int array4[] = {1, 86, 3, 86, 21, 21, 86};
        
        testing(array1, array1_len, 1); 
        testing(array2, array2_len, 99);
        testing(array3, array3_len, 7);
        testing(array4, array4_len, 86);
        
        return 0;        
}

/* most_common_int
* Purpose: Sort through array and each time a number appears add one to an
*          array of all zeros in the respectice number's slot. Next loop
*          through all the counts and find the whichever number appeared 
*          most times.
* Parameters: array of numbers and length of the array.
* Returns: number that appeared most frequently.
*/
int most_common_int(int numbers[], int length)
{
        int max_num = 0;
        int count[1000] = {0};
        
        for (int i = 0; i < length; i++) {
            ++count[numbers[i]];
            }
        
        for (int i = 0; i < 1000; i++) {
            
            if (count[i] > max_num) {
                max_num = count[i];
            }    
        }
        for (int i = 0; i < 1000; i++) {
            if (count[i] == max_num) {
                return i;
            }
        }   
        return -1; 
}

/* 
* Purpose: Test the result of most_common_int and see if it matches
*          the expected result. 
* Parameters: array of numbers, length of the array, and correct answer.
* Returns: Void, prints out appropriate results.
*/
void testing(int numbers[], int length, int correct)
{
        if (most_common_int(numbers, length) == correct) {
            cout << "TESTING:";
            print_array(numbers, length);
            cout << "SUCCESS: " << correct << endl;
        } else {
            cout << "TESTING:";
            print_array(numbers, length);
            cout << "FAILURE: " << most_common_int(numbers, length) << endl;
        }    
}

/* 
* Purpose: Print the array of numbers that is being tested.
* Parameters: The array of numbers and its length.
* Returns: Void, prints the array.
*/
void print_array(int numbers[], int length)
{
        for (int i = 0; i < length; i++) {
            cout << " " << numbers[i];
        }
        cout << endl;
}
    
