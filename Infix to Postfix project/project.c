#include <stdio.h>


#define MAX 7

#define IS_OPERATOR 0 
#define IS_OPERAND  1
#define IS_SPACE    2 


	char CheckOperationValidity (void) ; 
	char OperandOrOperator ( char Input ) ;
	char GetPriority (char Operator ) ;
	char InFix [MAX] = { 0 };
	char PostFix[MAX] = { 0 };
	char PstIndex = 0 ;

	char StartWithOperator = 0 ;
	char EndWithOperator = 0 ;
	char SyntaxError = 0 ;
	char AcceptedOperation = 0 ;
	char Index = 0;
	
	
	/*--------------------------------*/
	
	char top = -1 ;

	char Stack [MAX] ;

	char Stack_Is_Empty (void) ;
	char Stack_Is_Full (void) ;
	void PushToStack (char value) ;
	char PopFromStack (void)  ;
	void Display_Stack (void) ;
	
	/*--------------------------------*/
	
	
	
	
	
	
	
	
	
	

void main (void) 
{
	
	
	printf("Please Enter The arethmetic operation of %d element \n" , MAX);
	for (Index=0 ; Index<MAX ; Index++)
	{
		scanf("%c",&InFix[Index]);
	}
	
	printf("Arethmetic operation in one line without spaces  : \n");
	for (Index=0 ; Index<MAX ; Index++)
	{
		printf("%d >> ",InFix[Index]);
	}
	
	
	/*
	char y = (int)InFix[0] ;
	if (y == 50 )
	{
		printf("TRUE");
	}
*/

/**************************************************************************************/

		char y = CheckOperationValidity () ; 

	
	printf ("\n StartWithOperator = %d \n " , StartWithOperator ) ;
	printf (" EndWithOperator = %d \n " , EndWithOperator ) ;
	printf (" SyntaxError = %d \n " , SyntaxError ) ;
	printf (" AcceptedOperation = %d \n " , AcceptedOperation ) ;

	printf ("\n/***********************/\n") ;


/*
	for (Index=0 ; Index<MAX ; Index++)
	{
		char x = OperandOrOperator ( InFix[Index] ) ;
		
		printf("%d >> ",x);
	}
*/


	if (Stack_Is_Empty())
	{
		char TypeOfInput = IS_SPACE ; 
		
		for (Index=0; Index < MAX ; Index++)
		{
			TypeOfInput = OperandOrOperator(InFix[Index]) ;
			
			switch (TypeOfInput)
			{
				case IS_OPERAND :
				{
					PostFix[PstIndex] = InFix[Index] ;
					PstIndex++ ;
					break ;
				}
				case IS_OPERATOR :
				{
					
					else if (Stack_Is_Empty())
					{
						PushToStack ( InFix[Index] ) ;
					}
					else 
					{
						if ( (GetPriority( Stack [top]) ) > GetPriority (InFix[Index]))    
						{
							PushToStack ( InFix[Index] ) ;
						}
						else 
						{
							PostFix[PstIndex] = PopFromStack() ;
							PstIndex++ ;
							PushToStack ( InFix[Index] ) ;
						}
					}
					
					
					
					
					break ;
				}
				case IS_SPACE :
				{
					break ;
				}
				default :
				{
					break ; 
				}
					
			}
			
			
			}
				
		}
			
			
while (PstIndex <MAX)
{
	PostFix[PstIndex] = PopFromStack () ;
	PstIndex ++ ;
}
		

		
for (Index=0 ; Index<MAX ; Index++)
	{
		printf("%c >> ",PostFix[Index]);
	}
printf("\n----------------------\n");
Display_Stack ();

		
		
	}












char CheckOperationValidity (void) 
{
	
		
	if ( ((int)InFix[0] >=48 ) && ((int)InFix[0] <=57 ) )
	{
		StartWithOperator = 0 ;      // started the operation with a number 
	}
	else 
	{
		StartWithOperator = 1 ;      // started the operation with an arethmetic operator 
	}
	
/****************************************************************************************/
	
	if ( ((int)InFix[MAX-1] >=48 ) && ((int)InFix[MAX-1] <=57 ) )
	{
		EndWithOperator = 0 ;      // started the operation with a number 
	}
	else 
	{
		EndWithOperator = 1 ;      // started the operation with an arethmetic operator 
	}
	
/****************************************************************************************/	

	
	for (Index = 1 ; Index < MAX ; Index ++ )
	{
		if ( (( (int)InFix[Index] >=48 ) && ((int)InFix[Index] <=57 )) || (( (int)InFix[Index-1] >=48 ) && ((int)InFix[Index-1] <=57 ))  ) 
		{
			//SyntaxError = 0 ;
		}
		else 
		{
			SyntaxError = 1 ;
		}
	}
	
	AcceptedOperation = ( ! StartWithOperator ) && ( ! SyntaxError ) && (! EndWithOperator) ;
	
	return AcceptedOperation ;
	
}




char OperandOrOperator (char Input ) 
{
	if ( ((int)Input >=48 ) && ( ((int)Input) <= 57 )  )
	{
		return IS_OPERAND ; 
	}
	else if ((int)Input == 32)
	{
		return IS_SPACE ;
	}
	else 
	{
		return IS_OPERATOR ; 
	}

}


char GetPriority (char Operator ) 
{
	if ((Operator == '(') || (Operator == ')')  )
	{
		return 1 ;
	}
	else if ((Operator == '*') || (Operator == '/') )
	{
		return 2 ;
	}
	else if ((Operator == '+') || (Operator == '-'))
	{
		return 3 ;
	}
	else 
	{
		printf("didnot recognize operator");
	}
}



/*-----------------------------------------------------------------------------------------*/


char Stack_Is_Empty (void) 
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


char Stack_Is_Full (void) 
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


void PushToStack (char value) 
{
	if (Stack_Is_Full())
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


char PopFromStack (void) 
{
	if (Stack_Is_Empty())
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
	if (Stack_Is_Empty()) 
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








