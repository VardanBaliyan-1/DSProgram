#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a doubly linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *newNode, *temp;
    int i;

    for (i = 1; i <= n; i++) {
        // Allocate memory for new node
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);

        newNode->prev = NULL;
        newNode->next = NULL;

        // First node
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        }
        // Remaining nodes
        else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    return head;
}

// Function to display the doubly linked list
void display(struct Node *head) {
    struct Node *temp = head;

    printf("\nDoubly Linked List:\n");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    struct Node *head;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    display(head);

    return 0;
}