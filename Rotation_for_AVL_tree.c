#include <stdio.h>
#include<malloc.h>

struct node{
    int info;
    int height; 
    struct node *left;
    struct node *right;
};

typedef struct node node;

node* createnode(int value)
{   node *n;
    n = (node *)malloc(sizeof(node));
    n->info=value;
    n->height=1;
    n->left=NULL;
    n->right=NULL;
    
    return n;
    
}

int getheight(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    return root->height;
}

int max(int a,int b)
{
    return (a>b)?a:b;
}
node* rightrotate(node*y)
{
    node *x=y->left ;
    node *t2=x->right;
    
    x->right=y;
    y->left=t2;
    
    x->height=max(getheight(x->left),getheight(x->right))+1;
    y->height=max(getheight(y->left),getheight(y->right))+1;
    
    return x;
}
node* leftrotate(node*x)
{
    node *y=x->right;
    node *t2=y->left;
    
    y->left=x;
    x->right=t2;
    
    x->height=max(getheight(x->left),getheight(x->right))+1;
    y->height=max(getheight(y->left),getheight(y->right))+1;
    
    return y;
}

node* inserting(node*root,int value)
{
    if(root==NULL)
    {
        return createnode(value);
    }
    
    if(value > root->info)
    {
        root->right = inserting(root->right,value) ;
    }
    
    else if(value < root->info)
    {
        root->left = inserting(root->left,value) ;
    }
    
    root->height = max(getheight(root->left),getheight(root->right))+1;
    
    int bf;
    if(root==NULL)
    {
        bf=0;
    }
    else{
        bf= getheight(root->right)-getheight(root->left);
    }
    
    if(bf<-1 && value < root->left->info)
    {
        return rightrotate(root) ;
    }
    
    if(bf>1 && value > root->right->info)
    {
        return leftrotate(root) ;
    }
    
    if(bf<-1 && value >root->left->info)
    {
        root->left=leftrotate(root->left) ;
        return rightrotate(root) ;
    }
    
    if(bf>1 && value < root->right->info)
    {
        root->right=rightrotate(root->right) ;
        return leftrotate(root) ;
    }
    
    return root ;
}

void preorder(node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
  node*root=NULL;
   root=inserting(root,1);
    root=inserting(root,2);
     root=inserting(root,4);
      root=inserting(root,5);
       root=inserting(root,6);
        root=inserting(root,3);
         
         preorder(root);
    return 0;
}
