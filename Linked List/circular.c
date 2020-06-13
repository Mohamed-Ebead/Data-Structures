#include<stdio.h>
#include<stdlib.h>

void insertAtLast(int value);
void printList(void);

typedef struct node
{
	int data;
	struct node* next;
	
}node;

node* head = NULL;
void main (void)
{
	insertAtLast(10);
	insertAtLast(20);
	insertAtLast(30);
	insertAtLast(40);
	printList();
}
void printList(void)
{
	
	
	node* current = head ;
	printf("[head] =>");
	do
	{
		printf("%d => ",current->data);
		current = current->next;
		
	}
	
	while(current != head);
	
	printf("[NULL]\n");
	
}	

void insertAtLast(int value)
{
	node* temp =(node*)malloc(sizeof(node));
	temp->data = value ;
	//temp->next = NULL;
	
	//case 1
	if(head == NULL)
	{
		head = temp;
		head->next = head ;
	}
	else
	{
		node* current =head;
	while(current->next != head)
	{
		current=current->next;
		
	}
		
		current->next = temp ;
		temp->next = head ;
	}
	 
	
	
	
}