#include <stdio.h>
#include <stdlib.h>
int choice;
struct node{
    int info;
    struct node*next;
    struct node*prev;
};
typedef struct node node;
node *head=NULL;
node *last=NULL;

void insert_at_last(int value)
{
    node *new;
    new=(node*)malloc(sizeof(node));
    
    if(head==NULL)
    {
        new->info=value;
        new->next=NULL;
        new->prev=NULL;
        head=new;
        last=head;
    }
    else
    {
        new->info=value;
        new->next=NULL;
        new->prev=last;
        last->next=new;
        last=new ;
    }
}

int delete_from_last()
{
    node *new=last;
    last=last->prev;
    last->next=NULL;
    int a=new->info;
    
    return a;
}

void display()
{
    node *new=head;
    while(new!=NULL)
    {
        printf("%d\n",new->info) ;
        new=new->next;
    }
}

int main()
{
    printf("Harshit Shukla\n");
    
   
    
    while(choice!=4)
    {
       printf("select from the given choice.....\n 1.insert \n 2.delete \n 3.display \n 4.quit \n");
       scanf("%d",&choice);
       
       switch(choice)
       {
        case 1:
        {   int value;
            printf("enter the value\n");
            scanf("%d",&value);
            insert_at_last(value);
            break;
        }
        case 2:
        {
            printf("deleted value is %d\n",delete_from_last());
            break;
        
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            break;
        }
       }
      
    }
     return 0;
}
