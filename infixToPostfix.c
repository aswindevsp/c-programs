#include <stdio.h>
#include <string.h>

char stack[100], top = -1;

int prec(char c) {
	if(c == '^')
		return 3;
	else if(c == '*' || c == '/')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else 
		return -1;
}

void push(char ch) {
	top++;
	stack[top] = ch;
}
char pop() {
	if(stack[top] != -1) {
		return stack[top];
		top--;
	}
}
int main() {
	char arr[100];
	printf("Enter an expression: ");
	scanf("%s", arr);

	for(int i=0; i<strlen(arr); i++) {
		if((arr[i] >= 'a' && arr[i]<='z') || (arr[i] >= 'A' && s[i] <= 'Z')) {
			printf("%c", arr[i]);
		} else if(s[i] == '(') {
			push(arr[i]);
		} else if(s[i]== ')') {
			while(stack[top] != '(') {
				printf("%d",stack[top] );
				pop();
			}

		} else {
			while(prec(sta))
		}
	}
}