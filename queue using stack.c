#include <stdio.h>
int stack[20],top,cop,choice,i ;
void enqueue()
{
     if(top==4)
            {
                printf("stack is full\n");
            }
            else if(top ==-1)
            {
                printf("enter the number\n");
                scanf("%d",&i);
                stack[cop]=i;
                top++;
            }
            else
            {
                printf("enter the number\n");
                scanf("%d",&i);
                top++;
                stack[top]=i;
            } 
}
void dequeue()
{
     if(top==-1)
            {
                printf("stack is empty\n");
            }
            else
            printf("dequeud element is %d",stack[cop]);
            
            cop++;
}
void display()
{
            if(top==-1)
            {
                printf("stack is empty\n");
            } 
            else
            while(cop!=top+1)
            {
                printf("%d\n",stack[cop]);
                cop++;
            }
}

int main()
{
   
    
    top=-1 ;
    cop=0 ;
    
    do{
     printf("enter your choice \n 1-enqueue \n 2-dequeue \n 3- display \n 4-quit") ;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {  
               enqueue();
                break;
            }
            
        case 2: 
        {
           
           dequeue(); 
            break;
        }
       case 3:
       {
          
            display();
            break;
       }
       
       case 4: 
       {
           break;
       }
    }
    }while(choice!=4);
    
    return 0;
}   
   
    

 