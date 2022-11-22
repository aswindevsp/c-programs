#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *temp = NULL;
struct node *head = NULL;
struct node *prv = NULL;

void insert() {
	int data;
	printf("Enter value: ");
	scanf("%d", &data);
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	if(head == NULL) {
		head = newNode;
		temp = newNode;
	} else {
		temp = head;
		while(temp->link != NULL) {
			temp = temp->link;
		}
		temp->link = newNode;
		temp = newNode;
	}
	temp->data = data;
	temp->link = NULL;
}

void delete() {
	if(head == NULL) {
		printf("Linkedlist is empty\n");
		return;
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
		printf("Queue Empty\n");
	} else {
		printf("Queue elements: ");
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
		printf("1. Insert \n");
		printf("2. Delete \n");
		printf("3. Print \n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("\n");
				insert();
				break;
			case 2:
				printf("\n");
				delete();
				break;
			case 3:
				printf("\n");
				print();
				break;
		}
		printf("------------------------------------------\n");
	}
}
