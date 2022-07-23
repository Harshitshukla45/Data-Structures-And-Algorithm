#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    struct node* right;
    struct node* left;
    int height;
};
typedef struct node node;

node* creating(int value)
{
    node* temp;
    temp=(node*)malloc(sizeof(node)) ;
    temp->info=value;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1;
    return temp;
}

int* arraymaking(int* C,node* root)
{
    int i=0;

    if(root==NULL)
    {
      return NULL;
    }

    stack<node*>st;
    node* temp=root;

    while(temp || !st.empty())
    {
        while(temp)
        {
            st.push(temp);
            temp=temp->left;
        }
       temp=st.top();
       st.pop();
       C[i++]=temp->info ;
       temp=temp->right;
    }
    return C;
}

int getheight(node*root)
{
    if(root==NULL)
    {
        return 0;
    }

    return root->height;
}

int maxe(int a,int b)
{
    return (a>b)?a:b;
}
node* rightrotate(node*y)
{
    node *x=y->left ;
    node *t2=x->right;

    x->right=y;
    y->left=t2;

    x->height=maxe(getheight(x->left),getheight(x->right))+1;
    y->height=maxe(getheight(y->left),getheight(y->right))+1;

    return x;
}
node* leftrotate(node*x)
{
    node *y=x->right;
    node *t2=y->left;

    y->left=x;
    x->right=t2;

    x->height=maxe(getheight(x->left),getheight(x->right))+1;
    y->height=maxe(getheight(y->left),getheight(y->right))+1;

    return y;
}

node* merging(node*root,int value)
{
    if(root==NULL)
    {
        return creating(value);
    }

    if(value > root->info)
    {
        root->right = merging(root->right,value) ;
    }

    else if(value < root->info)
    {
        root->left = merging(root->left,value) ;
    }

    root->height = maxe(getheight(root->left),getheight(root->right))+1;

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

void inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}
int main()
{
    int i,j;
    node *root1 = creating(100);
    root1->left = creating(50);
    root1->right = creating(300);
    root1->left->left = creating(20);
    root1->left->right = creating(70);

    node *root2 = creating(80);
    root2->left = creating(40);
    root2->right = creating(120);

    int *arr;
    int *brr;
    int A[5];
    int B[3];
    arr = arraymaking(A,root1);
    brr = arraymaking(B,root2);

    int crr[8];
    for(i=0;i<5;i++)
    {
        crr[i]=arr[i];
    }

    for(i=5,j=0;i<8 && j<3;i++,j++)
    {
        crr[i]=brr[j];
    }
    printf("\n");
    node* head=NULL;
    for(i=0;i<8;i++)
    {
       head = merging(head,crr[i]);
    }

    inorder(head);

    return 0;
}
