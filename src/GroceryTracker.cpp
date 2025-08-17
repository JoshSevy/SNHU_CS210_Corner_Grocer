//
// Author: Joshua Sevy
// Created on: 8/16/25
//

#include "./GroceryTracker.h"
#include <fstream>
#include <iostream>
using namespace std;

/**
 * @description Constructor for GroceryTracker class.
 * @param dataInputPath
 * @param backUpPath
 */
GroceryTracker::GroceryTracker(const string &dataInputPath, const string &backUpPath)
    : inputFilePath(dataInputPath), backUpDataPath(backUpPath) {
    // Initialize the frequency map and load input data on class initialization
    loadInputData();
}

/**
 * @description Returns the count of a specific item in the frequency map.
 * @param item The item to get the count for.
 * @return The count of the item, or 0 if the item is not found.
 */
int GroceryTracker::getCount(const string &item) const {
    auto singleItem = frequencyMap.find(item);
    return singleItem == frequencyMap.end() ? 0 : singleItem->second;
}

/**
 * @description Checks if the frequency map has any data.
 * @return True if the frequency map is not empty, false otherwise.
 */
bool GroceryTracker::hasData() const {
    return !frequencyMap.empty(); // Check if the frequency map has any data
}

/**
 * @description Destructor for GroceryTracker class.
 */
bool GroceryTracker::loadInputData() {
    ifstream dataIn(inputFilePath);
    if (!dataIn) {
        cout << "Error opening file " << inputFilePath << endl;
        return false;
    }
    frequencyMap.clear(); // Clear the map before loading new data
    string line; // Using getLine to read each line for single work items and multiple words per line
    while (getline(dataIn, line)) {
        // TODO: Add string trimming to remove leading/trailing whitespace
        if (line.empty() || line[0] == '#') {
            continue; // Skip empty lines and comments
        }
        if (!line.empty()) {
            frequencyMap[line]++; // Increment the count for the item
        }
    }

    dataIn.close(); // Close the file after reading
    // TODO: Add writing to the frequency map to the backup file
    writeFrequencyData();
    return true;
}

/**
 * @description Prints all items and their counts in the frequency map.
 */
void GroceryTracker::printAll() const {
    if (frequencyMap.empty()) {
        cout << "No data available." << endl;
        return;
    }
    for (const auto &pair : frequencyMap) {
        cout << pair.first << ": " << pair.second << endl; // Print each item and its count
    }
}

/**
 * @description Prints a histogram of the frequency map using the specified symbol.
 * @param symbol The character to use for the histogram bars (default is '*').
 */
void GroceryTracker::printHistogram(char symbol) const {
    if (frequencyMap.empty()) {
        cout << "No data available." << endl;
        return;
    }
    for (const auto &pair : frequencyMap) {
        cout << pair.first << ": ";
        for (int i = 0; i < pair.second; ++i) {
            cout << symbol; // Print the histogram using the specified symbol
        }
        cout << endl;
    }
}

/**
 * @description Writes the frequency data to the backup file.
 * This function iterates through the frequency map and writes each item and its count to the backup file.
 */
void GroceryTracker::writeFrequencyData() const {
    ofstream dataOut(backUpDataPath);
    if (!dataOut) {
        cout << "Error opening file " << backUpDataPath << endl;
        return;
    }
    for (const auto &pair : frequencyMap) {
        dataOut << pair.first << ": " << pair.second << endl; // Write each item and its count
    }
    dataOut.close(); // Close the file after writing
}
