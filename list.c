//  Yuya Oguchi
//  COEN11L     Lab10
//  11/07/2014
//  main.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"


typedef struct node{
    int number;
    char name[20];
    struct node *next;
    struct node *previous;
}Node;

Node *head = NULL;
Node *tail = NULL;

void add(){
    Node *p;
    if ((p = (Node*)malloc (sizeof (Node))) == (Node*)NULL){
		printf ("Node could not be allocated\n");
		return;
	}

    printf("Enter name\n");
	scanf("%s", p->name);
	if (head == NULL){
		head = p;

	}else{
		Node *temp;
		temp = head;
		while (temp != NULL){
			if (strcmp(temp->name, p->name) == 0){//duplicate
				printf("Duplicate, try again\n");
				free(p);
				return;
			}
			else{//no duplicate
				temp = temp->next;
			}
		}
	}//end else check duplicate
    printf("Enter the number\n");
    scanf("%d",&p->number);
    if (tail != NULL){
		tail->next = p;
	}
	tail = p;
    tail->next=NULL;
    return;
}

void addpro(char name[20],int number){
    Node *p;
    if ((p = (Node*)malloc (sizeof (Node))) == (Node*)NULL){
		printf ("Node could not be allocated\n");
		return;
	}

	strcpy(p->name,name);
    p->number = number;

	if (head == NULL){
		head = p;

	}
    if (tail != NULL){
		tail->next = p;
	}
	tail = p;
    tail->next=NULL;
    p = p->next;
    return;
}


void deleted(){
    int open;
    Node *temp = head;//make temp linklist that is at head
    printf("What is the size of table?\n");
    scanf("%d", &open);

	if (head->number <= open)//checking for head
	{
        head = temp->next;
        free(temp);
        return;
	}
    Node *change;
    Node *temp2;
    change=temp;
    temp=change->next;
    while (temp->next != NULL){
        //change=temp;
        //temp=change->next;
        if (temp->number <= open)//if num is less than open
        {
            temp2 = change->next;
            change->next = change->next->next;
            free(temp2);
            printf("Value taken out\n");
            return;
        }else if (temp->number > open)
        {
            change = temp;
            temp = temp->next;
        }
    }//close while loop

    if(temp->number <= open){
        printf("Last value taken out\n");
        free(temp);
        tail = change;
        tail->next = NULL;
    }
	return;
}//close void

void stats(){
    Node *temp = head;
    while (temp != NULL){
        printf("Name: %s\tNumber: %d\n", temp->name, temp->number);
		temp = temp->next;
    }
    return;
}

void write_file(){

    char input[50];//this is name
    FILE *listw;
    listw = fopen("list.txt", "w");
    if (listw == NULL){
        printf ("cannot open the file %s\n",input);
    }

    Node *temp = head;
    while (temp != NULL){
        fprintf(listw, "%s %d\n", temp->name, temp->number);
		temp = temp->next;
    }

    fclose(listw);

}
