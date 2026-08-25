#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to insert node at end
struct Node* insertEnd(struct Node *head, int data) {
    struct Node *newNode, *temp;

    // Create a new node
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return head;
    }

    // Traverse to the last node
    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Connect new node at the end
    temp->next = newNode;
    newNode->prev = temp;

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

    printf("Enter data to insert at end: ");
    scanf("%d", &data);

    head = insertEnd(head, data);

    display(head);

    return 0;
}