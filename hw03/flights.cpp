// flights.cpp
//
// Purpose: rewrite the original code using several functions
//
// By: Joel Brandinger
//
// Date: 26 February 2021
//

#include <iostream>

using namespace std;

string layover(int a, int b, int c, int d);
string total(int e, int f, int g, int h);

int main()
{
    
        int depart_hour1, depart_min1, arrive_hour1, arrive_min1;
        int depart_hour2, depart_min2, arrive_hour2, arrive_min2;
        
        cout << "Flight 1: ";
        cin >> depart_hour1 >> depart_min1 >> arrive_hour1 >> arrive_min1;
        
        cout << "Flight 2: ";
        cin >> depart_hour2 >> depart_min2 >> arrive_hour2 >> arrive_min2;
        
        layover(arrive_hour1, arrive_min1, depart_hour2, depart_min2);
        
        total(depart_hour1, depart_min1, arrive_hour2, arrive_min2);        
    
}

string layover(int a, int b, int c, int d)
{
        int depart, arrive, layover_hr, layover_min;
        string layover;
    
        arrive = (a * 60) + b;
        depart = (c * 60) + d;
        
        if (depart < arrive) {
                depart = depart + 1440;
        } else {
                depart = depart;
        }
    
        layover_hr = (depart - arrive) / 60;
        layover_min = (depart - arrive) % 60;
        
        cout << "Layover: " << layover_hr << " hr " << layover_min 
             << " min" << endl;  
    
    return layover;
}

string total(int e, int f, int g, int h)
{

        int take_off, land, duration_hr, duration_min;
        string total;
        
        land = (g * 60) + h;
        take_off = (e * 60) + f;
        
        if (land < take_off) {
                land = land + 1440;
        } else {
                land = land;
        }
        
        duration_hr = (land - take_off) / 60;
        duration_min = (land - take_off) % 60;
        
        cout << "Total: " << duration_hr << " hr " << duration_min 
             << " min" << endl;  
    
    return total;        
}