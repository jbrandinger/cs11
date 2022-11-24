//*********************************************************************
//                       Animal_Array_list.cpp     
//        Member function and constructor/destructor implementations for 
//        the Animal_Array_List class.
//  Author: Joel Brandinger
//  Date: 13 April 2021 
//  Purpose: Creates a class of an array of the animals. Array starts out with
//           zero animals and a given capacity, but expands as needed to 
//           create more space.
//  Known bugs: none
//  Testing performed: In main, a variable called "all_animals" of class 
//                     Animal_Array_List was created. The file was read and 
//                     each member was stored in the array. The print function 
//                     was then called and all animals in the short db properly
//                     printed.
//*********************************************************************

#include <fstream>
#include <iostream>

using namespace std;

#include "Animal.h"
#include "Animal_Array_List.h"

// Default constructor
Animal_Array_List::Animal_Array_List()
{
        m_capacity = INITIAL_CAPACITY;
        m_num_animals = 0;
        animals = new Animal[m_capacity];        
}

// Destructor: Frees heap-allocated memory associated with arraylist
Animal_Array_List::~Animal_Array_List()
{
        delete [] animals;
}

// Adds a to the back of the list.
// Effects: may expand if necessary
void Animal_Array_List::add(Animal a)
{                
        while (m_num_animals >= m_capacity) {
            expand();
        } 
        animals[m_num_animals] = a;
        m_num_animals++;
}

// Returns the number of Animals currently stored
int Animal_Array_List::num_animals()
{
        return m_num_animals;
}

// Returns the Animal located at position index  
Animal Animal_Array_List::animal_at(int index)
{
        return animals[index];
}

// Doubles the capacity of the animals array
void Animal_Array_List::expand()
{
        m_capacity = m_capacity * 2;
        
        Animal *temp = new Animal[m_capacity];
        
        for (int i = 0; i < m_num_animals; i++) {
            temp[i] = animals[i];
        }
        
        delete [] animals;
        
        animals = temp;
}

//                       print
//       Ask all the Animals in the list to print themselves
void Animal_Array_List::print()
{
        for (int i = 0; i < m_num_animals; i++) {
            animals[i].print();
        }
}
