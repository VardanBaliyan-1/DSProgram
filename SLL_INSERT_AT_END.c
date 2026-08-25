#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

/* Function to insert node at end */
struct Node* insertEnd(struct Node *head, int data)
{
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    /* If list is empty */
    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    /* Move to the last node */
    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    /* Connect new node to last node */
    temp->next = newNode;

    return head;
}

/* Function to display the list */
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

    head = insertEnd(head, data);

    printf("Linked List after insertion:\n");
    display(head);

    return 0;
}