/*
* Brisa Andrade
* Bank Account Inheritance
* main.cpp
*/

#include "Accounts.h"
#include "Accounts.cpp"

#include <string>
#include <iostream>

int main()
{
	Savings savings("S123", "John Doe", 1000, 0.02);
	Current current("C456", "Jane Doe", 2000, 500);

	savings.Account::displayAccount();
	current.Account::displayAccount();

	savings.Account::deposit(500);
	current.Account::deposit(1000);

	savings.Account::displayAccount();
	current.Account::displayAccount();

	// transfer 300 from savings to current 
	current = current + savings;
	




}//end main

