#ifndef BANKINGSYSTEM_PROJECT_ACCOUNT_H
#define BANKINGSYSTEM_PROJECT_ACCOUNT_H
#define MIN_BALANCE 500

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
using namespace std;
class InsufficientFunds{
public:
    InsufficientFunds(){
        cout<<"WITHDRAWAL_ERROR :: Cannot have a balance under "<<MIN_BALANCE<<"."<<endl;
    }
};
class Account {
    long accountNumber;
    string firstName;
    string lastName;
    double balance;
    static long nextAccountNumber;//universal for the whole class like a sort of counter
public:
    Account();
    Account(string firstName,string lastName, double balance);

    long getAccountNumber();

    const string getFirstName();

    const string getLastName();

    double getBalance();

    static void setLastAccountNumber(long accountNumber);
    static long getLastAccountNumber();

    void deposit(int amount);
    void withdraw(int amount);

    friend ofstream & operator<<(ofstream &ofs, Account &a);
    friend ifstream  & operator>>(ifstream &ifs, Account &a);
    friend ostream & operator<<(ostream &os, Account &a);
};


#endif //BANKINGSYSTEM_PROJECT_ACCOUNT_H
