//  Yuya Oguchi
//  COEN11L     Lab6
//  11/07/2014
//  Complete restaurantwaitlist
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char *argv[])
{
    char namex[20];
    int numberx;
    int command;
    int quit = 0;
    printf("Welcome to Yuya's Restaurant what would you like to do?\n\n");
    printf("Type 1 to add waitlist\n");
    printf("Type 2 to eliminate an entry that fits the table\n");
    printf("Type 3 to show all Waitlist\n");
    printf("Type 4 to quit\n");
    printf("----------------------------\n\n");

    readin();
    while (quit == 0){

        scanf("%d",&command);

        if (command == 1){
            add();

        }else if (command == 2){
            deleted();

        }else if (command == 3){
            stats();

        }else if (command == 4){
            write_file(); //load all info
            quit = 1;

        }
        printf("What would you like to do?\n");

    }//end while loop

    return 0;
}
