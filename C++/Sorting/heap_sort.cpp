#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int LEFT(int );
int RIGHT(int );
int PARENT(int );
void swap(int & , int & );
void MAX_HEAPIFY(vector<int> &, int );
void EXTRACT_MAXIMUM(vector<int> & );
int MAXIMUM(vector<int> & );
void BUILD_MAX_HEAP(vector<int> &);

int main()
{
    vector<int> max_heap;
    int n_elements;
    cout << "Enter the number of elements to inserted in heap:" << endl;
    cin >> n_elements;
    for(int i=0, input; i < n_elements; i++)
    {
        cin >> input;
        max_heap.push_back(input);
    }

    //HEAP SORT
    BUILD_MAX_HEAP(max_heap);
    for(int i=n_elements-1; i>0; i--)
    {
        swap(max_heap[0], max_heap[i]);
        vector<int> unsorted(max_heap.begin(), max_heap.begin()+i-1);
        MAX_HEAPIFY(unsorted, 0);
    }
    return 0;
}

int LEFT(int i)
{
    return 2*i;
}

int RIGHT(int i)
{
    return 2*i+1;
}

int PARENT(int i)
{
    return floor(i/2);
}

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = a;
}

int MAXIMUM(vector<int> & heap)
{
    return heap[1];
}

void MAX_HEAPIFY(vector<int> & heap, int i)
{
    int largest = i;
    if(i < heap.size() and heap[i]<heap[LEFT(i)])
    {
        largest = LEFT(i);
    }
    
    if(heap[largest] < heap[RIGHT(i)])
    {
        largest = RIGHT(i);
    }
    if(largest != i)
    {
        swap(heap[i], heap[largest]);
        MAX_HEAPIFY(heap, largest);
    }
    
}

void BUILD_MAX_HEAP(vector<int> & heap)
{
    if(heap.empty())
    {
        printf("ERROR: heap does have any element in it");
        return;
    }
    for(int i=floor(heap.size()/2); i>=1; i--)
    {
        MAX_HEAPIFY(heap, i);
    }
}

void EXTRACT_MAXIMUM(vector<int> & heap)
{
    if(heap.empty())
    {
        printf("ERROR: heap does have any element in it");
        return;
    }
    int max = heap[1];
    swap(heap[1],heap[heap.size()]);
    heap.pop_back();
    MAX_HEAPIFY(heap, 1);
}