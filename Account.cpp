//
// Created by pro on 10/1/2022.
//

#include <iostream>
#include "Account.h"
using namespace std;
Account::Account() {}
Account::Account(string firstName,string lastName,double balance)  {
    if(balance<MIN_BALANCE)
        throw InsufficientFunds();
    nextAccountNumber++;
    accountNumber = nextAccountNumber;
    this->firstName = firstName;
    this->lastName = lastName;
    this->balance = balance;

}


long Account::getAccountNumber() {
    return accountNumber;
}

const string Account::getFirstName() {
    return firstName;
}

const string Account::getLastName() {
    return lastName;
}

double Account::getBalance() {
    return balance;
}

 void Account::setLastAccountNumber(long accountNumber) {
    nextAccountNumber = accountNumber;
}

 long Account::getLastAccountNumber() {
    return nextAccountNumber;
}
void Account::deposit(int amount) {
    balance+= amount;
}
void Account::withdraw(int amount) {
    if(balance<MIN_BALANCE && balance-amount>MIN_BALANCE)
        balance-= amount;
    else
        throw InsufficientFunds();
}
ofstream & operator<<(ofstream &ofs,Account &a){
    ofs<<a.accountNumber<<endl<<a.firstName<<" "<<a.lastName<<endl<<a.balance<<endl;
}

ifstream & operator>>(ifstream &ifs,Account &a){
    ifs>>a.accountNumber>>a.firstName>>a.lastName>>a.balance;
}

ostream  & operator<<(ostream &os,Account &a){
    os<<"Account Number: "<<a.accountNumber<<endl<<"Name: "<<a.firstName<<" "<<a.lastName<<endl<<"Balance: "<<a.balance<<endl;
    os<<"***************************"<<endl;
}
long Account::nextAccountNumber = 0;//to make sure only the class itself has this variable
