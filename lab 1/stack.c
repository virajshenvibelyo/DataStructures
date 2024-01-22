#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5

int top = -1, stack[SIZE];
void push(int value);
void pop();
void display();

int main()
{
    int n, value;
    while (1)
    {
        printf("********************************MENU******************************** \n");
        printf("ENTER 1: to push \n ENTER 2: to delete \n ENTER 3: to display \n ENTER 4: to exit \n");
        printf("Enter the number:");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid number, try again.");
            break;
        }
    }
}

void push(int value)
{
    if (top == SIZE - 1)
    {
        printf("Stack is Full \n overflow");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is Empty \n underflow");
    }
    else
    {
        int value = stack[top];
        top--;
        printf("poped value is %d \n", value);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is Empty \n ");
    }
    for (int i = top; i > -1; i--)
    {
        printf("Elements of stack are %d \n", stack[i]);
    }
}
