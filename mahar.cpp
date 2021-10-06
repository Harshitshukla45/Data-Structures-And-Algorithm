#include<iostream>
using namespace std;
class base
{
  public:
  int x;
void display(void){
  cout<<"give the value of y"<<endl ;
  cin>>y ;
  cout<<"value of y is"<<y<<endl ;
}
 

  private:
  int y;
  
 
  protected:
  int z;
} ;

 class child : public base 
{
	public:
   void show(void){
   cout<<"give the value of z"<<endl ;
  cin>>z ;
  cout<<"value of z is"<<z<<endl ;

}
};
   
int main()
{    
    base obj ;
 cout<<"enter the value of x"<<endl ;
 cin>>obj.x ;

  cout<<"value of x is"<<obj.x<<endl ;

 obj.display() ;
 
child cbj ;

 cbj.show() ;
 
}




