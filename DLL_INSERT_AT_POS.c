#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to insert node at specific position
struct Node* insertAtPosition(struct Node *head, int data, int position) {
    struct Node *newNode, *temp;
    int i;

    // Create new node
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    // Insert at beginning
    if (position == 1) {
        newNode->next = head;

        if (head != NULL) {
            head->prev = newNode;
        }

        head = newNode;
        return head;
    }

    // Traverse to the node before the required position
    temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Invalid position
    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return head;
    }

    // Insert new node
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    return head;
}

// Function to display the doubly linked list
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

    // Create initial list
    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        head = insertAtPosition(head, data, i);
    }

    printf("\nOriginal List:\n");
    display(head);

    // Data and position for new node
    printf("\nEnter data to insert: ");
    scanf("%d", &data);

    printf("Enter position: ");
    scanf("%d", &position);

    // Insert node
    head = insertAtPosition(head, data, position);

    printf("\nAfter Insertion:\n");
    display(head);

    return 0;
}