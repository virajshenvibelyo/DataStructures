#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue() {
    struct node  *new_node, *ptr;
    int val;

    printf("Enter the value: ");
    scanf("%d", &val);

    new_node= (struct node *)malloc(sizeof(struct node));
    new_node->data=val;

    if(new_node == NULL) {
        printf("Overflow...\n");
    } else  {
        if(front == NULL ){
            front = new_node;
            rear = new_node;
            front->next = NULL;
            rear->next = NULL;
        } else {
            rear->next = new_node;
            rear = new_node;
            rear->next = NULL;
        }
    } 
}

void dequeue() {
    struct node *ptr;

    if(front == NULL) {
        rear = NULL;
        printf("underFlow... \n");
    } else {
        ptr = front;
        front = ptr->next;
        printf("dequeued element : %d \n", ptr->data);
        free(ptr);
    }
}

void display() {
    struct node *ptr;

    if(front == NULL && rear == NULL) {
        printf("Queue is empty \n");
    } else {
        ptr = front;
        printf("Elements of Queue: \n");
        while(ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main() {
    int choice;

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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