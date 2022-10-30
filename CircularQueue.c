#include <stdio.h>
int q[100], front = -1, rear = -1;
int count = 0;
int size;

void enqueue(int n) {
	if((rear+1) % size == front) {
		printf("Queue is full \n");
		return;
	} else if((rear == -1) || (front == -1)) {
		front = rear = 0;
	} else {
		rear = (rear+1) % size;
	}
	count++;
	q[rear] = n;
	printf("\n");
}

void dequeue() {
	int item;
	if(rear == front && rear == -1) {
		printf("Queue is empty");
	} else {
		count--;
		item = q[front]
		printf("%d deleted \n\n", q[front]);
		if(rear == front) {
			front = rear = -1;
		} else {
			front = (front + 1) % size;
		} 
	}
	printf("\n");
}

void printQueue() {
	for(int i=front; i<front+count; i++) {
		if(i < size) {
			printf("%d ", q[i]);
		} else {
			printf("%d ", q[(i)%size]);
		}	
	}
	printf("\n\n");
}

int main() {
	printf("Enter the size of Circular Queue: ");
	scanf("%d", &size);
	int temp;
	int choice;
	while(1) {
		printf("1.Enqueue \n");
		printf("2.Dequeue \n");
		printf("3.Print \n");
		printf("Choice: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("Enter value: ");
				scanf("%d",&temp);
				enqueue(temp);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				printQueue();
				break;
				
		}
		
	}
}
