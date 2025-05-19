// Jonathan Kocur
// 3/27/23
// Program 6 functions

/* This code defines the functions called in the main codeand applies them. The first 
function calcualates the average of any array using a for loop to sum and the size. The
second function calculates that total grade average using all the scores and averages. */

# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "prog6_fns.h"

double avg(int arraySize, double *array) {

	int i;
	double sum;
	sum = 0;

	for (i = 0; i < arraySize; ++i) {
		sum = sum + array[i];
	}
	return (sum / arraySize);
}

double calculateGrade(double lAVG, double eAVG, double pAVG, int atten, double exam1, double oExams[2]) {
	return (0.2 * lAVG + 0.3 * pAVG + 0.1 * eAVG + atten + 0.15 * exam1 + 0.1 * oExams[0] + 0.1 * oExams[1]);
}
