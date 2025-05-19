// Jonathan Kocur
// 4/12/23
// Program 6 Main

/* This file acts as the main file for the weighted averages grading system. This
program will work the main loop that controls the commands for entering grades of
each catagory. Then, it will call functions for averages of the grades. */

# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "prog6_fns.h"

int main() {

	// These variables are related to the user inputed commands
	int i;
	char userCommand[10];
	char enterCommand[10];
	char averageCommand[10];

	// These variables are the total amount of assignments in each catagory
	int exersiseNUM = 9;
	int programNUM = 7;
	int labsNUM = 9;
	int testsNUM = 3;
	int attendance;

	// These arrays are used to fill the assignment grades in the loop
	double exercises[9];
	double programs[7];
	double labs[9];
	double tests[3];
	double test1;
	double othertests[2];

	// These variables represent the averages of each catagory
	double exerciseAVG;
	double labAVG;
	double programAVG;
	double finalAverage;

	/* This while loop is the main loop of the program. It will run until a quit
	command is prompted and take other commands to perform the main functions of
	the program. */
	while (1) {

		printf("Enter command (type help to see all commands): ");
		scanf("%s", userCommand);

		// This if statement controls the exit command and message
		if (strcmp(userCommand, "exit") == 0) {

			printf("Exiting program ...");
			break;
		}

		// This if statement controls the help command and prompts all commands
		else if (strcmp(userCommand, "help") == 0) {

			printf("Commands:\n");
			printf("help: print this command list\n");
			printf("enter: enter values for one type of assignment\n");
			printf("average: calculate/print average for one type of assignment\n");
			printf("grade: calculate/print letter grade based on assignment scores\n");
			printf("exit: exit program\n\n");
		}

		// This if statement controls the enter command
		else if (strcmp(userCommand, "enter") == 0) {

			// This while loop controls controls all of the commands in the enter section
			while (1) {

				printf("Category to enter (tests, programs, labs, exercises, attendance): ");
				scanf("%s", enterCommand);

				// This if statement scans the exercise values and calculates the average
				if (strcmp(enterCommand, "exercises") == 0) {
					printf("Enter 9 chapter exercise scores:\n");

					for (i = 0; i < exersiseNUM; i++) {

						printf("Enter chapter exercise %d: ", i + 1);
						scanf(" %lf", &(exercises[i]));
					}
					exerciseAVG = avg(exersiseNUM, exercises);
					printf("\n");
					break;
				}

				// This if statement scans the lab values and calculates the average
				if (strcmp(enterCommand, "labs") == 0) {
					printf("Enter 9 lab collection scores:\n");

					for (i = 0; i < labsNUM; i++) {

						printf("Enter lab %d: ", i + 1);
						scanf(" %lf", &(labs[i]));
					}
					labAVG = avg(labsNUM, labs);
					printf("\n");
					break;
				}

				// This if statement scans the program values and calculates the average
				if (strcmp(enterCommand, "programs") == 0) {
					printf("Enter 7 program scores:\n");

					for (i = 0; i < programNUM; i++) {

						printf("Enter program %d: ", i + 1);
						scanf(" %lf", &(programs[i]));
					}
					programAVG = avg(programNUM, programs);
					printf("\n");
					break;
				}
				/* This if statement scans the test scores as well as sorts the tests
				scores by their value. A for loop is used to pick the higest test score
				and fill an array with the other two. */
				if (strcmp(enterCommand, "tests") == 0) {
					printf("Enter 3 test scores:\n");

					for (i = 0; i < testsNUM; i++) {

						printf("Enter test %d: ", i + 1);
						scanf(" %lf", &(tests[i]));
					}

					test1 = tests[0];
					othertests[0] = tests[0];

					for (i = 0; i < testsNUM - 1; i++) {

						if (tests[i + 1] > tests[i]) {
							test1 = tests[i + 1];
							othertests[i] = tests[i];
						}
						else {
							othertests[i] = tests[i + 1];
						}
					}
					printf("\n");
					break;
				}
				// This if statement scans the attendance score
				if (strcmp(enterCommand, "attendance") == 0) {
					printf("Enter attendance score (0-5): ");
					scanf(" %d", &(attendance));
					printf("\n");
					break;
				}
				else {
					printf("invalid category %s\n", enterCommand);
				}
			}
		}

		// This if statement controls the average command
		else if (strcmp(userCommand, "average") == 0) {

			// This while loop controls controls all of the commands in the average section
			while (1) {

				printf("Enter category to average (programs, labs, exercises): ");
				scanf("%s", averageCommand);

				// This if statement prints the exercise values as well as the average
				if (strcmp(averageCommand, "exercises") == 0) {

					for (i = 0; i < exersiseNUM; ++i) {

						printf("Chapter exercise %d: ", i + 1);
						printf("%0.0lf\n", (exercises[i]));
					}
					printf("AVERAGE: %0.2lf\n\n", exerciseAVG);
					break;
				}

				// This if statement prints the lab values as well as the average
				if (strcmp(averageCommand, "labs") == 0) {

					for (i = 0; i < labsNUM; ++i) {

						printf("Lab %d: ", i + 1);
						printf("%0.0lf\n", (labs[i]));
					}
					printf("AVERAGE: %0.2lf\n\n", labAVG);
					break;
				}

				// This if statement prints the program values as well as the average
				if (strcmp(averageCommand, "programs") == 0) {
					for (i = 0; i < programNUM; ++i) {
						printf("Program %d: ", i + 1);
						printf("%0.0lf\n", (programs[i]));
					}
					printf("AVERAGE: %0.2lf\n\n", programAVG);
					break;
				}
				else {
					printf("invalid category %s\n", averageCommand);
				}

			}
		}

		// This if statement controls the grade command
		else if (strcmp(userCommand, "grade") == 0) {

			// Here all the final averages are printed as well is the final average function call
			printf("Lab average (20%%): %0.2lf\n", labAVG);
			printf("Program average (30%%): %0.2lf\n", programAVG);
			printf("Ch. exercise average (10%%): %0.2lf\n", exerciseAVG);
			printf("Attendance score (5%%): %d\n", attendance);
			printf("Highest exam grade (15%%): %0.0lf\n", test1);
			printf("2nd exam grade (10%%): %0.0lf\n", othertests[0]);
			printf("3rd exam grade (10%%): %0.0lf\n", othertests[1]);

			finalAverage = calculateGrade(labAVG, exerciseAVG, programAVG, attendance, test1, othertests);
			printf("FINAL AVERAGE: %0.2lf\n", finalAverage);

			// These if statements determine the grade message to be printed based on final average 
			if (finalAverage < 60) {
				printf("FINAL GRADE: F\n\n");
			}
			if (finalAverage >= 60 && finalAverage < 68) {
				printf("FINAL GRADE: D\n\n");
			}
			if (finalAverage >= 68 && finalAverage < 70) {
				printf("FINAL GRADE: D+\n\n");
			}
			if (finalAverage >= 70 && finalAverage < 73) {
				printf("FINAL GRADE: C-\n\n");
			}
			if (finalAverage >= 73 && finalAverage < 78) {
				printf("FINAL GRADE: C\n\n");
			}
			if (finalAverage >= 78 && finalAverage < 80) {
				printf("FINAL GRADE: C+\n\n");
			}
			if (finalAverage >= 80 && finalAverage < 83) {
				printf("FINAL GRADE: B-\n\n");
			}
			if (finalAverage >= 83 && finalAverage < 88) {
				printf("FINAL GRADE: B\n\n");
			}
			if (finalAverage >= 88 && finalAverage < 90) {
				printf("FINAL GRADE: B+\n\n");
			}
			if (finalAverage >= 90 && finalAverage < 93) {
				printf("FINAL GRADE: A-\n\n");
			}
			if (finalAverage >= 93) {
				printf("FINAL GRADE: A\n\n");
			}
		}

		// This else statement prompts an error if the command is invalid
		else {
			printf("invalid command %s\n\n", userCommand);
		}
	}
	return 0;
}