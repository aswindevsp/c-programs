#include <stdio.h>
int ar[100],top=-1,size;
void push();
void pop();
void print();
int main() {
	int choice;
	printf("Enter the size of stack: ");
	scanf("%d",&size);
	while(1) {
		printf("1. Push  ");
		printf("2. Pop  ");
		printf("3. Print \n");
		printf("Choice: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				print();
				break;
			default:
				printf("Invalid Input\n");
		}
	}
}
void push()
{
	if(top>=size-1)
		printf("Stack Full\n");
	else
	{
		top++;
		printf("Enter the element: ");
		scanf("%d",&ar[top]);
	}
}
void pop()
{
	if(top<=-1)
		printf("Stack Empty\n");
	else
	{
		printf("%d is deleted\n",ar[top]);
		top--;
	}
}
void print()
{
	if(top<=-1)
		printf("The stack is empty\n");
	else
	{
		printf("Current stack is: ");
	for(int i=0;i<=top;i++)
		printf("%d  ",ar[i]);
	printf("\n"	);
	}
}