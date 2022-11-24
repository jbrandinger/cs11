//*********************************************************************
//                       animaldb program
//  Author: Joel Brandinger
//  Date: 14 April 2021 
//  Purpose: Read command line to determine user query. Either print all 
//           animals in the desired database or conduct a classification 
//           report and only print the members of that classification.
//  Known bugs: none
//  Testing performed: Using both the small and large animal database file
//                     the program was run with no classification and every 
//                     animal in the file appeared to print. Then classications
//                     were tested with both the small and large database.
//                     Each trial properly printed the animals with that 
//                     classification and when a non existent classification
//                     was input, the proper response was printed.
//*********************************************************************

#include <fstream>
#include <iostream>

using namespace std;

#include "Animal.h"
#include "Animal_Array_List.h"

// Command line string used to ask for classification
// report.
const string CLASSIFICATION_CMD = "classification";

bool parse_cmdline(int argc, char *argv[], string *filename,
                   string *cmd, string *classification);
void print_usage_message();
void initialize_DB(ifstream& file, Animal_Array_List *all_animals);
Animal get_animal_from_file(ifstream& input_file);
void  do_classification_report(string classification,
                               Animal_Array_List *all_animals);

int main(int argc, char *argv[])
{
        string filename; 
        string cmd; 
        string classification;

        // Get filename, cmd, classification from command line
        if (not parse_cmdline(argc, argv, &filename, &cmd, &classification)) {
                return 1;
        }

        // Open the file
        ifstream file;
        file.open(filename);
        if (not file.is_open()) {
            cerr << "File " << filename << " could not be opened!" 
                      << endl;
            return 1;
        }
        
        Animal_Array_List all_animals;
        
        initialize_DB(file, &all_animals);
        
        if (cmd == CLASSIFICATION_CMD) {
            do_classification_report(classification, &all_animals);
        } else {
            all_animals.print();
        }

        file.close();
        return 0;
}

//*************************************************************
//                     do_classification_repot
//  Reads animal data from the given file, and stores it in the array list
//  Parameters:  classification: class to search for, e.g. fish
//               Pointer to a list of animals to be searched
//  Outputs:     Prints a list of matching animals 
//      REPLACE THE ENTIRE BODY OF THIS FUNCTION WITH YOUR
//      CODE.
//*************************************************************

void  do_classification_report(string classification,
                               Animal_Array_List *all_animals) 
{
        int matching_animals = 0;
        
        for (int i = 0; i < all_animals->num_animals(); i++) {
            if (all_animals->animal_at(i).classification() == classification) {
                all_animals->animal_at(i).print();
                matching_animals++;
            }
        }
        if (matching_animals == 0) {
            cout << "No animals with classification: computer-geek" << endl;
        }        
}

//*************************************************************
//                         initialize_DB
//  Reads animal data from the given file, and stores it in the array list
//  Parameters:  Filename to read data from, 
//               Pointer to a list to store the animals in
//  Outputs:     None
//  Effects:     Fills the passed list with animals, adding them to the back
//          THIS FUNCTION IS PROVIDED FOR YOU, DO NOT CHANGE IT.
//*************************************************************
void initialize_DB(ifstream& file, Animal_Array_List *all_animals)
{
        Animal a = get_animal_from_file(file);
        while (not file.eof()) {
            all_animals->add(a);
            a = get_animal_from_file(file);
        }
}

// Do not modify the follwoing function
Animal get_animal_from_file(ifstream& input_file)
{
        Animal a(input_file);
        return a;
}

//*************************************************************
//                   parse_cmdline
//        Check that command line arguments are correct.
//        If not, print usage information to cerr and return false.
//        If OK return true and set values for filename, cmd
//        and classification.
//      THIS FUNCTION IS PROVIDED FOR YOU, DO NOT CHANGE IT.
//*************************************************************
bool parse_cmdline(int argc, char *argv[], string *filename,
                   string *cmd, string *classification)
{
        bool retval = true;
        
        if ( not ((argc == 2) or (argc == 4)) ) {
                retval = false;
        } else {
                // Right number of arguments supplied, surely first is filename
                *filename =  argv[1];
        }

        // Check for long commands
        if (argc == 4 ) {
                *cmd = string(argv[2]);
                // The only command we support is classification
                if (*cmd != CLASSIFICATION_CMD) {
                        retval = false;
                }
                *classification = string(argv[3]);
        }
        if (not retval) {      
                print_usage_message();
        }
        return retval;
}

void print_usage_message()
{
        cerr << "Usage: animaldb <animal_db_filename>" << endl;
        cerr << "            -- or --" << endl;
        cerr << "Usage: animaldb <animal_db_filename> "
                "classification <animal-class>" << endl;
        cerr << endl;
        cerr << "Typical classifications: amphibian, bird, "
                "crustacean, fish, "
                "insect, mammal, reptile" << endl;
}
