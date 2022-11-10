#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *link;
};

struct node *head = NULL;
struct node *temp = NULL;

void insert(int data) {
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	if(head == NULL) {
		head = newNode;
		temp = newNode;
	} else {
		temp->link = newNode;
		temp = newNode;
	}
	temp->data = data;
	temp->link = NULL;
}

void delete() {
	temp = head;
	struct node *prv = head;
	
	if(head->link == NULL) {
		free(temp);
		head = NULL;
	} else {
		while(temp->link != NULL) {
			prv = temp;
			temp = temp->link;
		}
		free(temp);
		temp = prv;
		temp->link = NULL;
	} 
	
}

void print() {
	if(head == NULL) {
		print("Linked List is empty \n");
		return;
	}
	temp = head;
	while(temp->link != NULL) {
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("%d ",temp->data);
	printf("\n");
}

int findNodeNum() {
	int count = 1;
	if(head == NULL) 
		return 0;	
	temp = head;
	while(temp->link != NULL) {
		count++;
		temp = temp->link;
	}
	
	return count;
}


int main() {
	int choice;
	int value;
	while(1) {
		printf("1. Insert \n");
		printf("2. Delete \n");
		printf("3. Print \n");
		printf("4. Find node count \n");
		printf("Choice: ");
		scanf("%d", &choice);
		
		if(choice == 1) {
			printf("Enter value: ");
			scanf("%d", &value);
			insert(value);
		} else if(choice == 2) {
			delete();
		} else if(choice == 4) {
			printf("Node count: %d \n",findNodeNum());
		} else if(choice == 3) {
			print();
		}
		printf("\n--------------------------------------- \n");
	}
}

