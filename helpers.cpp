#include <iostream>
#include "helpers.h"
using namespace std;

bool isDigitsOnly(string s){
    int n = s.length();
    if(n == 0) return false;
    for(int i = 0; i<n; i++){
        if(s[i]<'0' || s[i]>'9') return false;
    }
    return true;
}

int readInt(string prompt, int low, int high){
    string line;
    while(true){
        cout<<prompt;
        getline(cin,line);
        if(isDigitsOnly(line) && line.length() <= 9){
            int num = stoi(line);
            if(num >= low && num<= high) return num;
        }
        cout<<"Please enter a number between "<<low <<" and "<<high<<".\n";
    }
}

double readAmount(string prompt){
    string line;
    while(true){
        cout<<prompt;
        getline(cin,line);

        int n = line.length();
        int dots = 0;
        int digits = 0;
        bool ok = (n > 0 && n <=12 );
        for(int i = 0; i<n ; i++){
            if(line[i] == '.') dots++;
            else if (line[i] >= '0' && line[i] <= '9')digits++;
            else ok = false;
        }
        if(ok && dots <= 1 && digits >= 0){
            double amt = stod(line);
            if(amt > 0)return amt;
        }
        cout<<"Enter a valid positive amount.\n";
    }
}

bool isValidDate(string d){
    if(d.length() != 10 )return false;
    if(d[2]!= '-' || d[5] != '-' )return false;

    string dd = d.substr(0,2);
    string mm = d.substr(3,2);
    string yyyy = d.substr(6,4);
    if(!isDigitsOnly(dd) || !isDigitsOnly(mm) || !isDigitsOnly(yyyy)) return false;

    int day = stoi(dd);
    int month = stoi(mm);
    int year = stoi(yyyy);
    if(day<1 || day>31)return false;
    if(month<1 || month>12) return false;
    if(year<1900 || year> 2100) return false;
    return true;
}

string readDate(string prompt){
    string line;
    while(true){
        cout<<prompt;
        getline(cin,line);
        if(isValidDate(line))return line;
        cout<<"Invalid date. Use DD--MM--YYYY (example: 25-10.2026).\n";
    }
}