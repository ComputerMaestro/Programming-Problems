// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends


long long  numberOfPaths(int m, int n)
{
    long long paths = 1;
    for(int i = n; i < (m + n - 1); i++)
    {
        paths *= i;
        paths /= (i -n + 1);
    }
    return paths;
}

// { Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends