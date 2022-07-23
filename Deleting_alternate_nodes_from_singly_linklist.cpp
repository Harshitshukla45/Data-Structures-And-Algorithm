#include <iostream>
struct node{
         int info;
         struct node *next ;

};

   typedef struct node node;

   node *inserting(node *head,node *tead,int value)
   {
       node *temp;
       temp=(node*)malloc(sizeof(node));

       temp->info=value;
       temp->next=NULL;

       if(head==NULL)
       {
           head=temp;
           return head;
       }
       else
       {
           tead->next=temp;
           tead=temp;

           return tead;
       }
   };

/* node* */void deleting(node *head)
 {
     node *temp=head;
     node *cemp=head->next;
     while(cemp!=NULL)
     {
         node*kemp=cemp;
         cemp=cemp->next;
         if(cemp==NULL)
         {
             temp->next=NULL;
             free(kemp);
             break;
         }
         temp->next=cemp;
         kemp->next=NULL;
         free(kemp);


         temp=temp->next;
         cemp=cemp->next;
     }

     //return head;
 }

 void display(node *head)
 {
     node *temp=head;
     while(temp!=NULL)
     {
         printf("%d\n",temp->info);
         temp=temp->next;
     }
 }

 int main()
 {

     node *head=NULL;
     node *tead=NULL;

     int value;

     printf("enter the value you want to enter\n");
     scanf("%d",&value);
     head=inserting(head,tead,value);
     tead=head;

     printf("enter the value you want to enter\n");
     scanf("%d",&value);
     tead=inserting(head,tead,value);


     printf("enter the value you want to enter\n");
     scanf("%d",&value);
     tead=inserting(head,tead,value);

     printf("enter the value you want to enter\n");
     scanf("%d",&value);
     tead=inserting(head,tead,value);

     printf("enter the value you want to enter\n");
     scanf("%d",&value);
     tead=inserting(head,tead,value);

    /* printf("enter the value you want to enter\n");
     scanf("%d",&value);
     tead=inserting(head,tead,value);*/

    /* head=*/deleting(head);

     display(head);

     return 0;


 }
