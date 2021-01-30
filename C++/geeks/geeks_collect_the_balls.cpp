// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int maxBalls(int N, int M, int a[], int b[]){
        int i = 0, j =0, balls1 = 0, balls2 = 0;
        while(i < N && j < M)
        {
            if(a[i] > b[j])
            {
                balls2 += b[j];
                j++;
            }
            else if(a[i] < b[j])
            {
                balls1 += a[i];
                i++;
            }
            else
            {
                balls1 += a[i];
                balls2 += b[j];
                if(balls1 > balls2)
                {
                    balls2 = balls1;
                }
                else
                {
                    balls1 = balls2;
                }
                i++;
                j++;
            }
        }
        
        if(a[i-1] == b[j-1])
        {
            if(balls1 > balls2)
            {
                balls2 = balls1;
            }
            else
            {
                balls1 = balls2;
            }
        }
        
        while(i < N)
        {
            balls1 += a[i];
            i++;
        }
        while(j < M)
        {
            balls2 += b[j];
            j++;
        }
        
        return balls1 > balls2 ? balls1 : balls2;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        int a[N], b[M];
        for(int i = 0;i < N;i++)
            cin>>a[i];
        for(int i = 0;i < M;i++)
            cin>>b[i];
        
        Solution ob;
        cout<<ob.maxBalls(N, M, a, b)<<"\n";
    }
    return 0;
}  // } Driver Code Ends