/*
* Brisa Andrade
* Bank Account Inheritance 
* Accounts.h
*/

#ifndef ACCOUNTS_H_
#define ACCOUNTS_H_

#include <string>
using namespace std;

class Account 
{
private:
	string aNumber;
	string aHolder;
	double balance;
	double transfer;

public:
	void displayAccount();
	void deposit(double amount);
	void withdraw(double amount);
	
	
	Account(); //default constructor
	Account(string accountNumber, string accountHolder, double balance); //constructor
	void setBalance(double balance); // set account balance
	void setAccountNumber(string n);
	void setAccountHolder(string name);
	void setTransfer(double amount);

	


	double getBalance(); //gets balance
	double getTransferAmount(); //gets transfer amount
	string getAccountNumber(); //gets account number
	string getAccountHolder(); // get account holder name
};

class Savings : public Account
{
private:
	double interestRate;

public: 
	void withdraw(double ammount);

	Savings(); //default constructor
	Savings(string accountNumber, string accountHolder, double balance, double interest); //constructor

	void setInterest(double interest); // set interest rate
	double getInterest(); // get interest rate

};

class Current : public Account
{

private:
	double overdraftLimit;

public:
	void withdraw(double ammount);

	Current();
	Current(string accountNumber, string accountHolder, double balance, double overdraft);

	void setOverdraft(double overdraft);
	double getOverdraft();

};

#endif 
