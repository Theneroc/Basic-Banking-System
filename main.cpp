#include<iostream>
#include<fstream>
#include<cstdlib>
#include<map>
#include "Account.h"
#include "Bank.h"
using namespace std;

int main() {

    int option;
    long accountNumber;
    string firstName,lastName;
    double amount;
    Account account;
    Bank bank;
    cout<<"*****Banking System*****"<<endl;
    do{

    cout<<"1. Open an account"<<endl;
    cout<<"2. Balance Enquiry"<<endl;
    cout<<"3. Deposit"<<endl;
    cout<<"4. Withdrawal"<<endl;
    cout<<"5. Close an account"<<endl;
    cout<<"6. Display all accounts"<<endl;
    cout<<"7. Quit"<<endl;

    cin>>option;
    switch(option){
        case 1:
            cout<<"Enter what may be required: "<<endl;
            cout<<"First Name:";
            cin>>firstName;
            cout<<"Last Name:";
            cin>>lastName;
            cout<<"Amount you wish to deposit (minimum of 500):";
            cin>>amount;
            account = bank.openAccount(firstName, lastName, amount);

            cout<<"Congratulations "<<firstName<<"! You are now an official client of K Bank."<<endl;
            cout<<"***************************"<<endl;
            cout<<account;
            break;
        case 2:
            cout<<"Enter the account's number:";
            cin>>accountNumber;
            account = bank.balanceEnquiry(accountNumber);
            cout<<account;
            break;
        case 3:
            cout<<"Enter the account's number:";
            cin>>accountNumber;
            cout<<"Enter the amount you wish to deposit:";
            cin>>amount;
            account = bank.deposit(accountNumber,amount);
            cout<<account;
            break;
        case 4:
            cout<<"Enter the account's number:";
            cin>>accountNumber;
            cout<<"Enter the amount you wish to withdraw:";
            cin>>amount;
            account = bank.withdraw(accountNumber,amount);
            cout<<account;
            break;
        case 5:
            cout<<"Enter the account's number:";
            cin>>accountNumber;
            cout<<"Are you sure you would like to close this account?(1 for yes, any key for no):";
            int ans;
            cin>>ans;
            switch(ans){
                case 0:
                    break;
                default:
                    bank.closeAccount(accountNumber);
                    cout<<account.getFirstName()<<"'s account has been closed. Thank you."<<endl;
            }
            break;
        case 6:
            bank.showAllAccounts();
            break;
        case 7:
            break;
        default:
            cout<<"You can only enter numbers between 1-7. Please try again."<<endl;
    }

    }
    while(option!=7);


    return 0;
}
