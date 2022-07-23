#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int info;
    struct node* next;
    struct node* prev;
};
typedef struct node node;

void creating(node** root,node** boot,int value)
{
    node* temp = *root;
    temp=(node*)malloc(sizeof(node));
    temp->info=value;
    temp->next=NULL;
    temp->prev=NULL;

    if(*root==NULL)
    {
        *root=temp;
    }
    else{
        temp->prev=*boot;
        (*boot)->next=temp;
        *boot=temp;
    }
}

void gettingpairs(node* root,int key)
{
    int i=0;
    vector<int>forw;
    vector<int>backw;
    node* temp=root;
    while(temp!=NULL)
    {
        forw.push_back(temp->info);
        if(temp->next==NULL)
        {
            break;
        }
        temp=temp->next;
    }
    while(temp!=root)
    {
        backw.push_back(temp->info);
        temp=temp->prev;
        if(temp==root)
        {
         backw.push_back(temp->info);
        }
    }

     int j=0;
    while(i<forw.capacity() || j<backw.capacity())
    {

        if((forw[i]+backw[j])==key)
        {
            cout<<"("<<forw[i]<<","<<backw[j]<<")"<<endl;
            i++;
            j++;

        }
        if((forw[i]+backw[j])>key)
        {
            j++;

        }
        if((forw[i]+backw[j])<key)
        {
            i++;
        }
        if(forw[i]==backw[i] || backw[i+1]==forw[i])
        {
            break;
        }
    }
    

int main()
{
    node* root=NULL;
    node* boot=NULL;
    int value,key;
    cout<<"enter the value\n";
    cin>>value;
    creating(&root,&boot,value);
    boot=root;
    cin>>value;
    creating(&root,&boot,value);
    cin>>value;
    creating(&root,&boot,value);
    cin>>value;
    creating(&root,&boot,value);
    cin>>value;
    creating(&root,&boot,value);
    cin>>value;
    creating(&root,&boot,value);
    cin>>value;
    creating(&root,&boot,value);

    cout<<"enter the key"<<endl;
    cin>>key;
    gettingpairs(root,key);

    return 0;
}
