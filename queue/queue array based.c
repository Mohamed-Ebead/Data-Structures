/* 
* project : queue array based 
*author : Mohamed Ebead 
*
*/

#include <stdio.h>

#define MAX 5

char front = -1 ;
char rear  = -1 ;

char Queue [MAX] ;

char Is_Empty (void) ;
char Is_Full (void) ;
void InQueue (int value) ;
int DeQueue (void)  ;
void Display_Queue (void) ;


void main (void) 
{
	InQueue(10) ;
	InQueue(20) ;
	int x = DeQueue() ;
	
	printf("%d \n",x) ;  // 10
	
	Display_Queue () ;
	
	
	
}


/****************************************************************************/
char Is_Empty (void) 
{
	if ((front == -1 ) && (rear == -1 ))
	{
		return 1 ;
	}
	else 
	{
		return 0 ;
	}
}

/****************************************************************************/
char Is_Full (void)
{
	if (rear == MAX-1 )
	{
		return 1 ;
	}
	else 
	{
		return 0 ;
	}
} 
/****************************************************************************/
void InQueue (int value) 
{
	if (Is_Full())
	{
		printf("Full Queue") ;
		return ;
	}
	else 
	{
		if (Is_Empty())
		{
			Queue [0] = value ;
			front = 0 ;
			rear = 0;
		}
		else 
		{
			//rear ++ ;
			Queue[++rear] = value ;
		}
		
	}
}
/****************************************************************************/
int DeQueue (void)  
{
	if (Is_Empty())
		{
			printf("Empty Queue ") ;
			return -1 ;
		}
		else if (rear == front)  // one element in the queue
		{
			int buff = 0 ;
			buff = Queue[rear] ;
			rear = front = -1 ;
			return buff ;
		}
		else 
		{
			return Queue[front++] ;
			
		}
}
/****************************************************************************/
void Display_Queue (void) 
{
	if (Is_Empty())
	{
		printf("Empty Queue ") ;
	}
	else
	{
	char count = 0 ;
	for(count = front ; count<= rear ; count ++ ) 
	{
		printf ("%d >> ",Queue[count]) ;
	}
	}
}
/****************************************************************************/