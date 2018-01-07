#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int seat;
	char name[15];
	int age;
	char sex;
	struct node* next;
}list, *ptr;
void delete(ptr a);
void add(ptr a);
void printseat(ptr temp);
void print(ptr a);
void delete(ptr a);
int main()
{
	int i, input;
	ptr a;
	a = (ptr)malloc(1 * sizeof(list));             // dummy node 
	a->next = NULL;
	a->seat = 0;
	for (i = 0; i<100; i++)
	{
		printf("enter 1 to book a ticket and 2 for deleting a TICKETand 3 to print the chart and 4 to exit the loop \n");
		scanf("%d", &input);
		if (input == 1)
		{
			add(a);
		}
		else if (input == 2)
		{
			delete(a);
		}
		else if (input == 3)
		{
			print(a);
		}
		else if (input == 4)
		{
			break;
		}
		else
		{
			printf("not able to recognise the command \n");
		}

	}
	printf("thank you \n");
	return 0;
}
void add(ptr a)
{
	int input, input2;
	ptr temp = NULL;
	while (a->next != NULL)
	{
		a = a->next;
	}
	if (a->seat>70)
	{
		printf("train full \n");
		return;
	}
	else if (a->seat>50)
	{
		printf("%d waiting awailable \n", (a->seat) - 50);
		printf("enter 1 to exit 0 to continue ");
		scanf("%d", &input2);
		if (input2 == 1)
		{
			return;
		}
	}
	temp = (ptr)malloc(1 * sizeof(
		list));
	temp->next = NULL;
	printf("enter name ");
	scanf("%s", temp->name);
	printf("enter age ");
	scanf("%d", &temp->age);
	printf("enter sex ");
	scanf("%s", &temp->sex);
	temp->seat = (a->seat) + 1;
	printf("enter 1 to print the ticket 0 for ot to print the ticket \n");
	scanf("%d", &input);
	if (input == 1)
	{
		printseat(temp);
	}
	a->next = temp;
	return;
}
void printseat(ptr temp)
{
	if (temp->seat>50)
	{
		printf("WL=%d", (temp->seat) -
			50);
	}
	else
	{
		printf("confirm seat=%d", temp->seat);
	}
	printf(" name=%s ", temp->name);
	printf("sex=%c ", temp->sex);
	printf("age=%d \n", temp->age);
	return;
}
void print(ptr a)
{
	a = a->next;
	while (a != NULL)
	{
		printf("seat number=%d,name=%s ,age=%d,sex=%c \n", a->seat, a->name, a->age, a->
			sex);
		a = a->next;
	}
	return;
}
void delete(ptr a)
{
	int input;
	ptr temp;
	a = a->next;
	printf("enter the seat number ");
	scanf("%d", &input);
	while (a != NULL && (a->seat) !=
		input)
	{
		a = a->next;
	}
	if (a == NULL)
	{
		printf("can not delete \n");
		return;
	}
	temp = a;
	a = a->next;
	free(temp);
	while (a != NULL)
	{
		a->seat = a->seat - 1;
		a = a->next;
	}
	printf("seat deleted \n");
	return;// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
    return 0;
}

