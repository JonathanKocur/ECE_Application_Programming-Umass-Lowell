// Jonathan Kocur
// 3/27/23
// Program 5 functions

/* This code defines the functions called in the main codeand applies them.The first function
takes the input coin amounts and adds them to the total dollar amount. The second function
calculates the total amount with the given interest rate and given time waited */

# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "prog5_functions.h"


double GetPiggyBankMoney(double Quarters, double Dimes, double Nickels, double Pennies) {
	return (Quarters * 0.25 + Dimes * 0.1 + Nickels * 0.05 + Pennies * 0.01);
}
double GetNewAmount(double principal, double rate, double years) {
	return (principal * pow((1 + rate), years));
}