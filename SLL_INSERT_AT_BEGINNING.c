#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

/* Function to insert node at beginning */
struct Node* insertBeginning(struct Node *head, int data)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = head;

    head = newNode;

    return head;
}

/* Function to display list */
void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
}

int main()
{
    struct Node *head = NULL;
    int data;

    printf("Enter data to insert: ");
    scanf("%d", &data);

    head = insertBeginning(head, data);

    printf("Linked List after insertion:\n");
    display(head);

    return 0;
}