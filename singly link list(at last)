#include<iostream>
using namespace std;
struct node{
 int info;
 struct node *next ;
 };
 int count=0;
 typedef struct node node;
 node *head =NULL;
 node *tead =NULL;
 void insertatlast(int value)
 { node *temp;
   temp=(node*)malloc(sizeof(node));
   temp->info=value;
   temp->next =NULL;
   
   if(head==NULL)
   {  head =temp;
   }
   if( count==0)
   {  tead =temp;
     count++;
     }
     
     else
     {
       head->next=temp;
       head =temp;
       }
       }
       
 void display()
 { node *temp=tead;
   while(temp!=NULL)
   {  if(temp->next!=NULL)
      { cout<<" "<<temp->info<<endl ;
      }
     temp=temp->next;
   }
   
 }
  int removelast()
{
   node *temp=tead;
   for(temp=tead;temp!=NULL;temp = temp->next)
   {  
       if(temp==head)
       {  int a=head->info ;
           temp =NULL ;
           return a;
           free(temp);
       }
   }
}
 
 int main()
 {  int value;
    cin>>value;
    
    insertatlast(value);
   
    cin>>value;
    
    insertatlast(value);
   
   
    cin>>value;
    
    insertatlast(value);
   
   
    cin>>value;
    
    insertatlast(value);
   
   
    cin>>value;
    
    insertatlast(value);
    
    cout<<"popped element is "<<removelast()<<endl;
   
    display();
   
    return 0;
   }
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
