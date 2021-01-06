/*
Objective is to find the number of all subarrays whose sum of elements is less than a given number

- All the elements in the original array are positives integers
*/

#include <iostream>
#include <vector>

using namespace std;

int find_subarrays(vector<int> & , int, int );

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cout << find_subarrays(A, N, K) << endl;

    return 0;
}

int find_subarrays(vector<int> & A, int N, int K)
{
    int num = 0;
    int prev_sum = 0;
    for(int i = 0; i < N; i++)
    {
        if(A[i] <= 6)
        {
            num++;
            prev_sum = A[i];
        }
        else
        {
            continue;
        }
        for(int j = i+1; j < N; j++)
        {
            if(A[j]+prev_sum <= 6)
            {
                num++;
                prev_sum += A[j];
            }
            else
            {
                break;
            }
        }
    }
}