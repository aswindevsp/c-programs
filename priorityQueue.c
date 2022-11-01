#include <stdio.h>
struct node{
	int item;
	int priority;
};

struct node q[100];
int size, front = -1, rear= -1;

void sort() {
	for(int i=front; i<=rear; i++) {
		for(int j=front; j<rear; j++) {
			if(q[j].priority < q[j+1].priority) {
				struct node temp = q[j];
				q[j] = q[j+1];
				q[j+1] = temp;
			}
		}
	}
}
void enqueue() { 
	int n, p;
	if(rear == size -1) {
		printf("Queue is full \n");
		return;
	} else if(front == -1) {
		front = 0;
		rear = 0;
	} else {
		rear++;
	}
	
	printf("Enter value and priority: ");
	scanf("%d %d", &n, &p);
	q[rear].item = n;
	q[rear].priority = p;
}

void dequeue() {
	sort();
	if(front == -1) {
		printf("Queue is empty");
		return;
	} else if(front == rear) {
		front = rear = -1;
	} else { 
		front++;
	}
}

void printQueue() {
	sort();
	if(front == -1)
		return;
	
	printf("Priority : ");
	for(int i=front; i<=rear; i++) {
		printf("%d ", q[i].priority);
	}
	printf("\n");
	printf("Value    : ");
	for(int i=front; i<=rear; i++) {
		printf("%d ", q[i].item);
	}
	
	printf("\n");
}

void main() {
	printf("Enter size of the queue: ");
	scanf("%d", &size);
	
	int choice;
	
	
	while(1) {
		printf("1. Enqueue \n");
		printf("2. Dequeue \n");
		printf("3. Print \n");
		printf("4. Exit\n");
		printf("Choice: ");
		
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				printQueue();
				break;
		}
		
		printf("-------------------------------------------------------------\n");
		
	}		 
}
