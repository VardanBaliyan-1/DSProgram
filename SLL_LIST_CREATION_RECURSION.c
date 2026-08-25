#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* create(int n)
{
    struct Node *newNode;
    int data;

    if (n == 0)
        return NULL;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &data);

    newNode->data = data;

    printf("Creating next node...\n");

    newNode->next = create(n - 1);

    return newNode;
}

void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("NULL");
        return;
    }

    printf("%d -> ", head->data);

    display(head->next);
}

int main()
{
    struct Node *head;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = create(n);

    printf("Linked List: ");
    display(head);

    return 0;
}