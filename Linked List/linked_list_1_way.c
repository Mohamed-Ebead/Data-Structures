#include<stdio.h>
#include<stdlib.h>

void insertAtLast(int value);
void insertAtFirst(int value);
void insert_MiD(int pos ,int value);
void search(int value);
void update_value (int old_data , int new_data);
void update_position (int position , int new_data);
void delet_first(void);
void delet_last(void);
void delet_Mid(int pos );
void printList(void);

typedef struct node
{
	int data;
	struct node* next;
	
}node;

node* head = NULL;

void main (void)
{
	insertAtLast(20);
	insertAtLast(30);
	insertAtLast(40);
	insertAtLast(20);
	printf("the list before any operaation\n ");
	printList();
	//search(20);
	
	//update(20,33);
	//update(40,100);
    //update_position(10,1);
	//insert_MiD(2,55);
	
	delet_Mid(1);
    printf("\n\nthe list after any operaation\n ");
	printList();
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


//problem
void insertAtLast(int value)
{
	node* temp =(node*)malloc(sizeof(node));
	temp->data = value ;
	temp->next = NULL;
	
	//case 1
	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		node* current =head;
	while(current->next != NULL)
	{
		current=current->next;
		
	}
		
		current->next = temp ;
	}
	 
	
	
	
}

//done
void insertAtFirst(int value)
{
	//case 1
	if(head == NULL)
	{
		head=(node*)malloc(sizeof(node));
		head->data = value ;
		head->next = NULL;
	}
	
	//case2
	else
	{
	    node* temp =(node*)malloc(sizeof(node));
		temp->next = head;
		temp->data = value ;
		head = temp ;
	
	}
}

void insert_MiD(int pos ,int value)
{
	node* temp = head ;
	
	int cnt =1;
	//at least we have 2 nodes 
	if(head == NULL || head->next ==NULL)
	{
	printf("the list less than 3 element")	;
	}
	else
	{
		while(cnt <(pos-1))
		{
			cnt ++ ;
			temp = temp->next ;
		}
		node* New_Node = (node*)malloc(sizeof(node));
		New_Node->data = value ;
		New_Node->next = temp->next ;
		temp->next = New_Node ;
	}
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
		free(temp);
	}
}
void delet_Mid(int pos )
{
	node* temp = head ;
	node* del = NULL;
	int cnt =1;
	//at least we have 2 nodes 
	if(head == NULL || head->next ==NULL)
	{
	printf("the list less than 3 element")	;
	}
	else
	{
		while(cnt <(pos-1))
		{
			cnt ++ ;
			temp = temp->next ;
		}
		del = temp->next ;
		temp->next = del->next ;
		free(del);
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
		free(del);
	}
}

void search(int value)
{
	node* temp = head ;
	int pos =0 ;
	int flag = 0;
	if(head == NULL)
	{
		printf("empty list");
		return ;
	}
	while(temp !=NULL)
	{
		pos++ ;
		if(temp->data == value)
		{
			flag= 1;
			printf("the value %d is at position %d",value,pos);
			
		}
		temp = temp->next ;
	}
	if(temp == NULL && flag ==0)
	{
		printf("this value is'nt in the list");
	}
}


void update_value (int old_data , int new_data)
{
	node* temp = head ;
	int pos =0 ;
	int flag = 0;
	if(head == NULL)
	{
		printf("empty list");
		return ;
	}
	while(temp !=NULL)
	{
		pos++ ;
		if(temp->data == old_data)
		{
			flag= 1;
			temp->data = new_data ;
			printf("\nthe old_value %d is at position %d\n",old_data,pos);
			
		}
		temp = temp->next ;
	}
	if(temp == NULL && flag ==0)
	{
		printf("this value is'nt in the list");
	}
}


void update_position (int position , int new_data)
{
	node* temp = head ;
	int count =1 ;
	int flag = 0;
	if(head == NULL)
	{
		printf("empty list");
		return ;
	}
	while(count <  position)
	{
		count ++; 
		temp = temp->next ;
		if(temp == NULL)
		{
			flag =1 ;
			printf("the list is'nt include this position");
		    return ;
		}
		
		
	}
	temp->data = new_data ;
	
}








