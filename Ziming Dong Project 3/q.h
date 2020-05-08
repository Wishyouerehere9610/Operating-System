#include <stdio.h>
#include <stdlib.h>
#include "tcb.h"

TCB_t* NewItem(void) {
	TCB_t* item;
	item = (TCB_t*)malloc(sizeof(TCB_t));
	item->payload = 0;
	item->next = NULL;
	item->prev = NULL;
	return item;
}

void InitQueue(TCB_t *head)
{
	TCB_t *firstNode = NewItem();
	head = firstNode;
	return;
}

void addQueue(TCB_t *head, TCB_t *item){
	
	      
	
	if (head->next == NULL) {
		
		head->next = item;
		item->prev = head;
		item->next = NULL;
	}
	else
	{
		
		TCB_t *temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = item;
		item->prev = temp;
		item->next = NULL;
	}
	
	return;
}
void printQueue(TCB_t *head)
{
	if (head->next == NULL)
	{
		
	}
	else {
		TCB_t* temp = head;
		while (temp != NULL)
		{
			
			temp = temp->next;
		}
	}
}
TCB_t* DelQueue(TCB_t *head)
{
	if (head == NULL) {
		
		return (NULL);
	}
	if (head->next == NULL)
	{
		
		TCB_t *temp = NewItem();
		temp->payload = head->payload;
		temp->next = head->next;
		temp->prev = head->prev;
		return temp;
	}
	else
	{
		TCB_t* temp2 = NewItem();

		temp2->payload = head->payload;
		temp2->next = head->next;
		temp2->prev = head->prev;
		return temp2;
	}

}
void rotateQ(TCB_t* head)
{

	if (head == NULL)
	  return;
	
	TCB_t *headNode = NewItem();
	headNode->payload = head->payload;
	headNode->context = head->context;
	head = head->next;
	
	addQueue(head, headNode);
}
