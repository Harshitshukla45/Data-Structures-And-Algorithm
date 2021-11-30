#include <iostream>
using namespace std;
class Base{
    protected:
    int rate;
    public:
    void getrate(int x)
    {
       rate=x;
    }
    void putrate()
    {
        cout<<"rate is "<<rate<<endl;
    }
};
class der1 : public Base
{
    protected:
    int amount;
    public:
    void getamt(int y)
    {
        amount=y;
    }
    void putamt()
    {   
        putrate();
        cout<<"total number of product  is "<<amount<<endl;
        cout<<"So total cost is "<<amount*rate<<endl;
    }
    
};
class der2 : public Base
{
    protected:
    int amount;
    public:
    void getamt(int z)
    {
        amount=z;
    }
    void putamt()
    {   
        putrate();
        cout<<"total number of product  is "<<amount<<endl;
        cout<<"So total cost is "<<amount*rate<<endl;
    } 
};
    
int main()
{ 
  der1 ob1;
  ob1.getrate(2);
  ob1.getamt(50);
  ob1.putamt();
  
  der2 ob2;
  ob2.getrate(3);
  ob2.getamt(30);
  ob2.putamt();
  
  return 0;
}
