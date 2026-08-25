#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    struct Node *head, *second, *third, *temp;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
        head->data = 10;
    second->data = 20;
    third->data = 30; 
    head->next = second;
    second->next = third;
    third->next = NULL;
    temp = head;
    while (temp != NULL)
     {
        printf("%d ", temp->data);
        temp = temp->next;
     }
      //free(head);
	//free(second);
	//free(third);
     	return 0;
}

    
