#include <iostream>
#include "GroceryTracker.h"

using namespace std;

int main() {
    // Initial init testing of GroceryTracker class
    GroceryTracker groceryTracker("CornerGrocerJCS/data/CS210_Project_Three_Input_File.txt", "data/frequency.dat");
    groceryTracker.printAll(); // Print all items and their counts
    groceryTracker.printHistogram('*'); // Print the histogram of the frequency map
    return 0;
}