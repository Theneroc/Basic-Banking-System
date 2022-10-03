#ifndef BANKINGSYSTEM_PROJECT_BANK_H
#define BANKINGSYSTEM_PROJECT_BANK_H
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include "Account.h"
using namespace std;


using namespace std;
class Bank {
  map<long,Account> accounts;//using a C++ built-in map class for easy access in finding a specific account using its personal account number.
public:
    Bank();
    Account openAccount(string firstName,string lastName,double balance);
    Account balanceEnquiry(long accNum);
    Account deposit(long accNum,double amount);
    Account withdraw(long accNum,double amount);
    void closeAccount(long accNum);
    void showAllAccounts();
    ~Bank();
};


#endif //BANKINGSYSTEM_PROJECT_BANK_H
