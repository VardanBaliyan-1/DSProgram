#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

/* Function to delete node from beginning */
struct Node* deleteBeginning(struct Node *head)
{
    struct Node *temp;

    /* Check if list is empty */
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    /* Store the first node */
    temp = head;

    /* Move head to the second node */
    head = head->next;

    /* Free the first node */
    free(temp);

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

    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    struct Node *newNode;
    int n, i, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    /* Create linked list */
    for (i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);

        newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    printf("\nOriginal Linked List:\n");
    display(head);

    /* Delete first node */
    head = deleteBeginning(head);

    printf("\nLinked List after deletion from beginning:\n");
    display(head);

    return 0;
}