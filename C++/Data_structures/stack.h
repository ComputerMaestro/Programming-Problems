#ifndef STACK_H
#define STACK_H

template <class>
class stack
{
    T *top = nullptr;

    public:
    T *top();
    void push(T);
    T pop();
};

template <class>
stack<T> *stack<T>::top()
{
    return top;
}

template <class>
void stack<T>::push(T key)
{
    if(top == nullptr)
    {
        top = new T;
        *top = key;
        return;
    }
    top++:
    *top = 
}

#endif