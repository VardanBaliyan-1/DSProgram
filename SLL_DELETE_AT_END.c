#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

/* Function to delete node from end */
struct Node* deleteEnd(struct Node *head)
{
    struct Node *temp, *prev;

    /* If list is empty */
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    /* If only one node exists */
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    /* Traverse to the last node */
    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    /* Delete last node */
    prev->next = NULL;
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
    struct Node *newNode, *temp;
    int n, i, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    /* Create the linked list */
    for (i = 0; i < n; i++)
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

    /* Delete last node */
    head = deleteEnd(head);

    printf("\nLinked List after deleting from end:\n");
    display(head);

    return 0;
}