#include <stdio.h>
int ar[100],top=-1,size = 100;
void push(char ch);
char pop();
void print();
int isp(char ch) {
	if(ch == '+' || ch == '-') 
		return 2;
	else if(ch == '*' || ch == '/') 
		return 4;
	else if(ch == '^') 
		return 5;
	else if(ch == '(') 
		return 0;
	else 
		return 8;
		
}

int icp(char ch) {
	if(ch == '+' || ch == '-') 
		return 1;
	else if(ch == '*' || ch == '/') 
		return 3;
	else if(ch == '^') 
		return 6;
	else if(ch == '(') 
		return 9;
	else if(ch == ')')
		return 0;
	else 
		return 7;
}


int main() {

	char exp[100];
	printf("Enter a string:  ");
	scanf("%s", exp);
	
	push('(');
	
	int i=1;
	while(top>=0) {
		char item = exp[i];
		i++;
		
		char x = pop();
		
		if(isp(item) == 8) {
			push(x);
			printf("%c", item);
		}
		else if(item == ')') {
			while(x != '(') {
				printf("%c", x);
				x = pop();
			}
		}
		else if(isp(x) >= icp(item)) {
			while(isp(x) >= icp(item)) {
				printf("%c", x);
				x = pop();
			}
		} 
		else if(isp(x) < icp(item)) {
			push(x);
			push(item);
		}
		else {
			printf("Invalid Expression");
		}
	}
		
	
}
void push(char ch)
{
	if(top>=size-1)
		printf("Stack Full\n");
	else
	{
		top++;
		ar[top] = ch;
	}
}
char pop()
{
	if(top<=-1)
		return -1;
	else
	{
		return (ar[top]);
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
		