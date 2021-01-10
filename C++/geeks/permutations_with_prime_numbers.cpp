#include <iostream>
#include <string>

using namespace std;

int factorial(int );
int sieve_of_eratoshenes(int );

int main()
{
    int n, primes;
    cin >> n;



    return 0;
}

int factorial(int n)
{
    return ((n == 1)||(n==0)) ? 1 : n * factorial(n-1);
}

int sieve_of_eratosthenes(int n)
{
    bool bool_arr[n] = {};
    bool_arr[0] = false;
    bool_arr[1] = true;
    int p =2;
    while(p*p <= n)
    {
        for(int i = 2; p * p <= n; i++)
        {
            bool_arr[p*i-1] = false; 
        }
        p++;
        while(!bool_arr[p])
        {
            p++;
        }
    }
}