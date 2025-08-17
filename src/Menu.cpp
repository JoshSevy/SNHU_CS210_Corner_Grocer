//
// Author: Joshua Sevy
// Created on: 8/16/25
//

#include "./Menu.h"
#include "./GroceryTracker.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

Menu::Menu(GroceryTracker &trackerClass) : tracker(trackerClass) {}

void Menu::doSearch() const {
    cout << "Enter the item to search for: ";
    string query;
    getline(cin, query);
    // Add trim utility function for whitespace removal
    tracker.getCount(query) > 0 ?
        cout << "Item found: " << query << " with count: " << tracker.getCount(query) << endl :
        cout << "Item not found: " << query << endl;
}

void Menu::doPrintAll() const {
    tracker.printAll();
}

void Menu::doHistogram() const {
    tracker.printHistogram('*'); // Default symbol for histogram
}

int Menu::promptChoice() const {
    int choice;
    // TODO: Add UI improvements for better user experience
    cout << "\n=============== Corner Grocer Menu ===============\n"
            << "1. Search item frequency\n"
            << "2. Print all frequencies\n"
            << "3. Print histogram\n"
            << "4. Exit\n"
            << "Please enter your choice (1-4): ";

    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid choice. Please enter a number between 1 and 4: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character from the input buffer
    return choice;
}

void Menu::run() const {
    if (!tracker.hasData()) {
        cout << "No data available. Please load input data first." << endl;
    }

    while (true) {
        int choice = promptChoice();
        switch (choice) {
            case 1:
                doSearch();
                break;
            case 2:
                doPrintAll();
                break;
            case 3:
                doHistogram();
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                return; // Exit the menu loop
            default:
                // Invalid should be caught by promptChoice
                // but just in case, we handle it here
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}


