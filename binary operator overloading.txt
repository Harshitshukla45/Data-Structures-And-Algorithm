#include <iostream>
using namespace std;
class number
{
    private:
    int x;
    public:
    void set(int a)
    {
        x = a;
    }
    void get()
    {
        cout << x << endl;
    }
    friend number operator +(number n1 ,number n2);
   
};
 number operator +(number n1,number n2)
    {
        number n3;
        n3.x = n1.x + n2.x;
        return n3;
    }
int main()
{
    number n1,n2,n3;
    int a,b;
    cout << "Enter two number" << endl;
    cin >> a >> b;
    n1.set(a);
    n2.set(b);
    n3 = n1+n2;
    n3.get();
    return 0;
}
