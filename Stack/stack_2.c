
#include <stdio.h>
#include <stdlib.h>



void Stack_Push(char u8_data);
int Stack_Pop(void);
void Stack_Print(void);


typedef struct Node_Single
{
	char data;
	struct Node_Single* next;
	
}Node_Single;

Node_Single* TopOfStack = NULL;




void main (void) 
{
	Stack_Push (10);
	Stack_Push (20);
	Stack_Push (30);
	Stack_Print();
	int x = Stack_Pop() ;
	printf("%d",x) ;
}

void Stack_Push(char u8_data)
{
	Node_Single* temp =(Node_Single*)malloc(sizeof(Node_Single));
	temp->data = u8_data ;
	temp->next = NULL;
	
	//case 1
	if(TopOfStack == NULL)
	{
		TopOfStack = temp;
	}
	else
	{
		Node_Single* current =TopOfStack;
	while(current->next != NULL)
	{
		current=current->next;
		
	}
		
		current->next = temp ;
	}
	 
}



int Stack_Pop(void) 
{
	Node_Single* temp =NULL;
	Node_Single* del =NULL;

	if(TopOfStack == NULL)
	{
		printf("list is empty");
		return 0 ;
	}	
	else if(TopOfStack->next == NULL)
		{
			int data = TopOfStack->data ; 
			free(TopOfStack);
			TopOfStack = NULL;
			
			return data ; 
		}
		
	else
	{ 
		//refere to pre last node
		Node_Single* temp =TopOfStack;
		while(temp->next->next !=NULL)
		{
		 temp =temp->next;
		}
		
		del = temp->next ;
		int data = del->data ; 
		temp->next =NULL;
		free(del);
		
		return data ;
	}
}




void Stack_Print(void)
{
	Node_Single* current = TopOfStack ;
	printf("[head] =>");
	
	while(current != NULL)
	{
		printf("%d => ",current->data);
		current = current->next;
		
	}
	printf("[NULL]\n");
	
}