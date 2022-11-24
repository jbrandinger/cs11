//*********************************************************************
//                       Animal.cpp      
//        Member function and constructor implementations for 
//        the Animal class.
//  Author: Joel Brandinger
//  Date: 13 April 2021 
//  Purpose: Create a class "Animal" that contains features of the animal.
//           Starts by intitializing each feature as "UNINITIALIZED" then 
//           changes it accordingly as the file is read.
//  Known bugs: none
//  Testing performed: In main, a variable "a" of type Animal was declared.
//                     The file was read into "a" and a.print() was called.
//                     The first line of short_amimals_db properly printed.   
//*********************************************************************

#include <fstream>
#include <iostream>

using namespace std;

#include "Animal.h"

//                        Animal::Animal
//       This no arguments constructor is called, among other situations
//       when an array of Animals is created.
Animal::Animal()
{
        m_name           = "UNINITIALIZED";
        m_origin         = "UNINITIALIZED";
        m_diet           = "UNINITIALIZED";
        m_ear_size       = "UNINITIALIZED";
        m_classification = "UNINITIALIZED";
}

Animal::Animal(ifstream& input_file)
{        
        input_file >> m_name;
        input_file >> m_origin;
        input_file >> m_diet;
        input_file >> m_ear_size;
        input_file >> m_classification;     
}

// *************************************************************************
//                   Accessor functions
// *************************************************************************
string Animal::name()
{
        return m_name;   
}

string Animal::origin()
{
        return m_origin;  
}

string Animal::diet()
{
        return m_diet; 
}

string Animal::ear_size()
{        
        return m_ear_size;
}

string Animal::classification()
{
        return m_classification;
}

//                        Animal::print
//       Print all information about the animal to cout
void Animal::print()
{
        cout << "name=" << m_name 
             << " origin=" << m_origin
             << " diet=" << m_diet
             << " ear_size=" << m_ear_size
             << " classification=" << m_classification
             << endl;
}
