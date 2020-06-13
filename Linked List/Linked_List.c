
#include <stdio.h>
#include <stdlib.h>


 

typedef node {
	
	char data ;
	struct node * next ;
	
} node ; 
	

	node *head = NULL ; 
	
	void insert_at_end (char value) 
	{
		node * temp = (node * ) malloc (sizeof(node)) ;
		temp->data = value ;
		temp->next = NULL ;
		
		if (head == NULL)          // if the list is empty 
		{
			head = temp ;                  // the node points to NULL
			return ; 
		}
		else 
		{			
			while (temp->next!=NULL)
			{
				temp = temp->next ; 
			}
			
			temp->next = temp ;
			
		}
		
		
		
	}
	
	
void display_List (void )

{
	node * current = head ; 
	printf("[head] >> ");
	
	while (current != NULL)
	{
		printf (" %d >> " , current->data);
		current=current->next ; 
	}
	
		printf("[NULL]. /n");

}





void main (void) 
{
	insert_at_end(10) ;
	insert_at_end(20) ;
	insert_at_end(30) ;
	
	
display_List () ;
	
	
	
	
	
	
}
