#include <iostream>
#include <random>

using namespace std;

default_random_engine gen;

void produce(int, int);

int main()
{
    int p, r;
    while(true)
    {
        cin >> p >> r;
        produce(p, r);
    }

    return 0;
}

void produce(int p, int r)
{
    uniform_int_distribution<int> dist(p, r);
    int i =0 ;
    while(i < 5)
    {
        cout << dist(gen) << endl;
        i++;
    }
}