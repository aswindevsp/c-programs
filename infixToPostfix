#include <stdio.h>
#include <string.h>

char stack[100];
int oStack[100];

int oTop = -1;
int top = -1;

void push(char ch) {
	top++;
	stack[top] = ch;
}

void oPush(char ch) {
	oTop++;
	oStack[oTop] = ch;
}

char pop() {
	if(top != -1) {
		top--;
		return stack[top+1];	
	} else {
		return 0;
	}
}

char oPop() {
	if(top != -1) {
		oTop--;
		return oStack[oTop+1];	
	} else {
		return 0;
	}
}


int prec(char ch) {
	if(ch == '+' || ch == '-') 
		return 1;
	else if(ch == '*' || ch == '/') 
		return 2;
	else if(ch == '^')
		return 3;
	else 
		return -1;
}

int getInt(char ch) {
	return (ch - '0');
}

int evaluate(char arr[]) {
	int i = -1;
	for(int j=0; j<strlen(arr); j++) {
		i++;
		if(isdigit(arr[j]) == 1) {
			int temp = getInt(arr[i]);
			oPush(temp);	
		} else {
			char op = arr[j];
			int y = oPop();
			int x = oPop();
			switch(op) {
				case '+':
					oPush(x + y);
					break;
				case '-':
					oPush(x - y);
					break;
				case '*':
					oPush(x * y);
					break;	
				case '/':
					oPush(x / y);
					break;	
			}
			
		}
	}
	
	printf("Value = %d\n", oStack[0]);
	
}



void main() {
	char str[100];
	char out[100];
	int k = 0;
	printf("Enter a string: ");
	scanf("%s", str);

	push('(');
	
	for(int i=0; i<strlen(str); i++) {
		if(str[i] == '(') {
			push(str[i]);
		} else if(isdigit(str[i]) == 1) {
			out[k++] = str[i];
			//printf("%c", str[i]);
		} else if(prec(str[i]) >= prec(stack[top])) {
			push(str[i]);		
		} else if(str[i] == ')') {
			while(stack[top] != '(') {
				out[k++] = stack[top];
				//printf("%c", stack[top]);
				pop();		
			}
			pop();
		}else if(prec(str[i]) < prec(stack[top])) {
			//printf("%c", stack[top]);
			out[k++] = stack[top];
			pop();
			push(str[i]);
		}
	}
	out[strlen(str)] = '\0';
	printf("%s \n", out);
	evaluate(out);
}

