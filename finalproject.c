#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdlib.h>
#include "proj1.h"
#include "proj2.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct Node Node;
#define LINES "-----------------------------------------------------------------------------------------------------------------*\n"



/* This functions returns a pointer to the node containing the given patient's record */
/*
* Should be already sorted by increasing ID value
*
* Return the memory address of corresponding node where the ID is found
*/
struct Node * findPatientbyID(struct Node * head, unsigned int ID){
	bool isTrue = true;
	struct Node * ptr = NULL;
	struct Node * current = head;
	
	while (current!= NULL)
	{
		if (current->data.ID == ID)
		{
				ptr = current;
				isTrue = false;
		}
		if (current!= NULL)
			current = current->hook;
	}//end of while

	return ptr;   //pointer to the node containing the patient's data
}


/* Display current elements of the linked list in their current order. For each element, display the patient's name, ID, and ward number on a single line, separated by commas .  */
void displayList(struct Node * head) {
	Node * current = head;
	printf(LINES);
	//		 1        2               3    4   5    6    ||  1     2      3    4             5                                6
	printf("  |%5s  |%19s  | %10s    | %s | %s | %s |\n", "ID", "Name", "Illness", "Ward Number", "Number of Current Check-Ups", "Check-Ups History");
	printf(LINES);

	while (current != NULL){
		//		 1   2     3            4   5      ||  1                     2             3                            4                        5                               
		printf("  | %d | %19s  | %11s  | %5hu     | %30d|", current->data.ID, current->data.name, current->data.illness, current->data.wardNumber, current->data.num_checkups);
		//loops through the dates 
		size_t i = 0;
	//	6 ||   
		if (current->data.num_checkups != 0)
		{
			while (current->data.num_checkups > i)
			{
				printf(" %u/%u/%u @ %u Hr,", current->data.checkupHistory[i].month, current->data.checkupHistory[i].day, current->data.checkupHistory[i].year, current->data.checkupHistory[i].hour);
				i++;

			}//end of dates loop
			printf("\n");
		}
		else
			printf("No checkups.\n");
		current = current->hook;
	}//end of outerloop
	printf(LINES);
}//end of displayList


/* This function first calls genNewPatient, then stores the returned data in a new Node structure, and finally attaches this node at the start of the linked list */
struct Node * addNewPatient(struct Node * head) {
	Node* newPatient = (Node*)(malloc(sizeof(Node)));
	fillNewPatientData(&newPatient->data);
	newPatient->hook = head;
	head = newPatient;
	
	head = sortByID(head);
	return head;
}

/* This function first find the Node where the given patient's record is stored in the list, then deletes it from the list */
struct Node * removePatient(struct Node * head, unsigned int ID) {
	Node * current;
	Node * temp;
	if (head == NULL){
		printf("the list is empty! :( \n");
		return head;
	}
	current = findPatientbyID(head, ID);
	if (current == NULL){
		printf("That is invalid ID! :( \n");
		return head;
	}
		
	else if(current==head){
		temp = head;
		head = head->hook;
		free(temp);
	}
	else{
		temp = head;
		while (temp->hook!=current)
			temp = temp->hook;
		temp->hook = current->hook;
		free(current);
	}
	return head;
}


/* This function adds today's date and current hour as a new checkup date in the checkupHistory field of the given patient's record */
struct Node * updatePatient(struct Node * head, unsigned int ID) {
	Node * current;
	time_t rawtime;
	struct tm *currentTime;
	struct Date * currentDate;

	//imputting the current time
	time(&rawtime);
	currentTime = localtime(&rawtime);
	current = findPatientbyID(head, ID);
	/*
	currentDate=&(current->data.checkupHistory[current->data.num_checkups]);
	currentDate->day = currentTime->tm_mday;
	currentDate->month = currentTime->tm_mon;
	currentDate->year = currentTime->tm_year+1900;
	currentDate->hour = currentTime->tm_hour;
	//adjusting for the next appointment
	current->data.num_checkups++;
	*/
	
	current->data.checkupHistory[current->data.num_checkups].day = currentTime->tm_mday;
	current->data.checkupHistory[current->data.num_checkups].month = currentTime->tm_mon;
	current->data.checkupHistory[current->data.num_checkups].year = currentTime->tm_year + 1900;
	current->data.checkupHistory[current->data.num_checkups].hour = currentTime->tm_hour;
	current->data.num_checkups++;

	return head;
}


void showCheckupHistory(struct Node * head, unsigned int ID) {
	Node * current;
	int i = 0;
	current = findPatientbyID(head, ID);

	printf("\n|Patient Check-Up History|\n");
	printf("--------------------------\n");
	while (current->data.num_checkups > i)
	{
		printf("|%d/%d/%d @ %d         |\n", current->data.checkupHistory[i].month, current->data.checkupHistory[i].day, current->data.checkupHistory[i].year, current->data.checkupHistory[i].hour);
		printf("--------------------------\n");
		i++;
	}//end of dates loop


}


struct Node * sortByName(struct Node * head) {
	int done;
	struct Node *ptr;
	struct Node *tmp, *stmp;


	//Special cases: when the list contains 0 or 1 elements, then no need to sort!
	if (head == NULL || head->hook == NULL)
		return head;


	done = 0;


	while (!done)
	{
		done = 1;
		for (ptr = head; ptr->hook != NULL;)
		{
			if (strcmp(ptr->data.name, ptr->hook->data.name) > 0)
			{
				done = 0;

				if (ptr == head)
				{
					head = ptr->hook;
					tmp = head->hook;
					head->hook = ptr;
					ptr->hook = tmp;

				}
				else {
					tmp = head;
					while (tmp->hook != ptr)
						tmp = tmp->hook;
					stmp = ptr->hook->hook;
					tmp->hook = ptr->hook;
					ptr->hook->hook = ptr;
					ptr->hook = stmp;
				}

			}
			else
				ptr = ptr->hook;
		}
	}

	return head;
}

struct Node * sortByWardNumber(struct Node * head) {
	int done;
	struct Node *ptr;
	struct Node *tmp, *stmp;


	//Special cases: when the list contains 0 or 1 elements, then no need to sort!
	if (head == NULL || head->hook == NULL)
		return head;


	done = 0;


	while (!done)
	{
		done = 1;
		for (ptr = head; ptr->hook != NULL;)
		{
			if (ptr->data.wardNumber > ptr->hook->data.wardNumber)
			{
				done = 0;

				if (ptr == head)
				{
					head = ptr->hook;
					tmp = head->hook;
					head->hook = ptr;
					ptr->hook = tmp;

				}
				else {
					tmp = head;
					while (tmp->hook != ptr)
						tmp = tmp->hook;
					stmp = ptr->hook->hook;
					tmp->hook = ptr->hook;
					ptr->hook->hook = ptr;
					ptr->hook = stmp;
				}

			}
			else
				ptr = ptr->hook;
		}
	}

	return head;
}


/* This function writes the information in all patient records into a text file */
void write2File(struct Node  * head, char * filename) {
	FILE * fpr;
	Node *current = head;
	size_t j = 0;
	size_t i = 0;
	fpr = fopen(filename, "w+");

	while (current != NULL){
		fprintf(fpr, " #%d) %d %s %s %hu %d", ++j, current->data.ID, current->data.name, current->data.illness, current->data.wardNumber, current->data.num_checkups);
		//loops through the dates 
		i++;
		while (current->data.num_checkups > i)
		{
			fprintf(fpr,"%d/%d/%d @ %s, ", current->data.checkupHistory[i].month, current->data.checkupHistory[i].day, current->data.checkupHistory[i].year, current->data.checkupHistory[i].hour);


		}//end of dates loop
		fprintf(fpr, "\n");

		current = current->hook;
	}// end of the while loop
	fclose(fpr);
}


/* This function deallocates all the dynamic variables used to store the nodes of the linked list */
struct Node  * freeList(struct Node * head) {
	Node * current = head;
	Node * temp;
	while (current != NULL)
	{	
			temp = current->hook;
			free(current);
			current = temp;
	}
	return NULL;
}

