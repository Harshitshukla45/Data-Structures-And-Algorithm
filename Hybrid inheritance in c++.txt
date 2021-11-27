#include <iostream>
using namespace std;
class student
{
    int roll ;
    public:
    void getroll(int x)
    {
        roll=x;
    }
    void putroll()
    {
       cout<<"roll no."<<roll<<endl;
    }
    
};
class test : public student
{
    protected:
    float m1,m2;
    public:
    void getmarks(float x,float y)
    {
      m1=x;
      m2=y;
    }
    void putmarks()
    {
      cout<<"enter two marks ";
      cout<<m1<<" "<<m2<<endl;
    }
};
class sports
{
    protected:
    float sp;
    public:
    void getsp(int p)
    {
        sp=p;
    }
    void putsp()
    {
        cout<<"sport is "<< sp<<endl ;
    }
    
};

class result : public test,public sports
{
    float total;
    public:
    void display()
    {
        total=m1+m2+sp;
        putroll();
        putmarks();
        putsp();
        cout<<"total is "<<total<<endl;
    }
};
int main()
{
   result res;
   res.getroll(20);
   res.getmarks(25.3,56.7);
   res.getsp(5);
   res.display();

    return 0;
}
