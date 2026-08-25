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

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        return newNode;
    }

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Function to delete node from specific position
struct Node* deleteAtPosition(struct Node *head, int position) {
    struct Node *temp;
    int i;

    // Check if list is empty
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    // Delete first node
    if (position == 1) {
        temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        free(temp);
        return head;
    }

    // Move to the node at given position
    temp = head;

    for (i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    // Invalid position
    if (temp == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    // Connect previous node to next node
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    // Connect next node to previous node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // Delete the node
    free(temp);

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
    int n, data, position, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create the doubly linked list
    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        head = insertEnd(head, data);
    }

    printf("\nBefore deletion:\n");
    display(head);

    // Position to delete
    printf("\nEnter position to delete: ");
    scanf("%d", &position);

    // Delete node
    head = deleteAtPosition(head, position);

    printf("\nAfter deletion:\n");
    display(head);

    return 0;
}