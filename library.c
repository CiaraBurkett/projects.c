/*
 * =====================================================================================
 *
 *       Filename:  library.c
 *
 *    Description:  A program for adding books to a digital library.
 *
 *                  TODO
 *                  
 *                  • Ask user if they wish to continue adding books after
 *                    each addition
 *                  • Enable "listing" of new books added to library in formatted way
 *                  • Add a file for storing list of books
 *                  • Enable printing of all books in file
 *                  • Make each case statement a function
 *
 *        Version:  1.0
 *        Created:  10/26/2014 16:36:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ciara
 *   Organization:  znth
 *
 * =====================================================================================
 */

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

// Constants
#define SHELF_SPACE 3 

// Structs
struct Book {
    char title[100];
    char author[100];
    char genre[50];
    int isbn;
    int year;
};

// Function Prototyping
int read(char s[], int maxlen);

// Main
int main(void) {
    bool exit = false;
    const char *commands[5] = {"help", "new", "list", "exit", "delete"};
    int input, i, count;
    struct Book library[SHELF_SPACE];

    for(i = 0; i < 5; i++) {
        printf("Command[%d]:  %s\n", i+1, commands[i]);
    }

    do {
        printf("Please choose a command: ");
        scanf("%d", &input);
        rewind(stdin);

        switch(input) {
            case 1:
                printf("You have selected: %s\n", commands[0]);
                puts("You are using Library to enter books into a digital catalog.");
                puts("Enter a number corresponding to a command.");
                break;
            case 2:
                for (count = 0; count < SHELF_SPACE; count++) {
                    printf("You have selected: %s\n", commands[1]);
                    printf("Enter the book title: ");
                    read(library[count].title, sizeof(library[count].title));

                    printf("Enter the book's author: ");
                    read(library[count].author, sizeof(library[count].author));

                    printf("Enter the genre: ");
                    read(library[count].genre, sizeof(library[count].genre));

                    printf("Enter the year of publication: ");
                    scanf("%d", &library[count].year);

                    srand(time(NULL));
                    library[count].isbn = rand();
                    rewind(stdin);
                }

                for (count = 0; count < SHELF_SPACE; count++) {
                    printf("Book[%d]: '%s' \nBy: %s \nPublished: %d \nISBN: %d ", 
                            count + 1, library[count].title, library[count].author, 
                            library[count].year, library[count].isbn);
                    printf("\nAisle: %s\n", library[count].genre);
                    printf("\n");
                }
                
                break;
            case 3:
                printf("You have selected: %s\n", commands[2]);
                break;
            case 4:
                printf("You have selected: %s\n", commands[3]);
                exit = true;
                break;
            case 5:
                printf("You have selected: %s\n", commands[4]);
                break;
            default:
                if (!(isdigit(input))) {
                    printf("ERROR! Enter a number corresponding to a command.\n");
                }
        }
    } while (!exit);

    return 0;
}

// Function Declaration
int read(char s[], int maxlen) {
    char ch;
    int i, chars_remain;

    i = 0;
    chars_remain = true;

    while(chars_remain) {
        ch = getchar();

        if ((ch == '\n') || (ch == EOF)) {
            chars_remain = false;
        }
        else if (i < maxlen - 1) {
            s[i] = ch;
            i++;
        }
    }
    s[i] = '\0';
    return i;
}
