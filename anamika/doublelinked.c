
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

void insertBeginning(int value) {
    struct node *newnode = malloc(sizeof(struct node));

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
}


void insertEnd(int value) {
    struct node *newnode = malloc(sizeof(struct node));
    struct node *temp = head;

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}


void displayForward() {
    struct node *temp = head;

    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void deleteNode(int value) {
    struct node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node deleted\n");
}


void displayReverse() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Reverse: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\n1. Insert Beginning");
        printf("\n2. Insert End");
        printf("\n3. Display Forward");
        printf("\n4. Delete Node");
        printf("\n5. Display Reverse");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                displayForward();
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 5:
                displayReverse();
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
