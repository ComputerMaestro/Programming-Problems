#include <iostream>
#include <string>
#include "..\Data_structures\LinkedList.h"

using namespace std;

node<int> * reverse(node<int> * head)
{
    node<int> *a = nullptr, *b = head -> next;
    while(b != nullptr)
    {
        b = head -> next;
        head -> next = a;
        a = head;
        head = b;
    }
    head = a;
    return head;
}

int main()
{
    int n;
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
    head = reverse(head);
    for(node<int> * curr_node = head; curr_node != nullptr; curr_node = curr_node->next)
    {
        printf(" -> %d", curr_node->key);
    }

    return 0;
}