#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indexI=0, top=-1, pos=0, length;
char symbol, temp, postfix[30], infix[30], stack[30];

void infixToPostfix();
int pred(char symbol);
void push(char symbol);
char pop();

int main() {
    printf("Enter the infix expression: ");
    scanf("%s", &infix);
    infixToPostfix();
    printf("Infix expression is %s\n", infix);
    printf("postfix expression is %s\n", postfix);
}

void push(char symbol) {
    top++;
    stack[top] = symbol;
}

char pop() {
    char symbol = stack[top];
    top--;
    return symbol;
}

int pred(char symbol) {
    int p;
    switch (symbol) {
        case '^':
            p = 3;
            break;
        case '*':
        case '/':
            p = 2;
            break;
        case '+':
        case '-':
            p = 1;
            break;
        case '(':
            p = 0;
            break;
        case '#':
            p = -1;
            break;
    }
    return p;
}

void infixToPostfix() {
    length = strlen(infix);
    push('#');
    while (indexI < length) {
        symbol = infix[indexI];

        switch (symbol) {
            case '(':
                push(symbol);
                break;
            case ')':
                temp = pop();
                while (temp != '(') {
                    postfix[pos] = temp;
                    pos++;
                    temp=pop();
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (pred(stack[top]) >= pred(symbol)) {
                    temp = pop();
                    postfix[pos] = temp;
                    pos ++;
                }
                push(symbol);     
                break;
            default: 
                postfix[pos] = symbol;
                pos++;           
        }
       indexI++;
    }
    while (top > 0) {
        temp = pop();
        postfix[pos] = temp;
        pos ++;
    }
}