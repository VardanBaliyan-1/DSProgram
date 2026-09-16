#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;

};
int main(){
    struct node *head = NULL, *temp, *newnode;
    int n, i ,count =0;
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
        count++;
        temp=temp->next;
    }
    printf("Number of nodes = %d",count);
    return 0;
}
