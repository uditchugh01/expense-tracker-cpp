#include <iostream>
#include <fstream>
#include "expense.h"
#include "helpers.h"
using namespace std;

// ---------- Constructor ----------
ExpenseManager::ExpenseManager(string file) {
    fileName = file;
    expenseCount = 0;
    load();                       // object bante hi file se data aa jayega
}

// ---------- Save / Load ----------
void ExpenseManager::save() {
    ofstream fout(fileName);
    for (int i = 0; i < expenseCount; i++) {
        fout << expenses[i].amount << "\n";
        fout << expenses[i].category << "\n";
        fout << expenses[i].date << "\n";
        fout << expenses[i].note << "\n";
    }
    fout.close();
}

void ExpenseManager::load() {
    ifstream fin(fileName);
    if (!fin) return;             // file nahi hai toh kuch load mat karo
    string line;
    while (expenseCount < MAX && getline(fin, line)) {
        expenses[expenseCount].amount = stod(line);
        getline(fin, expenses[expenseCount].category);
        getline(fin, expenses[expenseCount].date);
        getline(fin, expenses[expenseCount].note);
        expenseCount++;
    }
    fin.close();
}

// ---------- Add ----------
void ExpenseManager::add() {
    if (expenseCount == MAX) {
        cout << "List full!\n";
        return;
    }
    Expense e;
    e.amount = readAmount("Amount: ");
    cout << "Category: ";
    getline(cin, e.category);
    e.date = readDate("Date (DD-MM-YYYY): ");
    cout << "Note: ";
    getline(cin, e.note);

    expenses[expenseCount] = e;
    expenseCount++;
    save();
    cout << "Expense added!\n";
}

// ---------- View ----------
void ExpenseManager::view() {
    if (expenseCount == 0) {
        cout << "No expenses yet.\n";
        return;
    }
    for (int i = 0; i < expenseCount; i++) {
        cout << i + 1 << " | " << expenses[i].amount << " | "
             << expenses[i].category << " | " << expenses[i].date
             << " | " << expenses[i].note << "\n";
    }
}

// ---------- Delete ----------
void ExpenseManager::removeExpense() {
    if (expenseCount == 0) {
        cout << "Nothing to delete.\n";
        return;
    }
    view();
    int num = readInt("Delete which number? ",1, expenseCount);
    // delete = baaki elements ko ek step left shift karo
    for (int i = num - 1; i < expenseCount - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    expenseCount--;
    save();
    cout << "Deleted!\n";
}

// ---------- Total ----------
double ExpenseManager::getTotal() {
    double total = 0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// ------------ Search by category --------
void ExpenseManager::searchByCategory(){
    string cat;
    cout<<"Category to search: ";
    getline(cin,cat);

    bool found = false;
    for(int i = 0; i<expenseCount; i++){
        if(expenses[i].category == cat){
            cout<< i+1<<" | "<<expenses[i].amount<<" | "<<expenses[i].category<<" | "<<expenses[i].note<<"\n";
            found = true;
        }
    }
    if(!found){
        cout<<"No expenses found.\n";
    }
}

//----------Sort by amount ------- 
void ExpenseManager:: sortByAmount(){
    for(int i = 0 ; i<expenseCount-1 ; i++){
        int minIndex = i;
        for(int j = i+1; j<expenseCount; j++){
            if(expenses[j].amount < expenses[minIndex].amount){
                minIndex = j;
            }
        }
        Expense temp = expenses[i];
        expenses[i] = expenses[minIndex];
        expenses[minIndex] = temp;
    }
    save();
    cout<<"Sorted by amount (low to high).\n";
}

//-----------Monthly total------
double ExpenseManager:: getMonthlyTotal(int month,int year){
    double total = 0;
    for(int i = 0; i< expenseCount ; i++){
        int m = stoi(expenses[i].date.substr(3,2));
        int y = stoi(expenses[i].date.substr(6,4));
        if(m== month && y == year){
            total += expenses[i].amount;
        }
    }
    return total;
}