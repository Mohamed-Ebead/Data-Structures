#include "stdlib.h"
#include "stdio.h"



typedef struct node{
	char data;
	struct node* next;
	struct node* prev;
}Node;
Node* head = NULL;


void Insert_At_First (char data)
{
	Node*temp = (Node*) malloc (sizeof(Node));
	temp->next = head;
	temp->data = data;
	temp->prev = NULL;
	head = temp;
}
void Insert_At_Last(char data)
{
	if(head == NULL)
	{
		Node*temp = (Node*) malloc(sizeof (Node));
		temp->data = data;
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
	}
	else
	{
		Node*temp = (Node*) malloc(sizeof (Node));
		temp->data = data;
		temp->next = NULL;
		Node*trav = head;
		while (trav->next != NULL)
			trav = trav->next;
		trav->next = temp;
		temp->prev = trav;
	}
}
void Delete_At_First()
{
	if(head == NULL)
	{
		printf("Empty_List");
		return;
	}		
	Node* temp = head;
	head = head->next;
	head->prev = NULL;
	free(temp);
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
	while (trav != NULL)
	{
		printf("%d => ",trav->data);
		trav = trav->next;
	}
	printf("[NULL]");
}
void main ()
{
	Insert_At_First(50);
	Insert_At_First(40);
	Insert_At_First(30);
	Insert_At_First(10);
	Insert_At_First(80);
	Insert_At_Last(92);
	Delete_At_First();
	DisplayList();
}