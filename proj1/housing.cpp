// housing.cpp version
//
// Purpose: Read data from a set of houses and report to the user proper
//          information regarding the requested house lot.
//                     
// By: Joel Brandinger
//
// Date: 31 March 2021
//

#include <iostream>
#include <fstream>

using namespace std;

const int ROWS = 50;
const int COLS = 20;

struct House {
    
        bool   no_house_here;
        int    id;
        string lot_code; 
        float  price;
        int    number_of_bedrooms;
        string color;
        string availability;
};

House read_one_house(ifstream& input_file);
void print_house(House h);
int col_from_lot(string lot);
int row_from_lot(string lot);
void fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]);
bool read_all_house_data(string filename, House all_houses[ROWS][COLS]);
bool is_available(int house_id, House all_houses[ROWS][COLS]);
int matching_houses(float max_price, string desired_color, 
                    int desired_bedrooms, House all_houses[ROWS][COLS],
                    House results[ROWS * COLS]);
int num_neighbors(int house_id, House all_houses[ROWS][COLS]);
int rent_house(int house_id, House all_houses[ROWS][COLS]);
void run_command_loop(House all_houses[ROWS][COLS]);
string get_action();
House find_house(int house_id, House all_houses[ROWS][COLS]);
int max(int a, int b);
int min(int a, int b);
void print_availability(House all_houses[ROWS][COLS]);
void print_matching_houses(House all_houses[ROWS][COLS]);
void print_neighbors(House all_houses[ROWS][COLS]);
void print_house_rental(House all_houses[ROWS][COLS]);

#include "housing_hooks.hpp"

int main(int argc, char *argv[])
{
        House all_houses[ROWS][COLS];
        fill_with_no_houses(ROWS, COLS, all_houses);
        
        if (argc != 2) {
            cerr << "Filename missing on command line"
                 << endl;
            return 1;
        }
        
        string filename = argv[1];
        
        ifstream input_file;
        input_file.open(filename);
        
        if (not input_file.is_open()) {
            cerr << "Could not open file: "
                 << filename << endl; 
            return 1;
        }
        
        read_all_house_data(filename, all_houses);
        
        run_command_loop(all_houses);
        
        input_file.close();

        return 0;
}

/* read_one_house
 * parameters: input file
 * purpose: read information about one house from data file
 * returns: a house struct for the line read
 */
House read_one_house(ifstream& input_file) {
    
        House one_house;
        
        one_house.no_house_here = false;
        input_file >> one_house.id;
        input_file >> one_house.lot_code;
        input_file >> one_house.price;
        input_file >> one_house.number_of_bedrooms;
        input_file >> one_house.color;
        input_file >> one_house.availability;
        
        return one_house;
}

/* print_house
 * parameters: a house struct
 * purpose: print information regarding a given house
 * returns: void. prints relevant info
 */
void print_house(House h) {    
        
        if (h.no_house_here == true) {
            cout << "No house" << endl;
        } else {
            cout << "Id: " << h.id << " Lot: " << h.lot_code 
                 << " Color: " << h.color << " Price: " << h.price 
                 << " Bedrooms: " << h.number_of_bedrooms << " Available: ";
                 
                 if (h.availability == "booked") {
                     cout << "No" << endl;     
                 } else {
                     cout << "Yes" << endl;
                 }     
        }
}

/* col_from_lot
 * parameters: lot code from a house ex. A1
 * purpose: read first character in string and return corresponding number
 * returns: int corresponding to proper column in house grid
 */
int col_from_lot(string lot) {
        
        int col = lot[0] - 65;
        
        return col;
}
/* row_from_lot
 * parameters: lot code from a house ex. A1
 * purpose: read remaining characters from string and return number that is
 *          one less
 * returns: int corresponding to proper row in house grid
 */
int row_from_lot(string lot) {

        int row = 0;
    
        for (size_t i = 1; i < lot.length(); i++) {
        
            if (lot[i] >= 48 && lot[i] <= 57) {
                row = row * 10 +(lot[i] - 48);
        }    
    } 
        return row - 1;              
}

/* fill_with_no_houses
 * parameters: rows, columns, and array of house structs
 * purpose: set each house lot in array as having no house 
 * returns: void. fills house grid with empty houses
 */
void fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]) {
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                all_houses[i][j].no_house_here = true;
            }        
        }              
}

/* read_all_house_data
 * parameters: file to be read and array of house structs
 * purpose: read each line of houses in the data file and then place the 
 *          read house in the appropraite row and column of the all_houses
 *          array according to its lot code
 * returns: true if the house was read
 */
bool read_all_house_data(string filename, House all_houses[ROWS][COLS]) {

        ifstream input_file;
        input_file.open(filename);
    
        if (not input_file.is_open()) {
            cerr << "Could not open file: "
                 << filename << endl; 
            return false;
    }
    
        int num_houses;
        input_file >> num_houses;
        House house_read;
        
        for (int i = 0; i < num_houses; i++) {
        
            house_read = read_one_house(input_file);
        
            int row = row_from_lot(house_read.lot_code);
            int col = col_from_lot(house_read.lot_code);
         
            all_houses[row][col] = house_read;
        
        }                
    
        input_file.close();
    
        return true;
}

/* is_available
 * parameters: house id and array of houses
 * purpose: checks to see if inputted house id is available.
 * returns: true if house is available and false otherwise
 */
bool is_available(int house_id, House all_houses[ROWS][COLS]) {
        
        return find_house(house_id, all_houses).availability == "available";
                
}

/* matching_houses
 * parameters: max price, desired color, desired number of bedrooms, 
 *             all_houses array, and array of house results.
 * purpose: go through housing array and find every house that matches the
 *          input for price, color, and number of bedrooms. Copy each 
 *          matching house into the results array.
 * returns: number of matching houses 
 */
int matching_houses(float max_price, string desired_color, 
                    int desired_bedrooms, House all_houses[ROWS][COLS],
                    House results[ROWS * COLS]) {
                        
        int num_matching_houses = 0;
            
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (all_houses[i][j].price <= max_price and 
                    all_houses[i][j].color == desired_color and 
                    all_houses[i][j].number_of_bedrooms >= desired_bedrooms) {
                        
                        results[num_matching_houses++] = all_houses[i][j];
                    }
            }
        }    
    return num_matching_houses;                        
}

/* num_neighbors
 * parameters: house id and array of houses 
 * purpose: counts how many neighbors the given house id has 
 * returns: number of neighbors 
 */
int num_neighbors(int house_id, House all_houses[ROWS][COLS]) {
    
        House h = find_house(house_id, all_houses);
        
        if (h.no_house_here) {
            return 0;
        }
        
        int row = row_from_lot(h.lot_code);
        int col = col_from_lot(h.lot_code);
        
        int neighbors = 0;
        
        for (int i = max(0, row - 1); i <= min(row + 1, ROWS); i++) {
            for (int j = max(0, col - 1); j <= min(col + 1, COLS); j++) {
                if ((i != row and j != col)
                    and all_houses[i][j].availability == "booked"
                    and all_houses[i][j].no_house_here == false) {
                        neighbors++;
                    }
            }
        }            
    return neighbors;    
}

/* rent_house
 * parameters: house id and array of houses  
 * purpose: attempts to rent an available house and updates array of 
 *          houses to show that the house has been booked
 * returns: if given house does not exist, return 0. If given house exists 
 *          and is available, return 1. If house exists but is unavailable,
 *          return 2.
 */
int rent_house(int house_id, House all_houses[ROWS][COLS]) {
    
        House h = find_house(house_id, all_houses);
        
        if (h.id < 0) {
            return 0;
        }
        
        int row = row_from_lot(h.lot_code);
        int col = col_from_lot(h.lot_code);
        
        if (all_houses[row][col].availability == "available") {
            all_houses[row][col].availability = "booked";
            return 1;
        } else {
            return 2;
        }    
}

/* run_command_loop
 * parameters: array of houses  
 * purpose: repeatedly gets user input and runs appropriate command 
 * returns: void
 */
void run_command_loop(House all_houses[ROWS][COLS]) {

            while (true) {
            
            string action; 
            action = get_action();

            if (action == "q") {
                return;
            } else if (action == "a") {
                print_availability(all_houses);    
            } else if (action == "m") {
                print_matching_houses(all_houses);
            } else if (action == "n") {
                print_neighbors(all_houses);
            } else if (action == "r") {
                print_house_rental(all_houses);
            } else {
                cout << "Unknown command " << action << endl;
            }
        }
}

/* get_action
 * parameters: void 
 * purpose: gets user input 
 * returns: user input 
 */
string get_action() {
    
        string action;
        
        cout << "query->";
        cin >> action;
        
        return action;    
}

/* find_house
 * parameters: house id and array of houses 
 * purpose: find corresponding house given house id
 * returns: a house struct 
 */
House find_house(int house_id, House all_houses[ROWS][COLS]) {
    
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (all_houses[i][j].id == house_id) {
                    return all_houses[i][j];
                }
            }
        }
        
        House h;
        h.no_house_here = true;
        h.id = -1;
        return h;
}

/* max 
 * parameters: two integers, a and b
 * purpose: finds the larger of two ints. Useful for determing wether a house
 *          sits on the border of the grid 
 * returns: max int 
 */
int max(int a, int b) {
    
        if (a > b) {
            return a;
        } else {
            return b;
        }    
}

/* min  
 * parameters: two integers, a and b
 * purpose: finds the smaller of two ints. Useful for determing wether a house
 *          sits on the border of the grid 
 * returns: min int 
 */
int min (int a, int b) {
    
        if (a < b) {
            return a;
        } else {
            return b;
        }    
}

/* print_availability 
 * parameters: all houses array 
 * purpose: checks availability of given house and prints results
 * returns: void, only prints availability
 */
void print_availability(House all_houses[ROWS][COLS]) {
    
        int house_id;
        
        cin >> house_id;
        if (is_available(house_id, all_houses)) {
            cout << "House " << house_id << " is available" << endl;
        } else {
            cout << "Sorry, House " << house_id << " is not available"
                 << endl;
             }    
}

/* print_matching_houses
 * parameters: none 
 * purpose: checks to see which houses match the requested characteristics
 *          and prints the corresponding houses 
 * returns: void, only prints matching houses 
 */
void print_matching_houses(House all_houses[ROWS][COLS]) {
    
        float max_price;
        string desired_color;
        int desired_bedrooms, num_matching_houses;
        House results[ROWS * COLS];
        
        cin >> max_price >> desired_color >> desired_bedrooms;
        
        num_matching_houses = matching_houses(max_price, desired_color, 
                                  desired_bedrooms, all_houses,results);
        
        cout << "Matching Houses:" << endl;
        for (int i = 0; i < num_matching_houses; i++)
                print_house(results[i]);    
}

/* print_neighbors 
 * parameters: all houses array 
 * purpose: prints how the number of neighbors for a given house id 
 * returns: void, only prints neighbors 
 */
void print_neighbors(House all_houses[ROWS][COLS]) {
    
        int house_id, neighbors;
    
        cin >> house_id;
    
        neighbors = num_neighbors(house_id, all_houses);
    
        if (neighbors == 0) {
            cout << "You have no neighbors, practice your drums!" << endl;
        } else {
            cout << "You have " << neighbors << " neighbors!" << endl;
        }
    
}

/* print_house_rental
 * parameters: all houses array 
 * purpose: prints wether or not the house was able to be rented 
 * returns: void, only prints house rental situation 
 */
void print_house_rental(House all_houses[ROWS][COLS]) {
        
        int house_id, rental_situation;
        
        cin >> house_id;
        
        rental_situation = rent_house(house_id, all_houses);
        
        if (rental_situation == 0) {
            cout << "You can't rent a house that doesn't exist, but good try"
                 << endl;
        } else if (rental_situation == 1) {
            cout << "Congrats, you rented a house!" <<
                    " Hope your door knobs don't fall off" << endl;
        } else {
            cout << "Too late...i hear the dumpster behind" <<
                    " hill has some spaces open" << endl;
        }    
}
