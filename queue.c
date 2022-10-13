#include <stdio.h>
int ar[100],front=-1,rear=-1,size;
void push();
void pop();
void print();
int main() {
	int choice;
	printf("Enter the size of queue: ");
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
	if(rear>=size-1)
		printf("Queue Full\n");
	else if(rear==-1 && front==-1)
	{
		rear++;
		front++;
		printf("Enter the element: ");
		scanf("%d",&ar[rear]);
	}
	else
	{
		rear++;
		printf("Enter the element: ");
		scanf("%d",&ar[rear]);
	}
}
void pop()
{
	if(front<=-1)
		printf("Queue Empty\n");
	else if(rear==front)
	{
		printf("%d is deleted\n",ar[front]);
		rear=-1;
		front=-1;
	}
		
	else
	{
		printf("%d is deleted\n",ar[front]);
		front++;
	}
}
void print()
{
	if(front<=-1)
		printf("The queue is empty\n");
	else
	{
		printf("Current queue is: ");
	for(int i=front;i<=rear;i++)
		printf("%d  ",ar[i]);
	printf("\n"	);
	}
}