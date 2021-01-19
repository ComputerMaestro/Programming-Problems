// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends




class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        
        int LCS[n + 1][m + 1];
        int maximum = 0;
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(i == 0 || j == 0)
                {
                    LCS[i][j] = 0;
                }
                else if(S1[i-1] == S2[j-1])
                {
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                    if(LCS[i][j] > maximum)
                    {
                        maximum = LCS[i][j];
                    }
                }
                else
                {
                    LCS[i][j] = 0;
                }
                
            }
        }
        return maximum;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends