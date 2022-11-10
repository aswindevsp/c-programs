#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *link;
};

struct node *head = NULL;
struct node *temp = NULL;

void insertRear() {
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

void insertFront() {
	int data;
	printf("Enter value: ");
	scanf("%d", &data);
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	if(head == NULL) {
		head = newNode;
		
		head->link = NULL;
		head->data = data;
	} else {
		newNode->link = head;
		newNode->data = data;
		
		head = newNode;
		
	}
}

void insertAfter() {
	if(head == NULL){
		printf("LinkedList is empty \n");
		return;
	}
	
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	
	int after, data;
	printf("Insert after: ");
	scanf("%d", &after);
	
	printf("Value to insert: ");
	scanf("%d", &data);
	
	temp = head;
	while(temp != NULL) {
		if(temp->data == after) {
			newNode->link = temp->link; //Connecting newNode
			temp->link = newNode;  //Connectingn newNode
			
			temp = newNode;
			temp->data = data;
		}
		temp = temp->link;
	}
	
}


void print() {
	if(head == NULL) {
		printf("Linked List is empty \n");
		return;
	}
	
	printf("Elements: ");
	temp = head;
	while(temp->link != NULL) {
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("%d ",temp->data);
	printf("\n");
}

void deleteFront() {
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

void deleteRear() {

	if(head == NULL) {
		printf("Linkedlist is empty\n");
		return;
	}
	
	
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

void deleteAt() {
	if(head == NULL) {
		printf("Linked list is empty \n");
		return;
	}
	int at, data;
	printf("Delete value: ");
	scanf("%d", &at);

	
	temp = head;
	struct node *prv;
	prv = head;
	
	while(temp->data != at) {
		prv=temp;
		temp = temp->link;
	}
	
	prv->link = temp->link;
	free(temp);	
	
	
}


int main() {
	int choice;
	int value;
	while(1) {
		printf("1. Insert from front \n");
		printf("2. Insert from rear \n");
		printf("3. Insert after a specific node \n");
		printf("4. Delete from front \n");
		printf("5. Delete from rear \n");
		printf("6. Delete a specific node \n");
		printf("7. Display linkedlist\n");
		printf("Choice: ");
		scanf("%d", &choice);
		
		if(choice == 1) {
			insertFront();
		} else if(choice == 2) {
			insertRear();
		} else if(choice == 3) {
			insertAfter();
		} else if(choice == 4) {
			deleteFront();
		} else if(choice == 5) {
			deleteRear();
		} else if(choice == 6) {
			deleteAt();
		} else if(choice == 7) {
			print();
		}
		printf("\n--------------------------------------- \n");
	}
}

