[![CMake on a single platform](https://github.com/JoshSevy/SNHU_CS210_Corner_Grocer/actions/workflows/cmake-single-platform.yml/badge.svg)](https://github.com/JoshSevy/SNHU_CS210_Corner_Grocer/actions/workflows/cmake-single-platform.yml)

# Corner Grocer Item Tracker

## Module 8 Journal Guide

### Project Summary:

This project is a grocery item tracker for the Corner Grocer, designed to analyze daily purchase records. It offers the ability to look up how often specific items are purchased, display a complete list of item frequencies, generate a text-based histogram of item counts, and exit the program. The goal is to assist the Corner Grocer in optimizing their produce section layout based on customer buying patterns.

---

### Q&A

**What did you do particularly well?**  

One aspect I have improved throughout the projects is my ability to structure code in a way that is both maintainable and readable. I focused on using classes effectively, separating concerns between the GroceryTracker, Menu, and Utils classes. This modular approach makes updates and debugging easier, while also allowing the application to grow without becoming overly complex.

**Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?**  

One thing that I can enhance is better error checking and input validation. It would enhance the program's usability and remove issues caused by incorrect input. For example, verifying that the user enters the correct item name or number would avoid crashes and give a better user experience. Enhancing it would also involve adding logging to track user activity and errors for more convenient debugging and future development.

**Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?**  

The most challenging part was setting up the file I/O so the program could reliably read from the input file and write to frequency.dat. At first, it took some trial and error to get the program to properly recognize the .txt file and handle situations where the file path or name was incorrect. To solve this, I built the functionality step by step, starting with just reading the file before adding item counting and writing results. I leaned on examples from zyBooks for reference and used Microsoft’s official C++ documentation to better understand how file streams work. Going forward, I plan to keep building my support network with reliable references like Microsoft’s documentation and cplusplus.com, which will help me strengthen my skills with C++.

**What skills from this project will be particularly transferable to other projects or course work?**  

A key skill I developed in this project is applying organized object-oriented programming practices in C++. While I already work with object-oriented design in my career, this project allowed me to structure an application into clear, maintainable classes in a language that requires more explicit memory and type management. I also deepened my understanding of C++ data structures, especially how maps can be used for efficient frequency counting and lookups. These skills strengthen both my fluency with C++ and my ability to design scalable, efficient applications for future coursework and professional projects.

**How did you make this program maintainable, readable, and adaptable?**  

I made this program easy to maintain and flexible by maintaining a simple and uniform design. Every class has been given a separate responsibility, so the code remains well-defined and easier to extend or change in the future. I have used descriptive names so that every function or variable is understandable as to why it is there, and comments have been included to clarify the more important aspects of the logic. I have also inserted basic input validation in the menu to make the program user-friendly and prevent runtime errors. Through this approach, the program can be easily expanded without major changes. For instance, multiple input files or new report types can be added without rewriting the entire application.

---

## Table of Contents

- [Grocery Tracker Details](#grocery-tracker-details)
- [Build Instructions](#build-instructions)
- [Run Instructions](#run-instructions)
- [Design Overview](#design-overview)
- [Project Scenario](#project-scenario)
- [Implementation Guidelines](#implementation-guidelines)
- [Submission Requirements](#submission-requirements)
- [Notes](#notes)

---

## Grocery Tracker Details

Reads daily item logs and provides:
1. Frequency lookup for a single item
2. Full frequency list
3. Text histogram
4. Exit

---

## Build Instructions

### Visual Studio
- Create a new Console App project.
- Add all files in `src/` to the project.
- Add `data/CS210_Project_Three_Input_File.txt` to the project or ensure the working directory contains `data/`.

### CMake (Recommended for macOS/CLion)
- `cmake -S . -B build`
- `cmake --build build`

For CLion, open the project and build using the IDE.

- [CMake Documentation](https://cmake.org/cmake/help/latest/index.html)
- [CLion Documentation](https://www.jetbrains.com/help/clion/quick-start-guide.html)
- [CLion Download](https://www.jetbrains.com/clion/download/)

---

## Run Instructions

- Place input at `data/CS210_Project_Three_Input_File.txt`, one item per line.
- On start, the app writes `frequency.dat` with item counts.

---

## Design Overview

- `GroceryTracker`: loads input, builds `map<string,int>`, prints frequencies and histogram, writes backup.
- `Menu`: user loop and input validation.
- `Utils`: small helpers like `trim`.

---

## Project Scenario

You are doing a fantastic job at Chada Tech in your new role as a junior developer, and you exceeded expectations in your last assignment for Airgead Banking. Since your team is impressed with your work, they have given you another, more complex assignment. Your task is to build an item-tracking program for the Corner Grocer, which should incorporate all of their requested functionality.

The Corner Grocer needs a program that analyzes the text records they generate throughout the day. These records list items purchased in chronological order from the time the store opens to the time it closes. They are interested in rearranging their produce section and need to know how often items are purchased so they can create the most effective layout for their customers.

### Functional Requirements

**Menu Option One:**
1. Prompt a user to input the item, or word, they wish to look for.
2. Return a numeric value for the frequency of the specific word.

**Menu Option Two:**
1. Print the list with numbers that represent the frequency of all items purchased.

**Menu Option Three:**
1. Print the same frequency information for all the items in the form of a histogram.

**Menu Option Four:**
1. Exit the program.

### Data File Creation

Create a data file, with the naming convention `frequency.dat`, for backing up your accumulated data. The `frequency.dat` file should include every item (represented by a word) paired with the number of times that item appears in the input file.

---

## Implementation Guidelines

- Use at least one class with public and private sections.
- Prefer `std::map` for frequency counting.
- Follow best practices: comments, naming conventions, and input validation.

**Optional Challenge:**  
Add user input validation and error handling.

---

## Submission Requirements

- Submit a ZIP file with all project files.
- Include a one-page Word document describing your code’s design and functionality, with screenshots.

---

## Notes

- Map keeps items sorted.
- Histogram uses `*` per frequency.
- Input with spaces is supported via `getline`.
