#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct bst_node
{
    T key;
    node<T> *p = nullptr;
    node<T> *l = nullptr;
    node<T> *r = nullptr;
};

template <class T>
class BST
{
    bst_node<T> *root;
    
    public:
    node<T> * tree_min();
    node<T> * tree_max();
    auto search_bst(T);
    void insert_bst(T);
    void transplant(node<T> *, node<T> *);
    void delete_bst(T);
    vector<T> inorder_walk(bst_node<T> *curr_node = nullptr);
    vector<T> preorder_walk();
    vector<T> postorder_walk();
    bst_node<T> *successor(T);
    bst_node<T> *predecessor(T);
};

template <class T>
node<T> * BST<T>::tree_min()
{
    if(root != nullptr)
    {
        for{bst_node<T> *minimum = root; minimum -> l != nullptr; minimum = minimum -> l}{}
        return minimum -> key;
    }
    throw "Tree is not defined";
}

template <class T>
node<T> * BST<T>::tree_max()
{
    if(root != nullptr)
    {
        for{node<T> *maximum = root; maximum -> r != nullptr; maximum = maximum -> r}{}
        return maximum;
    }
    throw "Tree is not defined";
    return root;
}

template <class T>
auto BST<T>::search_bst(T key)
{
    if(root != nullptr)
    {
        bst_node<T> * curr_node = root;
        while(curr_node != nullptr)
        {
            if (key == curr_node -> key)
            {
                return curr_node;
            }
            else if(key < curr_node -> key)
            {
                if(curr_node == nullptr)
                {
                    return false;
                }
                curr_node = curr_node -> l;
            }
            else if(curr_node -> r == nullptr)
            {
                curr_node = curr_node -> r;
            }
            else
            {
                return false;
            }
            
        }
        return False;
    }
}

template <class T>
void BST<T>::insert_bst(T key)
{
    if(root != nullptr)
    {
        bst_node<T> * curr_node = root;
        while(curr_node -> l != nullptr)
        {
            if(key < curr_node -> key)
            {
                if(curr_node -> l == nullptr)
                {
                    curr_node -> = new bst_node<T>{key};
                    return;
                }
                curr_node = curr_node -> l;
            }
            else if(curr_node -> r == nullptr)
            {
                curr_node -> r = new bst_node<T>{key};
                return;
            }
            else
            {
                curr_node = curr_node -> r;
            }
        }
    }
    root = new bst_node<T>{key};
    return;
}

template <class T>
void transplant(node<T> *u, node<T> *v)
{
    if(u -> p == nullptr)
    {
        root = v;
    }
    else if(u -> p -> left == u)
    {
        u -> p -> l = v;
        v -> p = u -> p;
    }
    else
    {
        u -> p -> r = v;
        v -> p = u -> p;
    }
}

template <class T>
void BST<T>::delete_bst(T key)
{
    auto key_node = search_bst(key)
    if(key_node)
    {
        if(key_node -> l == nullptr)
        {
            transplant(key_node, key_node -> r);
            return;
        }
        else if(key_node -> r == nullptr)
        {
            transplant(key_node, nullptr); 
            return;
        }
        else
        {
            node<T> *y = tree_min(key_node -> r);
            if(y == key_node -> r)
            {
                transplant(z, y);
                
                return;
            }
            transplant(y, y -> r);
            y -> r = z -> r;
            y -> p = z -> p;
            y -> l = z -> l;
            if(z -> p -> l == z)
            {
                z -> p -> l = y;
            }
            else
            {
                z -> p -> r = y;
            }
            
        }
    }
}

template <class T>
vector<T> BST<T>::inorder_walk()
{
    vector<T> output;
    if(root != nullptr)
    {
        stack<T> S;
        bst_node<T> *curr_node = root;
        
        while(stack.isempty())
        {
            if(curr_node != nullptr)
            {
                S.push(curr_node);
                curr_node = curr_node -> l;
            }
            else
            {
                *curr_node = S.pop();
                output.push_back(curr_node -> key);
                curr_node = curr_node -> r;
            }
        }
    }
    return output;
}

template <class T>
vector<T> BST<T>::preorder_walk()
{
    vector<T> output;
    if(root != nullptr)
    {
        stack<T> S;
        bst_node<T> *curr_node = root;
        while(stack.isempty())
        {
            if(curr_node != nullptr)
            {
                output.push_back(curr_node -> key);
                S.push(curr_node);
                curr_node = curr_node -> l;
            }
            else
            {
                *curr_node = S.pop();
                curr_node = curr_node -> r;
            }
        }
    }
    return output;
}

// template <class T>
// vector<T> BST<T>::postorder_walk()
// {
//     vector<T> output;
//     if(root != nullptr)
//     {
//         stack S;
//         S.push(root);
//         bst_node<T> *curr_node = root, *parent_node;
//         while(S.isempty())
//         {
//             if(curr_node != S.top())
//             {
//                 if(curr_node -> l != nullptr)
//                 {
//                     S.push(curr_node);
//                     curr_node = curr_node -> l;
//                     continue;
//                 }
//                 if(curr_node -> r != nullptr)
//                 {
//                     S.push(curr_node);
//                     curr_node = curr_node -> r;
//                     continue;
//                 }
//             }
//             S.pop();
//             output.push_back(curr_node -> key);
//             parent_node = S.top();
//             if(parent_node -> l == curr_node)
//             {
//                 curr_node = parent_node -> r;
//             }
//             else
//             {
//                 curr_node = parent_node;
//             }
            
//         }
//     }
//     return output;
// }
    // template <class T>
    // bst_node<T> * BST<T>::successor(T);
    // template <class T>lkjhhj
    // bst_node<T> * BST<T>::predecessor(T);
    // template <class T>