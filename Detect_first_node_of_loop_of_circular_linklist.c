#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* next;
};
typedef struct node node;

node* insert(int value,node*head)
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

void getjoined(node*head,int key)
{   
    node*temp=head;
    while(temp!=NULL)
    {
      if(temp->info==key)
      {
          head->next=temp;
          break;
      }
      temp=temp->next;
    }
}

void detectloop(node*head)
{ 
  int flag=0,i=1,n=7;
  node *ptr[100];
  node*temp=head;
  while(i<=n)
  {
     temp=temp->next;
     for(int j=1;j<=i;j++)
     {
         if(temp==ptr[j])
         {
            printf("%d",temp->info);
            flag=1;
            break;
         }
     }
     if(flag==0)
     {
        ptr[i]=temp;  
     }
     else
     break;
     
     i++;
  }
}

int main()
{
    node*head=NULL;
    
    int value,key;
    
    scanf("%d",&value);
    head=insert(value,head);
    
     scanf("%d",&value);
    head=insert(value,head);
    
     scanf("%d",&value);
    head=insert(value,head);
    
     scanf("%d",&value);
    head=insert(value,head);
    
     scanf("%d",&value);
    head=insert(value,head);
    
     scanf("%d",&value);
    head=insert(value,head);
    
     scanf("%d",&value);
    head=insert(value,head);
    
    
    scanf("%d",&key);
    
    getjoined(head,key);
    
    detectloop(head);
    
    return 0;
    
    
}
