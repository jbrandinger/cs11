/*
* COMP11
* Spring 2021
* students.cpp
*
* Purpose: input student ID and print out information for student.
* 
* By: Joel Brandinger
*/

#include <iostream>
#include <string>

using namespace std;

// declare the Student struct
struct Student {
    int    id;
    string firstName;
    char   lastInitial;
    float  gpa; 
};

const int TOTAL_STUDENTS = 10;


// Function Prototypes
int  find_student(int id, Student students[], int num_students);
void print_student(int index, Student students[]);
int get_input();


int main() {

    Student students [TOTAL_STUDENTS] = {
        {268, "Dana",     'J', 4.0},
        {123, "Rachel",   'G', 3.42},
        {126, "Sam",      'B', 3.8},
        {431, "Keisha",   'M', 3.9},
        {231, "Joe",      'W', 2.7},
        {272, "Isabella", 'U', 3.73},
        {112, "Sook-Hee", 'E', 3.54},
        {289, "Molly",    'C', 3.6},
        {345, "Talia",    'K', 3.63},
        {228, "Jackson",  'P', 3.33}
    };

    print_student(find_student(get_input(), students, 
                  TOTAL_STUDENTS), students);

    return 0;
}

/* 
* Purpose: Print the sudents name anf GPA given their index in the array.
* Parameters: Students index number and array of students. 
* Returns: Void, prints relevant info.
*/
void print_student(int index, Student students[])
{
    if (index < 0) {
        cout << "Student not found." << endl;
    } else {
    cout << "Name: " << students[index].firstName << " "
         << students[index].lastInitial << endl;
    cout << "GPA: " << students[index].gpa << endl; 
    }
}

/* 
* Purpose: Sort through array of students to find the matching id with the
*          input.
* Parameters: Student's id, array of students, and total number of students
*             to sort through.
* Returns: the index number of the student.
*/
int find_student(int id, Student students[], int num_students)
{
    for (int i = 0; i < num_students; i++) {
        if (id == students[i].id) {
            return i;
        }
    }
    return -1;
}

/* 
* Purpose: Get input for student ID
* Parameters: N/A
* Returns: Student's ID number.
*/
int get_input()
{
    int id;
    
    cin >> id;
    
    return id;
}

