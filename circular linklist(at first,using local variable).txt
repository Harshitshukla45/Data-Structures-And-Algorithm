#include <stdio.h>
#include <stdlib.h>

struct node{
int info;
struct node *next;
};
typedef struct node node;

node* insert_at_first(int value,node*head)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->info=value ;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        head->next=head;
    }
    else
    {
        temp->next=head->next;
        head->next=temp;

    }
    return head;

}
int delete_from_first(node*head)
{
    node *temp=head->next;
    head->next=temp->next;
    temp->next=NULL;
    int b=temp->info;
    free(temp);
    return b;
}
void display(node*head)
{
    node*temp=head->next ;
    int a=temp->info,count=0;
    while(count!=2)
    { if(temp->info==a)
    {
       count++;
       if(count==2)
       {
           break;
       }
    }
      printf("%d\n",temp->info);
      temp=temp->next;
    }

}
int main()
{
    printf("Harshit Shukla\n");
    node *head=NULL;
    int choice;
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
            head=insert_at_first(value,head);
            break;
        }
        case 2:
        {
            printf("deleted value is %d\n",delete_from_first(head));
            break;

        }
        case 3:
        {
            display(head);
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
