/* 3 A menu driven Program in C for the following operations on STACK of Integers (Array Implementation of Stack with maximum size MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit
 */


#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
void push(int ele, int *top, int stack[]);
void pop(int *top, int stack[]);
void display(int top, int stack[]);
int palindrome(int *top, int stack[]);
void main()
{
	int choice, top=-1, ele, flag;
	int stack[SIZE];
	for(;;)
	{
		printf("Enter\n1. Push\n2. Pop\n3. Display\n4. Palindrome\n5. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: if(top==(SIZE-1))
					printf("Stack overflow!!!\n");
				else
				{
					printf("Enter element to be pushed:\n");
					scanf("%d", &ele);
					push(ele, &top, stack);
				}
				break;
			case 2: if(top==-1)
					printf("Stack underflow!!!\n");
				else
					pop(&top, stack);
				break;
			case 3:  if(top==-1)
					printf("Stack underflow!!!\n");
				else
					display(top, stack);
				break;
			case 4: flag= palindrome(&top, stack);
				if(flag==-1)
					printf("Not a palindrome.\n");
				else
					printf("Palindrome.\n");
				break;
			case 5: exit(0);
		}
	}
}
void push(int ele, int *top, int stack[])
{
	*top+=1;
	stack[*top]= ele;
}
void pop(int *top, int stack[])
{
	printf("Element to be deleted:\n%d\n", stack[*top]);
	*top-=1;
}
void display(int top, int stack[])
{
	int i;
	printf("Elements are:\n");
	for(i=top; i>=0; i--)
		printf("%d\t", stack[i]);
	printf("\n");
}
int palindrome(int *top, int stack[])
{
	int temp[SIZE], i, j, count=0;
	for(j=0; *top>=0; j++)
	{
		temp[j]= stack[(*top)--];
		count+=1;
	}
	for(i=0; i<=count/2; i++)
	{
		if( temp[i]!=temp[count-i-1])
			return -1;
	}
	return 1;
}
