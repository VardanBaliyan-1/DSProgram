#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;

};
int main(){
    struct node *head = NULL, *newnode, *temp;
    struct node *prev = NULL, *nextnode;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    
    //Creating the linked list
    for(i=1;i<=n;i++){
        newnode=(struct node *)malloc(sizeof(struct node));

        printf("Enter data for node %d: ",i);
        scanf("%d",&newnode->data);

        newnode->next=NULL;
        if(head == NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    temp=head;
    while(temp!=NULL){
        nextnode = temp->next;
        temp->next = prev;
        prev= temp;
        temp=nextnode;
    }
    head=prev;

    //Display revered list
    printf("\nReversed SLL: ");
    temp=head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    return 0;
}