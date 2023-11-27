/*
* Brisa Andrade
* Bank Account Inheritance
* Accounts.h
*/

#include "Accounts.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

Account::Account()
{
	aNumber = "";
	aHolder = "";
	balance = 0;
	transfer = 0;


}// end default constructor

Account::Account(string accountNumber, string accountHolder, double newBalance)
{
	aNumber = accountNumber;
	aHolder = accountHolder;
	balance = newBalance;
	transfer = 0;

}// end constructor

void Account::setBalance(double newBalance)
{
	balance = newBalance;

}// end setBalance

void Account::setAccountNumber(string n)
{
	aNumber = n;
}

void Account::setAccountHolder(string name)
{
	aHolder = name;
}

void Account::setTransfer(double amount)
{
	transfer = amount;
}

double Account::getBalance()
{
	return balance;
}// end getBalance

string Account ::getAccountNumber()
{
	return aNumber;
}// end getAccountNumber

string Account::getAccountHolder()
{
	return aHolder;
}

double Account::getTransferAmount()
{
	return transfer;
}

void Account::displayAccount()
{
	cout << "Account Number: " << aNumber << endl;
	cout << "Account Holder: " << aHolder << endl;
	cout << "Current Balance: " << balance << endl;
}// end displayAccount


void Account::deposit(double ammount)
{
	double b = getBalance();
	b += ammount;
	setBalance(b);
}

void Account::withdraw(double ammount)
{
	double b = getBalance();

	if (ammount < b)
	{
		b -= ammount;
		setBalance(b);
	}
	else
	{
		cout << " Withdraw Ammount is invalid, try again." << endl;
	}
}//end withdraw

inline Account operator + (Account const& a, Account const& b)
{
	Account result = a;
	Account c = b;
	double Transferring = c.getTransferAmount();

	result.deposit(Transferring);
	c.withdraw(Transferring);
	c.setTransfer(0);

	return result;

}// end operator +

inline Account operator + (Account const& a, Account const& b)
{
	Account result = a;
	Account c = b;
	double Transferring = c.getTransferAmount();

	result.deposit(Transferring);
	c.withdraw(Transferring);
	c.setTransfer(0);

	return result;

}// end operator +




Savings::Savings()
{
	setBalance(0);
	setAccountHolder("");
	setAccountNumber("");
	interestRate = 0;
}//end default constructor

Savings::Savings(string accountNumber, string accountHolder, double balance, double interest)
{
	setBalance(balance);
	setAccountHolder(accountHolder);
	setAccountNumber(accountNumber);
	interestRate = interest;

}// end constructor

void Savings::setInterest(double interest)
{
	interestRate = interest;
}// end setInterest

double Savings::getInterest()
{
	return interestRate;
} //end getInterest

void Savings::withdraw(double ammount)
{
	double b = getBalance();
	double minimumBalance = 200;

	if (b - ammount > minimumBalance)
	{
		b -= ammount;
		setBalance(b);
	}
	else
	{
		cout << " Withdraw Ammount will put account balance below "<< 
			"minimum balance requirement of $"<< minimumBalance << endl;
	}
}// end withdraw

Current::Current()
{
	setBalance(0);
	setAccountHolder("");
	setAccountNumber(0);
	overdraftLimit = 0;
}//end default constructor

Current::Current(string accountNumber, string accountHolder, double balance, double overdraft)
{
	setBalance(balance);
	setAccountHolder(accountHolder);
	setAccountNumber(accountNumber);
	overdraftLimit = overdraft;

}//end constructor

void Current::setOverdraft(double overdraft)
{
	overdraftLimit = overdraft;
}//end setOverdraft

double Current::getOverdraft()
{
	return overdraftLimit;
}//end setOverdraft

void Current::withdraw(double amount)
{
	double overdraft = getOverdraft();
	double b = getBalance();

	double n = b - amount;

		if (n + overdraft > 0)
		{
			setBalance(n);
		}
		else
		{
			cout << "Withdraw ammount exceeds overdraft limit." << endl;
		}


}// end withdraw

