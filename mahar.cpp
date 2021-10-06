#include<iostream>
using namespace std;
 class base
 {
  public:
    char name[100];
    int j ;
 };

int main()
{    base obj[100] ;
   int i,p,q,r,s, n;
   printf("enter the number of the people for their bill\n");
   scanf("%d",&n);

   for(i=0;i<n;i++)
   {
      cout<<"enter the name of the user:\n"<<endl ;
      cin>>obj[i].name ;

      cout<<"enter the amount of unit he/she used:\n"<<endl ;
      cin>>obj[i].j ;
   }

   cout<<"displaying information.......\n"<<endl;

   for(i=0;i<n;i++)
   {
     p = obj[i].j  ;

     if(p<=100)
     {
        r=p*60 ;
     }

    else if(p>=100 && p<=300)
    {
        r=p*80 ;
    }

    else{
        r=p*90 ;
    }

    cout<<"bill for "<<obj[i].name<<endl ;
    cout<<"Rupees:"<<r+50<<endl ;
   }

    return 0;
}

