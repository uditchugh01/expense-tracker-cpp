#pragma once
#include <string>
using namespace std;

struct Expense {
    double amount;
    string category;
    string date;
    string note;
};

const int MAX = 1000;

class ExpenseManager {
private:
    Expense expenses[MAX];
    int expenseCount;
    string fileName;
    void save();
    void load();

public:
    ExpenseManager(string file);
    void add();
    void view();
    void removeExpense();
    double getTotal();
    void searchByCategory();
    void sortByAmount();
    double getMonthlyTotal(int month, int year);
};