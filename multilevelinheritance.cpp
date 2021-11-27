#include<iostream>
using namespace std;

class stu
{
protected:
int roll;
public:
void getroll(int);
void putroll();
};

void stu :: getroll(int x)
{
roll=x;
}

void stu :: putroll()
{
cout<<"Roll no.: "<<roll<<endl;
}

class test : public stu
{
protected:
float m1,m2;
public:
void getmarks(float,float);
void putmarks();
};

void test :: getmarks(float x , float y)
{
m1=x;
m2=y;
}

void test :: putmarks()
{
cout<<"Marks of "<<"Test 1: "<<m1<<endl<<"Marks of Test 2: "<<m2<<endl;
}

class result : public test
{
float total;
public:
void display()
{
total=m1+m2;
putroll();
putmarks();
cout<<"Total: "<<total<<endl;
}
};

int main()
{
result res;
res.getroll(20);
res.getmarks(28.3,56.8);
res.display();
return 0;
}
