#include "stdlib.h"
#include "stdio.h"



typedef struct node{
	char data;
	struct node* next;
}Node;
Node* head = NULL;

void Insert_At_First(char data)
{
	Node*temp = (Node*) malloc(sizeof (Node));
	temp->data = data;
	temp->next = head;
	head = temp;
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
	free(temp);
}

void Insert_At_Last (char data)
{
	if(head == NULL)
	{
		Node*temp = (Node*) malloc(sizeof (Node));
		temp->data = data;
		temp->next = NULL;
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
	}
}

void Delete_At_Last()
{
	if(head == NULL)
	{
		printf("Empty_List");
		return;
	}
	else if(head -> next == NULL)
	{
		free(head);
		head = NULL;
		return;
	}
	Node* temp = head;
	Node* Delete = NULL;
	
	while (temp->next->next != NULL)
		temp = temp->next;
	Delete = temp->next;
	temp->next = NULL;
	free(Delete);
	
}

void Insert_At_Mid(char data, char position)
{
	if((head == NULL) || (position <= 1))
	{
		printf("Invalid Position OR It's An Empty_List");
		return;
	}
	else if((head ->next == NULL))
	{
		printf("The List has only 2 Elements");
		return;
	}
	else
	{
		char pos = 1;
		Node*trav = head;
		while(trav != NULL)
		{
			pos++;
			if((pos == position) && (trav -> next != NULL))
			{
				Node* link = (Node*)malloc(sizeof(Node));
				link -> data = data;
				link -> next = trav->next;
				trav -> next = link;
				return;
			}
			trav = trav->next;
		}
		printf("Invalid Position Please enter a valid one");
	}
}
void SearchList(char data)
{
	if(head == NULL)
	{
		printf("Empty_List");
		return;
	}
	char pos = 0;
	char flag = 0;
	Node*trav = head;
	while (trav != NULL)
	{
		pos++;
		if(trav->data == data)
		{
			printf("The value is at pos %d\n",pos);
			flag = 1;
		}
		trav = trav->next;
	}
	if(flag == 0)
	{
		printf("Data can't be found\n");
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
	while (trav != NULL)
	{
		printf("%d => ",trav->data);
		trav = trav->next;
	}
	printf("[NULL]");
}

void UpdateList (char new_data, char position)
{
	if(head == NULL)
	{
		printf("Empty_List");
		return;
	}
	else if((head ->next == NULL) && (position > 1))
	{
		head->data = new_data;
		return;
	}
	char pos = 0;
	char flag = 0;
	Node*trav = head;
	while (trav != NULL)
	{
		pos++;
		if(pos == position)
		{
			trav->data = new_data;
			return;
		}
		trav = trav->next;
	}
	printf("Out of Position\n");
}
void main()
{
	Insert_At_First(20);
	Insert_At_First(30);
	Insert_At_First(40);
	Insert_At_First(50);
	Insert_At_Mid(70,4);
	//Insert_At_Mid(70,6);
	//UpdateList(80,1);
	//UpdateList(100,10);
	//SearchList(20);
	DisplayList();
}