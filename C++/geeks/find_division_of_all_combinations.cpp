/*
Objective is to find the sum of all the A[i]/A{j] pairs in an array A,
where 0<=i,j<=N;

- All elements of the array are positive integers
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int sum_of_all_divs(vector<int> & , int);

int main()
{
    int n;
    cin >> n;
    vector<int> A(n, 0);

    for(int & i : A)
    {
        cin >> i;
    }

    cout << sum_of_all_divs(A, n);

    return 0;
}

int sum_of_all_divs(vector<int> & A, int n)
{
    int sum = 0;
    map<int, int> m;    

    // Calulating the frequency of all the elements occuring in the array
    for(int & i : A)
    {
        m[i]++;
    }
    for(map<int, int>::iterator itrj = m.begin(); itrj != m.end(); itrj++)
    {
        for(map<int, int>::iterator itri = itrj; itri != m.end(); itri++)
        {
            if(itri -> first == itrj -> first)
            {
                sum += itri -> second;
            }
            else
            {
                cout << (int)((itri -> first)/(itrj -> first)) << " " << (int)((itrj -> first)/(itri -> first)) << endl;
                sum += (itri -> second * itrj -> second)*((int)((itri -> first)/(itrj -> first)) + (int)((itrj -> first)/(itri -> first)));
            }
        }
    }
    return sum;
}