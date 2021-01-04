#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T>
struct node
{
    T key = (T)0;
    node<T> * next = nullptr;
};

template <class T>
class LinkedList
{
    private:
    node<T> *head = nullptr;
    node<T> *tail = nullptr;
    int num_elements = 0;

    public:
    void insert(T, int position = 1);
};

/* INSERT function 
Enter the poistion of the key to include */
template <class T>
void LinkedList<T>::insert(T key, int position)
{
    if(head == nullptr)
    {
        if(position != 1) {
            throw "Position value exceeds number of elements i the list";
            return;
        }
        head = new node<T>{key};
        return;
    }
    node<T> *temp = new node<T>{0, head};
    for(int curr_pos = 1; curr_pos < position; curr_pos++)
    {
        temp = temp -> next;
    }
    node<T> *new_node = new node<T>{key};
    new_node -> next = temp -> next;
    temp -> next = new_node;
}

#endif