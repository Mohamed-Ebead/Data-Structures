#include "stdlib.h"
#include "stdio.h"



typedef struct node{
	char data;
	struct node* next;
}Node;
Node* head = NULL;

void Insert_At_Last(char data)
{
	Node*temp = (Node*) malloc(sizeof (Node));
	temp->data = data;
	
	if(head == NULL)
	{
		head = temp;
		temp->next = head;
		return;
	}
	else
	{
		Node*trav = head;
		while (trav->next != head)
			trav = trav->next;
		trav->next = temp;
		temp->next = head;
	}
}
void DisplayList ()
{
	if(head == NULL)
	{
		printf("Empty_List");
		return;
	}
	printf("[Head] => ");
	Node*trav = head;
	do
	{
		printf("%d => ",trav->data);
		trav = trav->next;
	}
	while (trav != head);
	printf("[Head]");
}
void main ()
{
	Insert_At_Last(1);
	Insert_At_Last(23);
	DisplayList();
}