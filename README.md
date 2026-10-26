# Expense Tracker (C++)

A command-line expense tracker built in C++ with OOP, file handling and input validation.

## Features
- Add, view and delete expenses
- Total spending and monthly total
- Search by category
- Sort by amount (selection sort, implemented manually)
- Data saved in a text file, so it persists between runs
- Input validation for menu choices, amounts and dates (DD-MM-YYYY)

## Project Structure
- `main.cpp` - menu and program flow
- `expense.h` / `expense.cpp` - `ExpenseManager` class
- `helpers.h` / `helpers.cpp` - input validation helpers

## How to Run
```
g++ main.cpp expense.cpp helpers.cpp -o tracker
./tracker
```
(On Windows use `.\tracker`)

## What I Learned
- Structures, classes, constructors and encapsulation
- File I/O with `ifstream` / `ofstream`
- Splitting code into header and source files
- Writing input validation instead of trusting the user

## Future Improvements
- Case-insensitive search
- Edit an existing expense
- Replace the text file with SQLite