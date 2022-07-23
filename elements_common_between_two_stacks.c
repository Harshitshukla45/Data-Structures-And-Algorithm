#include <stdio.h>
#include <malloc.h>
#define max 100
void inserting(int* st,int *top)
{
    if(*top==max-1)
    {
        printf("stack is full\n");
    }
    
    else{
        int l;
        printf("enter the element\n");
        scanf("%d",&l);
        *top = *top+1;
        st[*top]=l;
    }
}
void findintersection(int st1[],int st2[],int top1,int top2)
{   
    int i,j;
    for(i=top1;i>-1;i--)
    {
        for(j=top2;j>-1;j--)
        {
           if(st1[i]==st2[j])
           {
               printf(" %d",st1[i]);
           }
        }
    }
}
void display(int st[],int top)
{
    for(int j = top;j>-1;j--)
    {
        printf("%d ",st[j]);
    }
    printf("\n");
}
int main()
{
   int i,j;
   
   int st1[100],st2[100],top=-1;
   
  inserting(st1,&top);
  inserting(st1,&top);
  inserting(st1,&top);
  inserting(st1,&top);
  inserting(st1,&top);
  inserting(st1,&top);
   
   int top1=top;
   top=-1;
   
  inserting(st2,&top);
  inserting(st2,&top);
  inserting(st2,&top);
  inserting(st2,&top);
  inserting(st2,&top);
  inserting(st2,&top);
  inserting(st2,&top);
   
   int top2=top;
   top=0;
   display(st1,top1);
   display(st2,top2);
   findintersection(st1,st2,top1,top2);
   
   
    return 0;
}
