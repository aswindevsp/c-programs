#include <stdio.h>
#include <string.h>


int prec(char ch) {
    if(ch == '+' || ch == '-') {
        return 1;
    } else if(ch == '*' || ch == '/') {
        return 2;
    } else if(ch == '^') {
        return 3;
    } else {
        return 0;
    }
}

int isDigit(char num) {
    if(num >= '0' && num <= '9' ) {
        return 1;
    } 
    return 0;
}   

int isOperant(char op) {
    if(op == '-' || op == '+' || op == '*' || op == '/' || op == '^') 
        return 1;
    else 
        return 0;
}


int toInt(char n) {
    return(n-'0');
}
void eval(char exp[]) {
    int stack[100];
    int top = -1;

    int op = 0;

    for(int i=0; i < strlen(exp); i++) {
        if(isDigit(exp[i])) {
            stack[++top] = toInt(exp[i]);
        } else {
            char operation = exp[i];
            int y = stack[top];
            int x = stack[--top];

            switch (operation) {
                case '+':
                    stack[top] = x + y;     
                    break;
                case '-':
                    stack[top] = x - y;     
                    break;
                case '*':
                    stack[top] = x * y;     
                    break;
                case '/':
                    stack[top] = x / y;     
                    break; 
            }
        }
    }

    printf("And the answer is: %d", stack[0]);
}

void infix(char exp[]) {
    char stack[100];
    int top = -1;


    char op[100];
    int opIndex = -1;
    
    for(int i=0; i<=strlen(exp); i++) {
        if(isDigit(exp[i]) == 1) {
            op[++opIndex] = exp[i];
        } else if(exp[i] == '(') {
            stack[++top] = exp[i];
        } else if(exp[i] == ')') {
            while(stack[top] != '(') {  
                if(isOperant(stack[top])) {
                    op[++opIndex] = stack[top];
                    top--; 
                } else {
                    top--;
                }
            }
            top--;
        } else if(isOperant(exp[i])) {
            if(prec(exp[i]) > prec(stack[top])) {
                stack[++top] = exp[i];
            } else {
                op[++opIndex] = stack[top];
                stack[top] = exp[i];
            }
        }
    }

    op[++opIndex] = '\0';

    printf("%s", op);
    eval(op);
}
int main() {
    char exp[100];
    scanf("%s", exp);

    infix(exp);
    // eval("7332+*+");
}
