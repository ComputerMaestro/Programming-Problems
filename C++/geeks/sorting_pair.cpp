// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


int activitySelection(int start[], int end[], int n){
    pair<int, int> p[n];
    for(int i = 0; i < n; i++)
    {
        p[i].first = end[i];
        p[i].second = start[i];
    }
    sort(p, p+n);
    int count = 0, finish = 0;
    for(pair<int, int> & pr : p)
    {
        if(pr.second >= finish)
        {
            count++;
            finish = pr.first;
        }
    }
    return count;
}

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        int start[n], end[n];
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        
        //function call
        cout << activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends