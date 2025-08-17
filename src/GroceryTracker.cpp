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

int GroceryTracker::getCount(const string &item) const {
    auto singleItem = frequencyMap.find(item);
    return singleItem == frequencyMap.end() ? 0 : singleItem->second;
}

bool GroceryTracker::hasData() const {
    return !frequencyMap.empty(); // Check if the frequency map has any data
}

/**
 * @description Destructor for GroceryTracker class.
 */
bool GroceryTracker::loadInputData() {
    ifstream data(inputFilePath);
    if (!data) {
        cout << "Error opening file " << inputFilePath << endl;
        return false;
    }
    frequencyMap.clear(); // Clear the map before loading new data
    string line; // Using getLine to read each line for single work items and multiple words per line
    while (getline(data, line)) {
        // TODO: Add string trimming to remove leading/trailing whitespace
        if (line.empty() || line[0] == '#') {
            continue; // Skip empty lines and comments
        }
        if (!line.empty()) {
            frequencyMap[line]++; // Increment the count for the item
        }
    }

    data.close(); // Close the file after reading
    // TODO: Add writing to the frequency map to the backup file
    writeFrequencyData();
    return true;
}

void GroceryTracker::printAll() const {
    if (frequencyMap.empty()) {
        cout << "No data available." << endl;
        return;
    }
    for (const auto &pair : frequencyMap) {
        cout << pair.first << ": " << pair.second << endl; // Print each item and its count
    }
}

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

void GroceryTracker::writeFrequencyData() const {
    ofstream data(backUpDataPath);
    if (!data) {
        cout << "Error opening file " << backUpDataPath << endl;
        return;
    }
    for (const auto &pair : frequencyMap) {
        data << pair.first << ": " << pair.second << endl; // Write each item and its count
    }
    data.close(); // Close the file after writing
}
