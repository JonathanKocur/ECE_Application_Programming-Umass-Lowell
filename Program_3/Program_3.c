// Jonathan Kocur
// 2/13/2023
// Program 3

/* The program simulates a simple calculator where the user inputs simple mathematical functions
and the program outputs the amswer. THe program also rejects syntax errors and invalid operators
printing out an error message. */

#include <stdio.h>
#include <math.h>

int main() {

	// This is the variables used in the calculator
	int variableA;
	char operand;
	int variableB;
	int answer;

	// This is the user prompt message
	printf("Please enter your integer arithmetic expression: ");

	// This is the scan of the variables for the user input
	//scanf("%i", &variableA);
	//scanf(" %c ", &operand);
	//scanf("%i", &variableB);

	/* This is the if else statements that print the answer of the expression if it is valid,
	or an error message if the expression is invalid. */
	if (variableB == 0 && (operand == '/' || operand == '%')) {
		printf("Error: Divide by zero!\n");
	}
	else if (operand == '+') {
		answer = variableA + variableB;
		printf("Answer: %i %c %i = %i\n", variableA, operand, variableB, answer);
	}
	else if (operand == '-') {
		answer = variableA - variableB;
		printf("Answer: %i %c %i = %i\n", variableA, operand, variableB, answer);
	}
	else if (operand == '*') {
		answer = variableA * variableB;
		printf("Answer: %i %c %i = %i\n", variableA, operand, variableB, answer);
	}
	else if (operand == '/') {
		answer = variableA / variableB;
		printf("Answer: %i %c %i = %i\n", variableA, operand, variableB, answer);
	}
	else if (operand == '%') {
		answer = variableA % variableB;
		printf("Answer: %i %c %i = %i\n", variableA, operand, variableB, answer);
	}
	else {
		printf("Error: invalid operator %c!\n", operand);
	}
	return 0;
}
