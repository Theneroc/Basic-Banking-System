//
// Created by pro on 10/1/2022.
//

#include "Bank.h"
using namespace std;
Bank::Bank(){
    Account account;
    ifstream inFile("Bank.txt");
    if(!inFile.is_open())
        return;

    while(!inFile.eof()){
        inFile>>account;
        accounts.insert(pair<long,Account>(account.getAccountNumber(),account));
    }
    Account::setLastAccountNumber(account.getAccountNumber());
    inFile.close();
}
Account Bank::openAccount(string firstName, string lastName, double balance) {
    ofstream outFile("Bank.txt",ios::app);
    Account account(firstName,lastName,balance);
    accounts.insert(pair<long,Account>(account.getAccountNumber(),account));
    //outFile<<account;
    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++){
        outFile<<itr->second;//itr->second gives the value of the pair (an account) while itr-> would give the key number of it.
    }
    outFile.close();
    return account;
}

Account Bank::balanceEnquiry(long accNum) {
   // return Account();
   map<long,Account>::iterator itr;
   itr = accounts.find(accNum);
   return itr->second;
}

Account Bank::deposit(long accNum, double amount) {
   map<long,Account>::iterator itr;
   itr = accounts.find(accNum);
   itr->second.deposit(amount);
    return itr->second;
}

Account Bank::withdraw(long accNum, double amount) {
   map<long,Account>::iterator  itr;
   itr = accounts.find(accNum);
   itr->second.withdraw(amount);
   return itr->second;
}

void Bank::closeAccount(long accNum) {
    map<long,Account>::iterator itr;
    itr = accounts.find(accNum);
    accounts.erase(itr);
    cout<<"Account "<<itr->second.getAccountNumber()<<" deleted."<<endl;
}

void Bank::showAllAccounts() {
    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++){
        cout<<itr->second;
    }
}

Bank::~Bank(){
    ofstream outFile("Bank.txt",ios::app);

    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++){
        outFile<<itr->second;
    }
    outFile.close();
}

