// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
  public:
    int recur(int n, int cur, int ops)
    {
        if(cur == n)
        {
            return ops;
        }
        else if(cur*2 > n)
        {
            return ops + n - cur;
        }
        else if(cur*2 == n)
        {
            return ops+1;
        }
        return min(recur(n, cur*2, ops+1), recur(n, cur+1, ops+1));
    }
    int minOperation(int n)
    {
        if(n == 1)
        {
            return 1;
        }
        int ops = 1;
        return recur(n, 1, 1);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends