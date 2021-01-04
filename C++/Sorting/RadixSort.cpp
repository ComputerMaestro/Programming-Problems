#include <iostream>
#include <vector>
#include <cmath>
#include "CountingSort.h"

using namespace std;

int max_element(vector<int> & A);
vector<int> counting_sort(vector<int> & A, int , int , int);
void radix_sort(vector<int> & A, int);

int main()
{
    int n;
    cout << "Enter the number of elements in array:" << endl;
    cin >> n;
    vector<int> A;
    for(int i = 0; (A.size() < n) && (cin >> i))
    {
        A.push_back(i);
    }
    radix_sort(A, n);
    return 0;
}

int max_element(vector<int> & A)
{
    int max = A[0];
    for(int a : A)
    {
        if(a > max)
        {
            max = a;
        }
    }
    return max;
}

vector<int> counting_sort(vector<int> & A, int d, int n, int k)
{

    vector<int> B(n, 0), C(k+1, 0);
    int div = pow(10, d);
    for(int &i : A)
    {
        C[(i%div - i%(div/10))/(div/10)] += 1;
    }
    for(int i = 1; i <= k; i++)
    {
        C[i] += C[i-1];
    }
    for(auto i = A.rbegin(); i != A.rend(); i++)
    {
        B[C[((*i)%div - (*i)%(div/10))/(div/10)]-1] = *i;
        C[((*i)%div - (*i)%(div/10))/(div/10)] -= 1;
    }

    return B;
}

void radix_sort(vector<int> & A, int n)
{
    int max = max_element(A.begin(), A.end());
    vector<int> D(n, 0);
    for(int d = 1; pow(10, d-1) < max ; d++)
    {
        A = counting_sort(A, d, n, k);
    }
}