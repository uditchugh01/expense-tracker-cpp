#include <iostream>
#include "expense.h"
#include "helpers.h"
using namespace std;

int main() {
     ExpenseManager manager("expenses.txt");   // constructor chala, file load ho gayi
    int choice;
    while (true) {
        cout << "\n1. Add  2. View  3. Delete  4. Total  5. Search 6. Sort 7. Monthly 8. Exit\n";
        choice = readInt("Choose: ",1, 8);
        if (choice == 1) manager.add();
        else if (choice == 2) manager.view();
        else if (choice == 3) manager.removeExpense();
        else if (choice == 4) cout << "Total: " << manager.getTotal() << "\n";
        else if (choice == 5) manager.searchByCategory();
        else if (choice == 6) manager.sortByAmount();
        else if (choice == 7) {
            int month= readInt("Month (1-12): ",1, 12);
            int year = readInt("Year: ",1900 , 2100);
            cout<<"Total: "<<manager.getMonthlyTotal(month,year)<<"\n";
        }
        else if (choice == 8) break;
        else cout << "Wrong choice\n";
    }
    return 0;
}