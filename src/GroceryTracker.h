//
// Author: Joshua Sevy
// Created on: 8/16/25
//

#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <map>
#include <string>

using namespace std;

class GroceryTracker {
public:
    GroceryTracker(const string &dataInputPath, const string &backUpPath);
    // TODO: Do we need a destruction function?
    // ~GroceryTracker();

    int getCount(const string& item) const; // Returns the count of a specific item in the frequency map
    bool hasData() const; // Checks if the frequency map has any data
    bool loadInputData(); // Loads data from the input file into the frequency map
    void printAll() const; // Prints all items and their counts in the frequency map
    void printHistogram(char symbol = '*') const; // Prints a histogram of the frequency map using the specified symbol
    void writeFrequencyData() const; // Writes the frequency data to the backup file

private:
    map<string, int> frequencyMap;
    string inputFilePath;
    string backUpDataPath;
};

#endif //GROCERY_TRACKER_H
