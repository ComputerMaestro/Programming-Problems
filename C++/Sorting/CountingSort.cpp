#include <iostream>
#include <vector>

using namespace std;

vector<int> counting_sort(vector<int> & A, int, int);

int main()
{
    vector<int> A, sorted_A;
    int n, k;
    cout << "Enter number of elements to be sorted:" << endl;
    cin >> n;
    for(int i = 0; (A.size() < n) && (cin >> i);)
    {
        if((!k) || (i > k)) {k = i;}
        A.push_back(i);
    }

    sorted_A = counting_sort(A, n, k);
    for(auto &i : sorted_A)
    {
        cout << i << endl;
    }
    return 0;
}

vector<int> counting_sort(vector<int> & A, int n, int k)
{
    vector<int> B(n, 0), C(k+1, 0);
    for(int &i : A)
    {
        C[i] += 1;
    }
    for(int i = 1; i <= k; i++)
    {
        C[i] += C[i-1];
    }
    for(auto i = A.rbegin(); i != A.rend(); i++)
    {
        B[C[*i]-1] = *i;
        C[*i] -= 1;
    }

    return B;
}