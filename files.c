//  Yuya Oguchi
//  COEN11L     Lab10
//  11/07/2014
//  file functions
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

//read file
void readin(){

    char namex[20];
    int numberx;


    char input[50];//this is name
    FILE *list;
    list = fopen("list.txt", "r");
    if (list == NULL){
        printf ("cannot open the file %s\n",input);
    }

    while(fscanf(list,"%s %d\n",namex,&numberx) != EOF)
    {
    addpro(namex,numberx); //readin all info
    }
}
