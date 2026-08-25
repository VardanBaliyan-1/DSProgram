#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

/* Function to insert at specified position */
struct Node* insertPosition(struct Node *head, int data, int pos)
{
    struct Node *newNode, *temp;
    int i;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;

    /* Insert at beginning */
    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    temp = head;

    /* Move to node before required position */
    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

/* Function to display */
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
    struct Node *newNode, *temp;
    int n, i, data, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    /* Create list */
    for (i = 1; i <= n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter data to insert: ");
    scanf("%d", &data);

    printf("Enter position: ");
    scanf("%d", &pos);

    head = insertPosition(head, data, pos);

    printf("Linked List after insertion:\n");
    display(head);

    return 0;
}