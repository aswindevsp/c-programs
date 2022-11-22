#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *temp = NULL;
struct node *head = NULL;
struct node *prv = NULL;

void push() {
	int data;
	printf("Enter data: ");
	scanf("%d", &data);
	
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = data;
	
	if(head == NULL) {
		head = newNode;
		head->link = NULL;
	} else {
		newNode->link = head;
		head = newNode;
	}
}

void pop() {
	if(head == NULL) {
		printf("Stack is empty\n");
	} else if(head->link == NULL) {
		free(head);
		head = NULL;	
	} else {
		temp = head;
		head = head->link;
		free(temp);
	}
}

void print() {
	
	if(head == NULL) {
		printf("Stack Empty\n");
	} else {
		printf("Stack elements: ");
		temp = head;
		while(temp->link != NULL) {
			printf("%d ", temp->data);
			temp = temp->link;
		}
		printf("%d \n", temp->data);
	}
}


int main() {
	int choice;
	while(1) {
		printf("1. Push \n");
		printf("2. Pop \n");
		printf("3. Print \n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("\n");
				push();
				break;
			case 2:
				printf("\n");
				pop();
				break;
			case 3:
				printf("\n");
				print();
				break;
		}
		printf("------------------------------------------\n");
	}
}
