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

void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
   
    node *p=create(4); 
     node *p1=create(1);
      node *p2=create(6);
       node *p3=create(5);
        node *p4=create(2);
        
        p->left=p1;
        p->right=p2;
        p1->left=p3;
        p1->right=p4;
        
        preorder(p);
        
        return 0;
}
