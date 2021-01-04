#include <iostream>
#include <vector>
#include <cmath>
#include ".\Data_structures\LinkedList.h"

using namespace std;

template <typename T>
void bucket_sort(vector<float> & A, int n);

int main()
{
    int n;
    cout << "Enter the number elements in the array to be sorted:" << endl;
    cin >> n;

    vector<float> A;
    for(float i = 0; (A.size() < n) && (cin >> i);)
    {
        A.push_back(i);
    }
    bucket_sort<float>(A, n);
    for(auto e : A)
    {
        printf("%.2f", e);
    }
    return 0;
}

template <typename T>
struct node<T> * custom_insertion_sort(struct node<T> *sorted_head, struct node<T> *new_node)
{
    struct node<T> *sorted_node = new node<T>;
    sorted_node->next = sorted_head;
    while((sorted_node->next != nullptr) && (new_node->key < (sorted_node->next)->key))
    {
        sorted_node = sorted_node->next;
    }
    new_node->next = sorted_node->next;
    sorted_node->next = new_node;
    if(new_node->next == sorted_head)
        sorted_head = new_node;
    return sorted_head;
}

template <typename T>
void bucket_sort(vector<float> & A, int n)
{
    int k = 10;
    vector<node<T> *> B(k, nullptr);
    for(float i : A)
    {
        node<T> * new_node = new node<T>{i};
        if(B[floor(k*i)] == nullptr)
        {
            B[floor(k*i)] = new_node;
            continue;
        }
        B[floor(k*i)] = custom_insertion_sort(B[floor(k*i)], new_node);
    }
    int i = n-1;
    for(auto x = B.rbegin(); x != B.rend(); x++)
    {
        if(*x != nullptr)
        {
            for(node<T> *y = *x; y != nullptr ; y = y -> next, i--)
            { 
                A[i] = y -> key;
            }
        }
    }
}