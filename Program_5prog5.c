// Jonathan Kocur
// 3/27/23
// Program 5 Main

/* This program acts as a simple banking system where the user is prompted to invest
 with a yearly interest rate, wait, or quit. In the user invests, they are asked to enter
 the number of pennies, nickels, dimes, and quarters and a function calculates the fund amount
 after the specified time with interest */

# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "prog5_functions.h"

int main()
{   
    // Here is where the variables used in the main function are initialized
    int current_Year = 0;
    double current_Funds = 0;
    double current_Rate = 0;
    char user_Command;
    int a, b, c, d;
    int years_Waited;


    /* This while loop controls the main portion of the banking system where the users input
    dictates what path the while loop goes in. If the user does not enter q, i, or w (not case
    sensative), the program will print an error message an start the loop again. */
    while (1) {

        // Here the initial prompt is given to the user and 
        printf("Year %d:\n", current_Year);
        printf(" There is $%.2lf in your bank account with an annual rate of %.3lf. What do you wish to do?", current_Funds, current_Rate);
        printf(" (Wait, Invest, Quit): ");
        scanf(" %c", &user_Command);


        // Here the quit path is written where the program ends with the character q.
        if (tolower(user_Command) == 'q') {
            printf("Bye!");
            break;
        }

        /* Here the invest path is written where the user is prompted to enter the change amount
        and the current funds are updated with the change function. Then the interest rate is 
        scanned and the interest function is used to wait a year. */
        else if (tolower(user_Command) == 'i') {
            while (1) {
                printf("\nPlease enter the number of quarters, dimes, nickels, and pennies, separated by spaces: ");
                scanf("%d %d %d %d", &a, &b, &c, &d);

                if ((a < 0) || (b < 0) || (c < 0) || (d < 0)) {
                    printf("All values must be >= 0!\n");
                }
                else {
                    break;
                }
            }

            current_Funds = current_Funds + GetPiggyBankMoney(a, b, c, d);
            printf("\nYou got $%.2lf from your piggy bank and added it to your account! Your total is now $%.2lf\n", GetPiggyBankMoney(a, b, c, d), current_Funds);

            while (1) {
                printf("What is the new yearly rate? ");
                scanf("%lf", &current_Rate);

                if (current_Rate <= 0) {
                    printf("Need a positive amount!\n");
                }
                else {
                    break;
                }
            }
            current_Funds = GetNewAmount(current_Funds, current_Rate, 1);
            current_Year = current_Year + 1;

        }

        /* Here the wait path is written where the user is prompted to enter the number of years 
        to be waited and the interest function is called. */
        else if (tolower(user_Command) == 'w') {

            while (1) {

                printf("How many years do you want to wait? ");
                scanf("%d", &years_Waited);

                if (years_Waited <= 0) {
                    printf("Need a positive amount!\n");
                }
                else {
                    break;
                }
            }
            printf("Waiting %d year(s)...\n", years_Waited);
            current_Funds = GetNewAmount(current_Funds, current_Rate, years_Waited);
            current_Year = current_Year + years_Waited;
        }

        // Here the error message for an invalid character is written
        else {
            printf("Invalid command %c!\n", user_Command);
        }
        printf("\n");
    }
    return 0;
}
