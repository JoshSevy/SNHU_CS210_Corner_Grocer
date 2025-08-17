//
// Author: Joshua Sevy
// Created on: 8/16/25
//

#ifndef MENU_H
#define MENU_H

class GroceryTracker;

class Menu {
public:
    explicit Menu(GroceryTracker &tracker); // Constructor that takes a reference to a GroceryTracker object
    void run() const; // Runs the menu loop until the user chooses to exit

private:
    GroceryTracker& tracker;
    void doSearch() const; // Searches for an item in the frequency map
    void doPrintAll() const; // Prints all items and their counts
    void doHistogram() const; // Prints a histogram of the frequency map
    int promptChoice() const; // Prompts the user for a menu choice
};

#endif //MENU_H
