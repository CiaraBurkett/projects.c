/*
 * =====================================================================================
 *
 *       Filename:  termina.c
 *
 *    Description:  termina mobile investigation unit
 *
 *        Version:  1.0
 *        Created:  04/19/2014 19:57:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ciara
 *   Organization:  znth 
 *
 * =====================================================================================
 */

// Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>

// Constants
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Function prototyping
void printGreeting();
void getUsername();
void scanning();
void outside();
void facilityEntrance();
void missionFailure();
void entranceHallway();
void moving();

// Main game functionality
int main() {

    char userInput[10];
    printGreeting();
    getUsername();

    puts("Commencing initial environment scan.");
    scanning();

    outside();

    char help[4] = "help";
    char scan[4] = "scan";
    char enter[5] = "enter";
    char forward[7] = "forward";
    char back[4] = "back";
    char one[3] = "one";
    char two[3] = "two";
    char tryAgain;
    char areYouSure;
    bool exit = false;
    
    // LEVEL 1:  Outside CSRL facility. Secluded area within overgrown forest and parking lot.
    while (!exit) {
        do {
            printf(ANSI_COLOR_CYAN "Instructions? " ANSI_COLOR_RESET);
            printf("(options: help, scan, forward, enter, back) ");
            scanf(" %s", userInput);

            if (strncmp(userInput, help, 4) == 0) {
                puts("You have selected option: 'help'");
                puts("\nInteractive Mobile Investigation Unit (IMIU) v1.01 beta is a product of Garrison Corp. Inc.");
                puts("Patent pending.\n");
                continue;

            }
            else if (strncmp(userInput, scan, 4) == 0) {
                puts("You have selected option: 'scan'");
                scanning();
                outside();
                continue;
            }   
            else if (strncmp(userInput, enter, 5) == 0) {
                puts("You have selected option: 'enter'");
                puts("Nothing to enter.");
                continue;
            }
            else if (strncmp(userInput, forward, 7) == 0) {
                moving();
                exit = true;
            }
            else if (strncmp(userInput, back, 4) == 0) {
                puts("You have selected option: 'back'");
                printf(ANSI_COLOR_YELLOW "Are you sure?  Leaving environment will result in mission failure! (y/n) " ANSI_COLOR_RESET);
                scanf(" %c", &areYouSure);

                if (tolower(areYouSure) == 'y') {
                    puts("Please submit letter of resignation at your earliest convenience.");
                    missionFailure();
                }
                else {
                    continue;
                }
            }
            else {
                printf(ANSI_COLOR_RED "ERROR: " ANSI_COLOR_RESET);
                printf("'%s'", userInput);
                printf(ANSI_COLOR_RED " is not a command.  Try again? (y/n) " ANSI_COLOR_RESET);
                scanf(" %c", &tryAgain);

                if (tolower(tryAgain) == 'y') {
                    tryAgain = 'z';
                    continue;
                }
                else {
                    missionFailure();
                }
            }
        } while (tolower(tryAgain) == 'y');
    } // end LEVEL 1

    exit = false;

    // LEVEL 2:  Front of CSRL entrance 
    printf(ANSI_COLOR_GREEN "New Location: " ANSI_COLOR_RESET);
    puts("Facility entrance.");

    while (!exit) {
        do {
            printf(ANSI_COLOR_CYAN "Instructions? " ANSI_COLOR_RESET);
            printf("(options: help, scan, forward, enter, back) ");
            scanf(" %s", userInput);

            if (strncmp(userInput, help, 4) == 0) {
                printf(ANSI_COLOR_CYAN "You have selected option: " ANSI_COLOR_RESET);
                printf("'%s'\n", userInput);
                puts("IMIU is outside Computational Sciences Research Lab entrance.");
                continue;
            }
            else if (strncmp(userInput, scan, 4) == 0) {
                puts("Commencing environment scan.");
                scanning();
                facilityEntrance();
                continue;
            }
            else if (strncmp(userInput, forward, 7) == 0) {
                puts(ANSI_COLOR_YELLOW "Facility entrance." ANSI_COLOR_RESET);
                continue;
            }
            else if (strncmp(userInput, enter, 5) == 0) {
                moving();
                exit = true;
            }
            else if (strncmp(userInput, back, 4) == 0) {
                printf(ANSI_COLOR_YELLOW "Are you sure?  Leaving facility will result in mission failure! (y/n) " ANSI_COLOR_RESET);
                scanf(" %c", &areYouSure);

                if ((tolower(areYouSure)) == 'y') {
                    outside();
                    missionFailure();
                }
                else {
                    continue;
                }
            }
            else {
                printf(ANSI_COLOR_RED "ERROR: " ANSI_COLOR_RESET);
                printf("'%s'", userInput);
                printf(ANSI_COLOR_RED " is not a command.  Try again? (y/n) " ANSI_COLOR_RESET);
                scanf(" %c", &tryAgain);

                if (tolower(tryAgain) == 'y') {
                    tryAgain = 'z';
                    continue;
                }
                else {
                    missionFailure();
                }
            }
        } while (tolower(tryAgain) == 'y');
    } // end LEVEL 2))

    exit = true;

    // LEVEL 3 CSRL Entrance Hallway
    printf(ANSI_COLOR_GREEN "New Location: " ANSI_COLOR_RESET);
    puts("Computational Sciences Research Lab entrance hallway.");

    while (!exit) {
        do {
            printf(ANSI_COLOR_CYAN "Instructions? " ANSI_COLOR_RESET);
            printf("(help, scan, enter, back, one, two) ");
            scanf(" %s", userInput);

            if (strncmp(userInput, help, 4) == 0) {
                entranceHallway();
                continue;
            }
            else if (strncmp(userInput, scan, 4) == 0) {
                entranceHallway();
                continue;
            }
            else if (strncmp(userInput, enter, 5) == 0) {
                // print Please enter "one" for the first door or "two" for the second door
                // continue;
            }
            else if (strncmp(userInput, one, 3) == 0) {
                moving();
                exit = true;
            }
            else if (strncmp(userInput, two, 3) == 0) {
                moving();
                exit = true;
            }
            else if (strncmp(userInput, back, 4) == 0) {
                printf(ANSI_COLOR_YELLOW "Are you sure?  Leaving facility will result in mission failure! (y/n) " ANSI_COLOR_RESET);
                scanf(" %c", &areYouSure);

                if ((tolower(areYouSure)) == 'y') {
                    facilityEntrance();
                    missionFailure();
                }
                else {
                    continue;
                }
            }
            else {

            }
        } while (tolower(tryAgain) == 'y');
    }

    return 0;

} // end of main

/**************************************************************************************************************/

// Print greeting function
void printGreeting() {

    printf(ANSI_COLOR_CYAN  "\n\n***  Welcome to Termina, Interactive Mobile Investigation Unit (IMIU).  ***\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "-----------------------------------------------------------------------------" ANSI_COLOR_RESET "\n\n");
}

// Get username function
void getUsername() {

    char username[25];
    char correct;
    
    do {
        printf("Please enter employee username (25 characters and below): ");
        scanf(" %s", username);
        printf("Is username: " ANSI_COLOR_CYAN "%s" ANSI_COLOR_RESET " correct? (y/n) ", username);
        scanf(" %c", &correct);
    } while (tolower(correct) != 'y');
    
    if (strlen(username) >=24) {
        printf(ANSI_COLOR_RED "ERROR: Username exceeds character limit." ANSI_COLOR_RESET  "\n\n");
        exit(1);
    }
    printf(ANSI_COLOR_GREEN "CONFIRMED:  " ANSI_COLOR_RESET);
    printf("Thank you, %s.\n\n", username);
}

// Wait 10 seconds while scanning new environment
void scanning() {

    int i;

    for (i = 1; i < 10; i++) {
        sleep(1);
        printf(".  ");
        fflush(stdout);
    }
    printf("\n");
}

// IMIU is outside the facility
void outside() {
    printf("\n");
    puts(ANSI_COLOR_MAGENTA "DESCRIPTION:" ANSI_COLOR_RESET);
    puts("------------");
    puts("Approximately 5 meters outside of Computational Sciences Research Lab");
    printf("\n");
}

// IMIU is at facility entrance
void facilityEntrance() {
    printf("\n");
    puts(ANSI_COLOR_MAGENTA "DESCRIPTION:" ANSI_COLOR_RESET);
    puts("------------");
    puts("Facility entrance is solid glass at 10 centimeters thick.");
    puts("Words in white lettering read:  'CSRL'");
    printf("\n");
}

// Red error message and end of game
void missionFailure() {
    puts("\a\a\a");
    printf(ANSI_COLOR_RED "***  MISSION FAILURE  ***\n" ANSI_COLOR_RESET);
    exit(1);
}

// Text when IMIU is on the move
// Todo:  Play sound while moving
void moving() {
    printf("\n");
    printf(ANSI_COLOR_YELLOW "***  STANDBY:  Engaging locomotion " ANSI_COLOR_RESET);

    int i;

    for (i = 1; i < 10; i++) {
        sleep(1);
        printf(".");
        fflush(stdout);
    }
    printf("\n\n");
}

// Description of CSRL entrance hallway
void entranceHallway() {
    printf("\n");
    puts(ANSI_COLOR_MAGENTA "DESCRIPTION:" ANSI_COLOR_RESET);
    puts("------------");
    puts("Hallway light visibility is low.");
    printf("\n");
}
