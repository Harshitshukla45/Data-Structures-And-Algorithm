#include <iostream>
using namespace std;
struct node{
 int info;
 struct node *next ;
 };
 int count=0;
 typedef struct node node;

 node* insertatlast(node**head,node*tead,int value)
 { 
  
   node *temp;
   temp=(node*)malloc(sizeof(node));
   temp->info=value;
   temp->next =NULL;
   
   if(*head==NULL)
   {  *head =temp;
   }
   
   if(count==0)
   { 
     tead=temp;
     count++;
   }
   
     else
     {
       tead->next=temp;
       tead=temp;
     }
       return tead;
 }
       
 void display(node**head)
 { 
   node *temp=*head;
   while(temp!=NULL)
   {  
       cout<<" "<<temp->info<<endl ;
   
     temp=temp->next;
   }
   
 }
  int removelast(node**head,node*tead)
{
   node *temp=*head;
   node*cemp=temp->next;
  
     while(cemp!=NULL) 
      {
           if(cemp==tead)
       {  int a=tead->info ;
          tead=temp;
          tead->next=NULL;
           return a;
           free(temp);
           free(cemp);
       }
       temp=temp->next;
       cemp=cemp->next;
   
       
   }
}
 
 int main()
 { 
      node *head =NULL;
      node *tead =NULL; 
      int value;
      cin>>value;
    
     tead=insertatlast(&head,tead,value);
     cin>>value;
    
     tead=insertatlast(&head,tead,value);
     
   
     cin>>value;
    
     tead=insertatlast(&head,tead,value);
   
   
     cin>>value;
    
     tead=insertatlast(&head,tead,value);
   
   
     cin>>value;
    
     tead=insertatlast(&head,tead,value);
    
     cout<<"popped element is "<<removelast(&head,tead)<<endl;
   
     display(&head);
   
     return 0;
   }
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
