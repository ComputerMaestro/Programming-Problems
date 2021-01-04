#include <iostream>
#include <vector>
#include ".\Data_structures\LinkedList.h"

using namespace std;

template <typename T>
struct node<T> * insertion_sort(struct node<T> *);

int main()
{
    int n;
    cout << "Enter the number of elements of list to be sorted:" << endl;
    cin >> n;

    node<int> *head = new node<int>, *tail = head, *sorted;
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            cin >> head->key;
            continue;
        }
        node<int>* new_node = new node<int>;
        cin >> new_node->key;
        tail->next = new_node;
        tail = new_node;
    }
    sorted = insertion_sort(head);
    printf("head");
    for(node<int> * curr_node = sorted; curr_node != nullptr; curr_node = curr_node->next)
    {
        printf(" -> %d", curr_node->key);
    }
    return 0;
}

template <typename T>
struct node<T> * insertion_sort(struct node<T> * head)
{
    if(head == nullptr)
        return head;
    struct node<T> * sorted_head = head, *sorted_node, *temp;
    head = head->next;
    sorted_head->next = nullptr;
    while(head != nullptr)
    {
        sorted_node = new node<T>;
        sorted_node->next = sorted_head;
        while((sorted_node->next != nullptr) && (head->key < (sorted_node->next)->key))
        {
            sorted_node = sorted_node->next;
        }
        temp = head;
        head = head->next;
        temp->next = sorted_node->next;
        sorted_node->next = temp;
        if(temp->next == sorted_head)
            sorted_head = temp;
    }
    return sorted_head;
}