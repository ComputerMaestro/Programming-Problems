#include <iostream>

using namespace std;

class Test
{
    int first_mem;
    int s;
    public:
    void getdata(int f)
    {
        first_mem = f;
    }
    Test(){};
    Test(int f){first_mem = f;}
    void setdata(Test & t, int & a);
};
void Test::setdata(Test & t, int & a)
{
    a = t.first_mem;
}

int main()
{
    Test t1;
    Test t2(3);
    int in;
    cin >> in;
    t1.getdata(in);
    int a;
    t1.setdata(t2, a);

    cout << in << endl;
    cout << a << endl;
    return 0;
}