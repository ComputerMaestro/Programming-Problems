#include <iostream>
#include <vector>
#include <random>

using namespace std;

int partition(vector<int> & , int, int);
void swap(int &, int &);
void quick_sort(vector<int> &, int , int);

default_random_engine gen;

int main()
{
    vector<int> A;
    int array_length;
    cout << "Enter the number of elements to be entered in array for sorting:"<< endl;
    cin >> array_length;
    for(int i = 0; (A.size()<array_length)&&(cin >> i);)
    {
        A.push_back(i);
    }
    quick_sort(A, 0, A.size()-1);
    for(auto &i : A)
    {
        cout << i << endl;
    }
    return 0;
}

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> & A, int p, int r)
{
    uniform_int_distribution<int> rand_num_dist(p, r);
    int i = p, rand_num = rand_num_dist(gen);
    int pivot = A[rand_num];
    swap(A[r], A[rand_num]);
    for(auto j = A.begin()+p; j <= (A.begin()+r-1); j++)
    {
        if(*j < pivot)
        {
            swap(*j, A[i]);
            i++;
        }
    }
    swap(A[r], A[i]);
    return i;
}

void quick_sort(vector<int> & A, int p, int r)
{
    cout << "yash"<<endl;
    if((r+1 - p)<2)
        return;
    int q = partition(A, p, r);
    quick_sort(A, p, q-1);
    quick_sort(A, q+1, r);
}