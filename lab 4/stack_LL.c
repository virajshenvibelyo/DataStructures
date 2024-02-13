#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

void push(int num) {
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;

    if(head == NULL){
        head = new_node;
        new_node->next = NULL;
    } else {
        new_node->next = head;
        head = new_node;
    }
}

void pop() {
    struct node *ptr;

    if(head == NULL) {
        printf("Underflow, Stack is empty... \n");
    } else {
        ptr = head;
        head = ptr->next;
        printf("Poped element: %d \n", ptr->data);
        free(ptr);
    }
}

void display() {
    struct node *ptr;

    if(head == NULL) {
        printf("Stack is empty... \n");
    } else {
        ptr = head;
        while(ptr != NULL) {
            printf(" %d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main() {
    int choice,num;

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number: ");
            scanf("%d", &num);
            push(num);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4: 
            exit(0);
        default:
            printf("invalid input try again... \n");
            break;
        }
    }
}