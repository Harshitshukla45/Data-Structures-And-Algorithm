#include <stdio.h>
#include <stdlib.h>

struct node{
int info;
struct node*next;
};
 typedef struct node node;

 void inserting(node ** head,node **tead,int value)
 {
     node*temp;
     temp=(node*)malloc(sizeof(node));
     temp->info=value;
     temp->next=NULL;

     if(*head==NULL)
     {
         *head=temp;
         *tead=temp;
     }

     else{
        (*tead)->next=temp;
         *tead=temp;
     }
 }

void  printrecursively(node **head)
{
    node*temp = *head ;

    if(temp != NULL)
    {
        printrecursively(&(temp->next));
        printf(" %d",temp->info);
    }
}
int main()
{
    node *head=NULL;
    node *tead=NULL;
    int value;

    printf("enter the value\n");
    scanf("%d",&value);
    inserting(&head,&tead,value);

    printf("enter the value\n");
    scanf("%d",&value);
    inserting(&head,&tead,value);

    printf("enter the value\n");
    scanf("%d",&value);
    inserting(&head,&tead,value);

    printf("enter the value\n");
    scanf("%d",&value);
    inserting(&head,&tead,value);

    printf("enter the value\n");
    scanf("%d",&value);
    inserting(&head,&tead,value);

    printf("enter the value\n");
    scanf("%d",&value);
    inserting(&head,&tead,value);

    printrecursively(&head);

    return 0;
}
