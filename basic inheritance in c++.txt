#include <iostream>
using namespace std;

class employee{
public:
    int id;
    float salary;

    employee(int impid)
    {
      id=impid;
      salary=56000 ;
    }
   employee(){};
    };

    class pro : public employee
    {
    public:
        int code;
        pro(int impid)
        {
            id=impid;
            code=10 ;
        }
        void showdata()
        {
            cout<<id<<endl;
        }
    };


int main()
{
   employee ob1(1) ,ob2(2);

   cout<<ob1.salary<<endl;
   cout<<ob2.salary<<endl;

   pro ob3(20);

   cout<<ob3.code<<endl;
   cout<<ob3.id<<endl;

   ob3.showdata();
    return 0;
}
