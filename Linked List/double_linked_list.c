#include<stdio.h>
#include<stdlib.h>


void insertAtFirst(int value);
void insert_At_last(int value);

void printList(void);
void delet_first(void);
void delet_last(void);

typedef struct node
{
	struct node* prev ;
	int data;
	struct node* next;
	
}node;

node* head = NULL;



void main(void)
{
	insertAtFirst(10);
	insertAtFirst(20);
	insertAtFirst(30);
	insertAtFirst(40);
	printf("the list before any operaation\n ");
	printList();
	//delet_first();
	//delet_last();
	insert_At_last(90);
	printf("\n\nthe list after any operaation\n ");
	printList();
	
}
void insertAtFirst(int value)
{
	node* temp =(node*)malloc(sizeof(node));
	
	temp->data = value ;
	temp->next = head;
	temp->prev = NULL ;
	head = temp ;
}
void printList(void)
{
	
	
	node* current = head ;
	printf("[head] =>");
	
	while(current != NULL)
	{
		printf("%d => ",current->data);
		current = current->next;
		
	}
	printf("[NULL]\n");
	
}	

void delet_first(void)
{
	node* temp =NULL;
	if(head == NULL)
	{
		printf("list is empty");
		return;
	}
	else
	{
	    temp = head ;
		head =head->next;
		head->prev =NULL ;
		free(temp);
	}
}


void delet_last(void)
{
	node* temp =NULL;
	node* del =NULL;

	if(head == NULL)
	{
		printf("list is empty");
		return;
	}	
	else if(head->next == NULL)
		{
			free(head);
			head = NULL;
		}
		
	else
	{ 
		//refere to pre last node
		node* temp =head;
		while(temp->next->next !=NULL)
		{
		 temp =temp->next;
		}
		del = temp->next ;
		temp->next =NULL;
		temp->prev =temp->next->next ;
		free(del);
	}
}

void insert_At_last(int value)
{
	node* temp =(node*)malloc(sizeof(node));
	temp->data = value ;
	temp->next = NULL;
	
	//case 1
	if(head == NULL)
	{
		head = temp;
		temp-> prev =NULL ;
		return ;
	}
	else
	{
		node* current =head;
	while(current->next != NULL)
	{
		current=current->next;
		
	}
		
		current->next = temp ;
		temp->prev= current ;
	}
	 
	
}




