#include<iostream>
using namespace std;
struct node{
int info;
struct node *next;
};
typedef struct node node;

node* inserting(node*head,int value)
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    temp->info=value;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
    return head;
}
node* del(node*head,int key)
{
  if(head->info==key)
  {
      node*temp=head;
      head=head->next;
      temp->next=NULL;
      free(temp);
      return head;

  }
  else{
    node*temp=head;
    node*cemp=head->next;
    while(cemp!=NULL)
    {
        if(cemp->info==key)
        {
            if(cemp->next==NULL)
            {
                temp->next=NULL;
                break;
            }
            else{
            temp->next=cemp->next;
            cemp->next=NULL;
            break;
            }
        }
        cemp=cemp->next;
        temp=temp->next;
    }
    free(cemp);
    return head;
  }
  
}

void display(node*head)
{
    node*temp=head;
    while(temp!=NULL)
    {
      cout<<temp->info<<endl ;
      temp=temp->next ;
    }
}
int main()
{
   
   int value=0,key=0,choice=0;
   node *head=NULL;

   while(choice<4)
   {
        cout<<"select from the given choice\n 1.insert \n 2.delete \n 3.display \n" ;
        cin>>choice ;
        switch(choice)
        {
           case 1:
           {
              cout<<"enter the value\n" ;
              cin>>value;
              head=inserting(head,value);
              break;
           }
            case 2:
            {
              cout<<"enter the key\n" ;
              cin>>key;
              head=del(head,key);
              break;
            }
            case 3:
                {
                    display(head);
                    break;
                }

        }
   }

   return 0;
}
