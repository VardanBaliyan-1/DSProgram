#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to insert node at beginning
struct Node* insertBeginning(struct Node *head, int data) {
    struct Node *newNode;

    // Create new node
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    // If list is not empty
    if (head != NULL) {
        head->prev = newNode;
    }

    // New node becomes the head
    head = newNode;

    return head;
}

// Function to display the list
void display(struct Node *head) {
    struct Node *temp = head;

    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int data;

    printf("Enter data to insert at beginning: ");
    scanf("%d", &data);

    head = insertBeginning(head, data);

    display(head);

    return 0;
}