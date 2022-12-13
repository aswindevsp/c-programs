#include <stdio.h>
#include <stdlib.h>
struct node
{
	int coe;
	int exp;
	struct node *link;
};

struct node *temp = NULL;
struct node *temp2 = NULL;

void insertRear(int coe, int exp, struct node **p)
{

	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->coe = coe;
	newNode->exp = exp;
	newNode->link = NULL;

	if (*p == NULL)
	{
		*p = newNode;
	}
	else
	{
		temp = *p;
		while (temp->link != NULL)
		{
			temp = temp->link;
		}
		temp->link = newNode;
	}
}

void inputPoly(struct node **p)
{
	int maxPower;
	printf("Enter the max power of polynomial: ");
	scanf("%d", &maxPower);

	int temp;
	for (int i = maxPower; i >= 0; i--)
	{

		printf("Enter coefficent of x^%d: ", i);
		scanf("%d", &temp);

		insertRear(temp, i, &(*p));
	}
}

void printPoly(struct node **p)
{

	if (*p == NULL)
	{
		printf("Huh! No polyomial here \n");
		return;
	}

	printf("Polynomial: ");
	temp = *p;
	while (temp->link != NULL)
	{
		printf("%dx^%d + ", temp->coe, temp->exp);
		temp = temp->link;
	}
	printf("%dx^%d", temp->coe, temp->exp);
	printf("\n");
}

void polyAdd(struct node **p1, struct node **p2)
{
	struct node *rHead = NULL;
	struct node *r = NULL;
	struct node *a = *p1;
	struct node *b = *p2;

	while (a != NULL && b != NULL)
	{
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		newNode->link = NULL;
		if (a->exp == b->exp)
		{
			newNode->exp = a->exp;
			newNode->coe = (a->coe + b->coe);
			a = a->link;
			b = b->link;
		}
		else if (a->exp > b->exp)
		{
			newNode->exp = a->exp;
			newNode->coe = a->coe;
			a = a->link;
		}
		else
		{
			newNode->exp = b->exp;
			newNode->coe = b->coe;
			b = b->link;
		}

		if (rHead == NULL)
		{
			rHead = newNode;
			r = rHead;
		}
		else
		{
			r->link = newNode;
			r = newNode;
		}
	}

	printPoly(&rHead);
}

void polyMult(struct node **p1, struct node **p2)
{
	struct node *a = *p1;
	struct node *b = *p2;
	struct node *rHead;
	struct node *r = NULL;

	while (a != NULL)
	{
		b = *p2;
		while (b != NULL)
		{
			struct node *newNode = (struct node *)malloc(sizeof(struct node));
			newNode->coe = a->coe * b->coe;
			newNode->exp = a->exp + b->exp;
			newNode->link = NULL;
			if (r == NULL) {
				r = newNode;
			} else {
				temp = r;
				while (temp->link != NULL) {
					temp = temp->link;
				}
				temp->link = newNode;
			}
			b=b->link;
		}

		a = a->link;
	}

	rHead = r;
	while(r!=NULL) {
		temp = rHead;
		while(temp!=NULL) {
			if(r->exp == temp->exp && temp != r) {
				r->coe = r->coe + temp->coe;
				//deleting something 
				temp2 = r;
				while(temp2->link != temp){
					temp2=temp2->link;
				}
				temp2->link = temp->link;
				temp2 = temp;
				temp = temp->link;
				free(temp2);
			} else {
				temp = temp->link;	
			}
		}
		r = r->link;
	}

	printPoly(&rHead);
}

int main()
{
	struct node *p1Head = NULL;
	struct node *p2Head = NULL;
	inputPoly(&p1Head);
	inputPoly(&p2Head);
	polyMult(&p1Head, &p2Head);
}