#include <stdio.h>
#include <stdlib.h>
struct Node
{ 
   int data; 
   struct Node *next; };
int main()
{    struct Node   *newNode;    
 newNode = malloc(sizeof(struct Node));  
 newNode->data = 10;   
 newNode->next = NULL;    
 printf("Data = %d", newNode->data);    
 free(newNode); 
 return 0;}



  

