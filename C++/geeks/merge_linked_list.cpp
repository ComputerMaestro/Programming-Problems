// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

Node* mergeKLists(Node* arr[], int N);

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}

   		Node *res = mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
// } Driver Code Ends


/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

struct compare
{
    bool operator()(const Node * a, const Node * b)
    {
        return a -> data > b -> data;
    }
};

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
Node * mergeKLists(Node *arr[], int N)
{
    priority_queue<Node *, vector<Node *>, compare> minheap;
    Node * head, *temp;
    for(int i = 0; i < N; i++)
    {
        minheap.push(arr[i]);
    }
    
    head = minheap.top(), temp = head;
    if(minheap.top() -> next != NULL)
    {
        minheap.pop();
        minheap.push(temp -> next);
    }
    else
    {
        minheap.pop();
    }
    
    while(!minheap.empty())
    {
        temp -> next = minheap.top();
        temp = minheap.top();
        if(minheap.top() -> next != NULL)
        {
            minheap.pop();
            minheap.push(temp -> next);
        }
        else
        {
            minheap.pop();
        }
    }
    temp -> next = NULL;
    return head;
}

