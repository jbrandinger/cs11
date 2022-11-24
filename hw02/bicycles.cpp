// Bicycles.cpp
//
// Purpose: tell user how many bikes they can make given a certain
//          number of wheels, frames, and links
// 
// By: Joel Brandinger
// 
// Date: 21 February 2021
//

#include <iostream>

using namespace std;

string singular(int items, string word);
int get_bikes(int wheels, int frames, int links);
int remaining_parts(int parts, int parts_per_bike, int bikes);

int main()
{
  
        int w1, f1, l1, w2, f2, l2;
        
// w1, f1, l1 = given parts
// w2, f2, l2 = number of bikes the given part can make 
  
  
        cout << "Enter the number of wheels: ";
        cin >> w1;
          
        cout << "Enter the number of frames: ";
        cin >> f1;
        
        cout << "Enter the number of links: ";
        cin >> l1;
        
        w2 = w1 / 2;
        f2 = f1 / 1;
        l2 = l1 / 50;
        
        int bikes = get_bikes(w2, f2, l2);
        
        cout << "You can make " << bikes << " " << singular(bikes, "bike")
             << ". ";
            
        cout << "There are " << remaining_parts(w1, 2, bikes) << " "
             << singular(remaining_parts(w1, 2, bikes), "wheel") << ", "
             << remaining_parts(f1, 1, bikes) << " "
             << singular(remaining_parts(f1, 1, bikes), "frame") << ", "
             << remaining_parts(l1, 50, bikes) << " "
             <<  singular(remaining_parts(l1, 50, bikes), "link") 
             << " leftover." << endl;
      
        return 0;      
}

string singular(int items, string word)
{
    if (items == 1) {
      return word;
    }
    return word + "s";
}

int get_bikes(int wheels, int frames, int links)
{
    int lowest = wheels;
    
    if (frames < lowest) {
      lowest = frames;
    }
    
    if (links < lowest) {
      lowest = links;
    }
    
    return lowest;
}

int remaining_parts(int parts, int parts_per_bike, int bikes)
{
    int parts_used = parts_per_bike * bikes;
    return parts - parts_used;
}
