#include <iostream>

using namespace std;

template <typename T, int K = 0>
struct node
{
    T key = (T)K;
    node<T> * next = nullptr;
};

template <typename T>
struct node<T> * custom_insertion_sort(struct node<T> *sorted_head, struct node<T> *new_node)
{
    node<int> * N = new node<int>;
    return N;
}

int main()
{
    node<int, 0> * A = new node<int, 0>;

    return 0;
}