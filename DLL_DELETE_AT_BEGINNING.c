#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to delete node from beginning
struct Node* deleteBeginning(struct Node *head) {
    struct Node *temp;

    // Check if list is empty
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    // Store the first node
    temp = head;

    // Move head to the next node
    head = head->next;

    // Make previous of new head NULL
    if (head != NULL) {
        head->prev = NULL;
    }

    // Free the deleted node
    free(temp);

    return head;
}

// Function to insert a node at end
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
    int n, data, i;

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

    // Delete first node
    head = deleteBeginning(head);

    printf("\nAfter deleting first node:\n");
    display(head);

    return 0;
}