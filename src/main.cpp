//
// Author: Joshua Sevy
// Created on: 8/16/25
// Description: Main entry point for the Grocery Tracker application.
// This program initializes the GroceryTracker class and prepares for user interaction through the Menu class.
//

#include <iostream>
#include "GroceryTracker.h"
#include "Menu.h"

using namespace std;

int main() {
    GroceryTracker groceryTracker("data/CS210_Project_Three_Input_File.txt", "data/frequency.dat");
    // Error logging for file paths
    if (!groceryTracker.loadInputData()) {
        cerr << "Failed to load input data. Exiting program." << endl;
        return 1; // Exit with an error code if data loading fails
    }
    // Error handling for empty frequency map
    if (!groceryTracker.hasData()) {
        cerr << "No data loaded. Exiting program." << endl;
        return 1; // Exit with an error code if no data is available
    }

    const Menu menu(groceryTracker);
    menu.run();
    return 0;
}