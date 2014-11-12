/*
 * =====================================================================================
 *
 *       Filename:  library.c
 *
 *    Description:  A program for adding books to a digital library.
 *
 *                  TODO
 *                  
 *                  • Make library an array of structs
 *                  • Enable "listing" of all books added to library
 *                  • Add a file for storing list of books
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
// Structs
struct Book {
    char title[100];
    char author[100];
    char subject[50];
    int isbn;
    int year;
};

// Function Prototyping
int read(char s[], int maxlen);

// Main
int main(void) {
    bool exit = false;
    const char *commands[5] = {"help", "new", "list", "exit", "delete"};
    int input, i;
    struct Book library;

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
                printf("You have selected: %s\n", commands[1]);
                printf("Enter the book title: ");
                read(library.title, sizeof(library.title));

                printf("Enter the book's author: ");
                read(library.author, sizeof(library.author));

                printf("Enter the subject: ");
                read(library.subject, sizeof(library.author));

                printf("Enter the year of publication: ");
                scanf("%d", &library.year);

                srand(time(NULL));
                library.isbn = rand();
                
                printf("New Book: '%s' by %s, published in %d with ISBN: %d ", 
                        library.title, library.author, library.year, library.isbn);
                printf("in the %s aisle.\n", library.subject);
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
