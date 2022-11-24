/* rps.cpp
 * 
 * Purpose: Have the user play rock, paper, scissors against
 *          the computer
 * 
 * By: Joel Brandinger
 *
 * Date: 22 February 2021
 */ 
#include <iostream>

// The following are for srand() and time()
// for random numbers. Leave them 
// in your program.
#include <cstdlib>
#include <ctime>

using namespace std;

string computers_choice (int num);
string users_choice (string input);
string determine_winner(string computer, string user);
 
int main()
{
        srand(time(nullptr));

        int num = rand() % 3;
        string input;
        string computers_move = computers_choice(num);
        
        cout << "Enter rock (r), paper (p), or scissors (s): ";
        cin >> input;
        
        string user_move = users_choice(input);
        
        cout << determine_winner(computers_move, user_move);
            
            if (user_move == computers_move) {
                cout << " The computer also chose ";
            } else {
                cout << " The computer chose ";
            }
            cout << computers_move << "." << endl;
        
        return 0;
}

string computers_choice (int num)
{
    string computer;
    
        if (num == 0){
                computer = "rock";
        }
        if (num == 1){
                computer = "paper";
        }
        if (num == 2){
                computer = "scissors";
        }
        
        return computer;    
}

string users_choice (string input)
{
    string user;
    
    if (input == "r") {
            user = "rock";
    }
    else if (input == "p") {
            user = "paper";
    }
    else {
            user = "scissors";
    }
    
    return user;    
}

string determine_winner(string computer, string user)
{
    string draw, computerwin, userwin, result;
    
    draw = "It's a tie.";
    computerwin = "You lost.";
    userwin = "You won!";
    
    if (computer == user){
            result = draw;
    }
    else if (computer == "rock" && user == "scissors"){
            result = computerwin;
    }
    else if (computer == "rock" && user == "paper"){
            result = userwin;
    }
    else if (computer == "paper" && user == "rock"){
            result = computerwin;
    }
    else if (computer == "paper" && user == "scissors"){
            result = userwin;
    }
    else if (computer == "scissors" && user == "paper"){
            result = computerwin;
    }
    else {
            result = userwin;
    }
    
    return result;
    
}
