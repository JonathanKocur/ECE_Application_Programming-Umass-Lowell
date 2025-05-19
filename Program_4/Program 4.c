// Jonathan Kocur
// 2/13/2023
// Program 4

/* This program essentially creates a simple guessing game where the program prompts the user
 to enter specifications for the game. Then, the game is run and the program will inform the
user of the accuracy of their guess. When the game is over the program prints the statistics */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {

	// These variables are related to the user specification of the game
	int RNDseed = 0;
	int Range1 = 0;
	int Range2 = 0;
	int guessNumber = 0;
	int roundNumber = 0;


	// These variables are related to the guessing part of the game
	int playerGuess = 0;
	int i;
	int currentGuess;
	int wins = 0;
	int losses = 0;
	double winsDB;
	double WinPCT;


	// This while loop controls the user defined random seed
	while (RNDseed <= 0) {
		printf("Enter seed for random number generator: ");
		scanf("%d", &RNDseed);

		if (RNDseed <= 0) {
			printf("ERROR: seed value should be > 0\n");
		}
	}
	printf("Seed: %d\n\n", RNDseed);

	// This while loop controls the user defined range endpoints
	while ((Range2 - Range1) < 4) {
		while (Range1 <= 0) {
			printf("Enter range endpoints: ");
			scanf("%d %d", &Range1, &Range2);

			if ((Range2 - Range1) < 4) {
				printf("ERROR: Max value should be at least 4 more than min value\n");
			}
			if (Range2 <= 0) {
				printf("ERROR: Max value should be positive\n");
			}
			if (Range1 <= 0) {
				printf("ERROR: Min value should be positive\n");
			}
		}
	}
	printf("Range endpoints: %d %d\n\n", Range1, Range2);

	// This while loop controls the user defined guess number
	while (guessNumber < 2) {
		printf("Enter number of guesses per round: ");
		scanf("%d", &guessNumber);

		if (guessNumber < 2) {
			printf("ERROR: Must allow at least 2 guesses\n");
		}
	}
	printf("Number of guesses: %d\n\n", guessNumber);

	// This while loop controls the user defined round number
	while (roundNumber < 1) {
		printf("Enter number of rounds for game: ");
		scanf("%d", &roundNumber);

		if (roundNumber < 1) {
			printf("ERROR: Must allow at least 1 round\n");
		}
	}
	printf("Number of rounds: %d\n\n", roundNumber);


	srand(RNDseed);


	/* This nested loop represents the turns in the game. The outer for loop controls the rounds of each
	round which are specified by the user. The inner for loop controls the guesses of each round and
	breaks if the amount of guesses is up or the player guessed correctly */
	for (i = 1; i <= roundNumber; ++i) {

		printf("ROUND %d\n", i);
		int num = (rand() % (Range2 - Range1 + 1)) + Range1;

		/* The inner for loop controls the guessing for each round of the game. Each iteration is a guess
		where the if statements below test the accuracy of the guess. If the player guesses right, the 
		iteration value is changed to the max to end the for loop. */
		for (currentGuess = 1; currentGuess <= guessNumber; ++currentGuess) {
			printf("Enter guess #%d: ", currentGuess);
			scanf("%d", &playerGuess);

			if ((playerGuess > num) && (currentGuess < guessNumber)) {
				printf("%d is too high!\n", playerGuess);
			}
			if ((playerGuess < num) && (currentGuess <= guessNumber)) {
				printf("%d is too low!\n", playerGuess);
			}
			if (playerGuess == num) {
				printf("Correct guess!\n");
				wins = wins + 1;
				currentGuess = guessNumber;
			}
			if ((currentGuess == guessNumber) && (playerGuess != num)) {
				printf("No more guesses--the correct answer was %d\n", num);
				losses = losses + 1;
			}
		}

		// Here the results of are printed after each round.
		printf("Current wins: %d\n", wins);
		printf("Current losses: %d\n\n", losses);
	}


	/* These equations below calculate the win percentage of the game. Then, the final results 
	of the game are printed out to the screen. */
	winsDB = wins;
	WinPCT = (winsDB) / (roundNumber) * 100;
	printf("FINAL STATS\n");
	printf("Wins: %d\n", wins);
	printf("Losses: %d\n", losses);
	printf("Winning percentage: %0.2lf%%\n", WinPCT);

	return 0;
}
