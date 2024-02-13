#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1;
struct node *head2;

struct node *insert1(struct node *head1) {
    struct node *new_node, *ptr;
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->data = num;

    if(head1 == NULL) {
        head1 = new_node;
    } else {
        ptr = head1;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    return head1;
}

struct node *insert2(struct node *head2) {
    struct node *new_node, *ptr;
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->data = num;

    if(head2 == NULL) {
        head2 = new_node;
    } else {
        ptr = head2;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    return head2;
}

void display(struct node *head) {
    struct node *ptr;

    ptr = head;
    printf("Element are: \n");
    while(ptr != NULL) {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void concat(struct node *head1, struct node *head2){
    struct node *ptr;

    if(head1 != NULL && head2 != NULL) {
        ptr = head1;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = head2;
    } else {
        printf("either of the Linked List is Empty");
    }
}

void reverse(struct node *head1) {
    struct node *ptr = NULL, *prev = NULL;
    while(head1 != NULL) {
        ptr = head1->next;
        head1->next = prev;
        prev = head1;
        head1 = ptr;
    }
    head1 = prev;
    display(head1);
}


int main() {
    int choice;

    do {
        printf("Enter the Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head1 = insert1(head1);
            break;
        case 2:
            head2 = insert1(head2);
            break;
        case 3:
            display(head1);
            break;
        case 4:
            display(head2);
            break;
        case 5:
            concat(head1, head2);
            break;
        case 6:
            display(head1);
            break;
        case 7:
            reverse(head1);
            break;
        }
    } while(choice != -1);
}