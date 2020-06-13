#include<stdio.h>

#define MAX 	2
#define TRUE	1
#define FALSE	0

typedef char uint8;
typedef int  uint32;

/*functions Prototypes*/
uint8 is_empty(void);
uint8 is_full(void);
void push(uint32 a_data);
void pop(void);
void display(void);

uint8 top=-1;

uint8 stack[MAX];

int main(void)
{
	push(1);
	push(2);
	push(3);
//	display();
	pop();
	display();
	
	return 0;
}

uint8 is_empty(void)
{
	uint8 flag=FALSE;
	
	if(top==-1){
		flag=TRUE;
	}
	else{}
	return flag;
}


uint8 is_full(void)
{
	uint8 flag=FALSE;
	
	if(top==(MAX-1)){
		flag=TRUE;
	}
	else{}
	return flag;
}

void push(uint32 a_data)
{
	uint8 ovf_flag=is_full();
	
	if(ovf_flag==TRUE){
		printf("\nstack overflow\n");
	}
	else{
		top++;
		stack[top]=a_data;
	}
}

void pop(void)
{
	uint8 empty_flag=is_empty();
	
	if(empty_flag==TRUE){
		printf("\nstack is empty\n");
	}
	else{
		top--;
	}
}

void display(void)
{
	uint8 count=0;
	uint8 empty_flag=is_empty();
	
	if(empty_flag==TRUE){
		printf("\n stack ");
	}
	else{
		for(count=0;count<=top;count++){
			printf("%d\t",stack[count]);
		}
	}
}