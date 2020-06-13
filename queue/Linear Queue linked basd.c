
// Linear Queue linked basd

#include "stdlib.h"
#include "stdio.h"


typedef struct node{
	
	int data;
	struct node* next;
	
}Node;

Node* front = NULL;
Node* rear  = NULL;





char Is_Empty (void) ;
char Is_Full (void) ;
void EnQueue (int value) ;
int DeQueue (void)  ;
void Display_Queue (void) ;


void main (void) 
{
	EnQueue(10);
	EnQueue(20);
	Display_Queue() ;
	
}


/**************************************************************/
char Is_Empty (void) 
{
	if (front == NULL )
	{
		return 1 ;
	}
	else 
	{
		return 0 ;
	}
}
/**************************************************************/
char Is_Full (void) 
{
	// thereis no full case , it's dynamic 
}
/**************************************************************/
void EnQueue (int value)  // insert at last
{
	if(Is_Empty())
	{
		rear = (Node*) malloc(sizeof (Node));
		front=rear ;
		rear->data = value;
		rear->next = NULL;
	}
	else
	{
		rear->next = (Node*) malloc(sizeof (Node));
		rear = rear->next ;
		rear->data = value;
		rear->next = NULL;
		
	/*	Node*trav = head;
		while (trav->next != NULL)
			trav = trav->next;
		trav->next = temp; */ 
	}
}
/**************************************************************/
int DeQueue (void)    // delete at first 
{
	int buff = 0 ;
	if(Is_Empty())
	{
		printf("Empty_Queue");
		return -1;
	}
	else if (front == rear)
	{
		buff = front->data ;
		free (front) ;
		front = rear = NULL ; 
		return buff ;
	
	}	
	else 
	{
		Node* temp = front;
		buff = front->data ;		
		front = front -> next ;
		free(temp);

		return buff ;		
	}
	
}
/**************************************************************/
void Display_Queue (void) 
{
	if(Is_Empty())
	{
		printf("Empty_List");
		return;
	}
	printf("[Head] => ");
	Node*temp = front;
	while (temp != NULL)
	{
		printf("%d => ",temp->data);
		temp = temp->next;
	}
	printf("[NULL]");
}
/**************************************************************/






