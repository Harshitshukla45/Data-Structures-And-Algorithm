#include <stdio.h>
#include<malloc.h>
struct node{
    int info;
    struct node* left,*right;
};
typedef struct node node;

node* create(int data)
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    temp->info=data;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->info);
        inorder(root->right);
    }
}

int isbst(node *root)
{
    static node *prev=NULL;
    if(root!=NULL)
    {
      if(!isbst(root->left))
      {
        return 0;
      }
      if(prev!=NULL && root->info <= prev->info)
      {
          return 0;
      }
      prev=root;
      return isbst(root->right);
    }
    else{
        return 1;
    }
}
 node*search(node*root,int key)
 {

     if(root==NULL)
     {
         return NULL;
     }
     if(root->info==key)
     {
         return root;
     }

     else if(root->info > key)
     {
         return search(root->left,key);
     }
     else
     {
         return search(root->right,key);
     }
 }
 
  void inserting(node*root,int key)
 {
     
     node*temp=NULL;
     while(root!=NULL)
    { 
      temp=root;
     if(root->info==key)
     {   
         printf("cannot be inserted\n");
         return;
     }

     else if(root->info > key)
     {
         root=root->left;
     }
     else
     {
         root=root->right;;
     }
    }
    
    node* new=create(key);

    if(key>temp->info)
    {
        temp->right=new;
    }
    else{
        temp->left=new;
    }
    
 }
 
node* inorderpredecessor(node*root)
 {
     root=root->left;
     while(root->right!=NULL)
     {
         root=root->right;
     }
     return root;
 }
 
 node * deleting(node *root,int value)
 {   
     node*ipre;
     if(root == NULL)
     {
         return NULL;
     }
     if(root->left == NULL && root->right == NULL)
     {
         root=NULL;
         return root;
     }
     
     else if(root->info > value)
     {
         root->left = deleting(root->left,value);
     }
     
     else if(root->info < value)
     {
        root->right=deleting(root->right,value);
     }
     
     else{
         ipre=inorderpredecessor(root);
         root->info=ipre->info;
         root->left=deleting(root->left,ipre->info);
         
     }
     return root;
 }
 

int main()
{

        node *p=create(5);
        node *p1=create(3);
        node *p2=create(6);
        node *p3=create(2);
        node *p4=create(4);

        p->left=p1;
        p->right=p2;
        p1->left=p3;
        p1->right=p4;

        int key;
        printf("enter the data you want to search\n");
        scanf("%d",&key);

        node*x=search(p,key);
        
        printf("found : %d\n",x->info);
        inorder(p);

        if(isbst(p))
        {
            printf("\nthis is bst\n");
        }
        else
            printf("\nnot bst\n");
            
            inserting(p,1);
             inorder(p);
             
             p=deleting(p,2);
              printf("\n");
              inorder(p);
             

        return 0;
}
