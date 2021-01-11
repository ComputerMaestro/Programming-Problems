// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
vector<int> maxSubarraySum(vector<int> & A){
    
    int start = 0, end = 0, max_cur = 0, max_so_far = INT_MIN;
    for(int end = 0; end < A.size(); end++)
    {
        max_cur += A[end];
        if(max_cur < A[end])
        {
            max_cur = A[end];
            start = end;
        }
        if(max_cur > max_so_far)
        {
            max_so_far = max_cur;
        }
    }
    return vector<int>{start, end, max_so_far};
    
}

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        vector<int> a(n, 0);
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        vector<int> A = maxSubarraySum(a);
        cout << "start index :" << A[0] << " || End index : " << A[1] << " || Maximum array sum : " << A[2] << endl;
    }
}
  // } Driver Code Ends