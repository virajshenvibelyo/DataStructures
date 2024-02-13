#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void create_ll()
{
    struct node *new_node, *ptr;
    int num;
    printf("Enter -1 to exit.. \n");
    // printf("Enter the num: ");
    // scanf("%d", &num);
    while (num != -1)
    {
        printf("Enter the num: ");
        scanf("%d", &num);
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (head == NULL)
        {
            head = new_node;
            new_node->next = NULL;
            new_node->prev = NULL;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
        }
    }
}

void insert_left()
{
    struct node *newnode, *ptr;
    int val, node;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter a value to insert at left:");
    scanf("%d", &val);
    printf("enter a value before which data need to be inserted: ");
    scanf("%d", &node);
    newnode->data = val;
    if (head == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        ptr = head;
        while(ptr->data != node){
              ptr = ptr->next;
        }
        newnode->next = ptr;
        newnode->prev = ptr->prev;
        ptr->prev->next = newnode;
        ptr->prev = newnode;
    }
}

void display()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("Linked list is empty!");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }
    }
}

void del()
{
    struct node *ptr;
    int val;
    printf("enter the value to be deleted:");
    scanf("%d", &val);
    ptr = head;
    if (head->data == val)
    {
        ptr = ptr->next;
        head = ptr;
        free(ptr);
    }
    else
    {
        while (ptr->data != val)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
    }
}

int main()
{
    int value, choice;
    while (1)
    {
        printf("---------------MENU----------------\n");
        printf("1.create_ll\n 2.insert_left\n 3.delete\n 4.display\n 5.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_ll();
            break;

        case 2:
            insert_left();
            break;

        case 3:
            del();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("wrong input!\n");
            break;
        }
    }
}