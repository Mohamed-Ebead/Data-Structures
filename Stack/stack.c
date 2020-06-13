#include <stdio.h>
#define MAX 5

char top = -1 ;

char Stack [MAX] ;

char Is_Empty (void) ;
char Is_Full (void) ;
void Push (int value) ;
int Pop (void)  ;
void Display_Stack (void) ;


void main (void )
{
	
	Push(10) ;
	Push(20) ;
	//Pop () ;
	//Push(40) ;
	//Push(50) ;
	//Push(60) ;
	//Push(70) ;
	//Push(80) ;
	
	

	
Display_Stack ();
	
	
	//int x =	Pop() ;

printf ("pop == %d",Stack[top]) ; 


}



char Is_Empty (void) 
{
	if (top == -1)
	{
		return 1 ;
	}
	else 
	{
		return 0 ;
	}
}


char Is_Full (void) 
{
	if (top == MAX-1)
	{
		return 1 ;
	}
	else 
	{
		return 0 ;
	}
	
}


void Push (int value) 
{
	if (Is_Full())
	{
		printf ("Stack Over Flow ") ;
		return ; 
	}
	else 
	{
		top ++ ;
		Stack [top] = value ;
	}
}


int Pop (void) 
{
	if (Is_Empty())
	{
		printf (" Empty Sack") ;
		return 0 ; 
	}
	else 
	{
		top -- ;         // return stack[top--] ;
		return Stack [top+1]  ; 
	}
}



void Display_Stack (void) 
{
	if (Is_Empty()) 
	{
		printf("Empty Stack") ;
		return ;
	}
	else
	{
		char count = 0 ;
		for (count =0 ; count<=top ; count ++ )
		{
			printf("%d >>" , Stack[count]) ;
		}
		
	}
	
	
}





