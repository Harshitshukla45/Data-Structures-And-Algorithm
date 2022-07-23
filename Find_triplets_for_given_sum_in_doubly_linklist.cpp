#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 typedef struct node{
    int data;
    struct node* prev,*next;
}node;

void inserting(node** head,node** tead,int value)
{   
    node* temp=(node*)malloc(sizeof(node));
    temp->data=value;
    temp->next=NULL;
    
    if(*head==NULL)
    {
        *head=temp;
        *tead=temp;
    }
    else
    {
      (*tead)->next=temp;
      temp->prev=*tead;
      *tead=temp;
    }
}

void findingpairs(node* head,int k)
{
    unordered_map<int,int>mp;
    node *temp=head;
    while(temp)
    {
        mp[temp->data]=2;
        temp=temp->next;
    }
    temp=head;
    node* kemp;
    kemp=temp->next;
    while(temp)
    {
       int val=k-temp->data;
       kemp=temp->next;
       while(kemp!=NULL)
       {
           if(mp[val - kemp->data]==2 && val-kemp->data != kemp->data && val-kemp->data != temp->data )
           {
               cout<<"("<<temp->data<<","<<kemp->data<<","<<val-kemp->data<<")"<<endl;
           }
           kemp=kemp->next;
       }
       temp=temp->next;
      
    }
}
int main()
{
    node* head=NULL;
    node* tead=NULL;
    
    inserting(&head,&tead,1);
     inserting(&head,&tead,2);
      inserting(&head,&tead,4);
       inserting(&head,&tead,5);
        inserting(&head,&tead,6);
         inserting(&head,&tead,8);
           inserting(&head,&tead,9);
          
            node*temp=head;
            /*while(temp)
            {
                cout<<temp->data<<"\n";
                temp=temp->next;
            }*/
            
         findingpairs(head,17)  ; 
    

    return 0;
}
