#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

/* Function to delete node at specific position */
struct Node* deleteAtPosition(struct Node *head, int position)
{
    struct Node *temp, *prev;
    int i;

    /* Check if list is empty */
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    /* Delete first node */
    if (position == 1)
    {
        temp = head;
        head = head->next;
        free(temp);

        return head;
    }

    /* Move to the node at given position */
    temp = head;

    for (i = 1; i < position; i++)
    {
        prev = temp;
        temp = temp->next;

        /* Position does not exist */
        if (temp == NULL)
        {
            printf("Invalid position\n");
            return head;
        }
    }

    /* Delete the node */
    prev->next = temp->next;

    free(temp);

    return head;
}

/* Function to display the linked list */
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
    struct Node *newNode, *temp;
    int n, i, data, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    /* Create linked list */
    for (i = 1; i <= n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    printf("\nOriginal Linked List:\n");
    display(head);

    printf("\nEnter position to delete: ");
    scanf("%d", &position);

    head = deleteAtPosition(head, position);

    printf("\nLinked List after deletion:\n");
    display(head);

    return 0;
}