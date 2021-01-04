#include<iostream>
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

using namespace std;

class A
{
    public:
        A()
        {
            cout << "A" ;
        }
        ~A()
        {
            cout << "~A";
        }
};

class B : public A
{
    public:
        B()
        {
            cout << "B";
        }
        ~B()
        {
            cout << "~B";
        }

};

int main()
{
    if(fork()>=0)
    {
        printf("*");
        if(fork()==0)
        {
            printf("*");
        }
    }
    else{

    }
    printf("*");

}