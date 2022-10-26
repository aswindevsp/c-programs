#include <stdio.h>
int q[100];
int front = -1, rear = -1, size;

void enqueueR(int n) {
	if((front == 0 && rear == size-1) || (front == rear + 1)) {
		printf("Queue is full \n");
		return;
	} else if(rear == -1 && front == -1) {
		rear = size-1;
		front = size-1;
	} else if(rear == size-1){
		rear = 0;
	} else {
		rear++;
	}
	
	q[rear] = n;
}
void enqueueF(int n) {
	if((front == 0 && rear == size-1) || (front == rear + 1)) {
		printf("Queue is full \n");
		return;
	} else if(rear == -1) {
		front = 0;
		rear = 0;
	} else if(front == 0) {
		front = size-1;
	} else {
		front--;
	} 
	q[front] = n;
}

void dequeueR() {
	int item;
	if(front == -1) {
		printf("Queue is empty. \n");
		return;
	} else if(front == rear) {
		item = q[front];
		front = rear-1;
	} else if(rear == 0) {
		item = q[rear];
		rear = size -1;
	} else {
		item = q[rear];
		rear--;
	}
	printf("%d deleted \n", item);
}

void dequeueF() {
	int item;
	if(front == -1) {
		printf("Qeueu is empty \n");
		return;
	} else if(front == rear) {
		item = q[front];
		front = -1;
		rear = -1;
	} else if(front == size -1) {
		item = q[front];
		front = 0;
	}else {
		item = q[front];
		front++;
	}
	
	printf("%d deleted \n", item);
}

void print() {
	printf("Queue: ");
	if(front == rear) {
		printf("%d ", q[front]);
	} else if(front < rear) {
		for(int i=front; i<=rear; i++) {
			printf("%d ", q[i]);
		}
	} else {
		for(int i=front; i<size; i++) {
			printf("%d ", q[i]);
		}	
		for(int i=0; i<=rear; i++) {
			printf("%d ", q[i]);
		}
	}
	printf("\n");
}

void main() {
	size = 10;
	printf("Enter size of the queue: ");
	scanf("%d", &size);
	int choice;
	int temp; //For taking input and passing to function 
	while(1) {
		printf("1. Enqueu Front \n2. Enqueue Rear \n3. Dequeue Front \n4. Dequeue Rear \n5. Print\n");
		printf("Choice: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("Enter value: ");
				scanf("%d", &temp);
				enqueueF(temp);
				break;
			case 2:
				printf("Enter value: ");
				scanf("%d", &temp);
				enqueueR(temp);
				break;
			case 3:
				dequeueF();
				break;
			case 4:
				dequeueR();
				break;
			case 5:
				print();
				
		}
		printf("----------------------------------------------\n");
	}
}
