#include<iostream>
using namespace std;

class A
{
protected:
int m;
public:
void getm(int);
};

void A :: getm(int x)
{
m=x;
}

class B
{
protected:
int n;
public:
void getn(int);
};

void B :: getn(int x)
{
n=x;
}

class C : public A , public B
{
int c;
public:
void add();
void display();
};

void C :: add()
{
c=m+n;
}

void C :: display()
{
cout<<"Value of m and n: "<<m<<" "<<n<<endl;
cout<<"Value of addition: "<<c<<endl;
}

int main()
{
C obj;
obj.getm(100);
obj.getn(200);
obj.add();
obj.display();
return 0;
}
