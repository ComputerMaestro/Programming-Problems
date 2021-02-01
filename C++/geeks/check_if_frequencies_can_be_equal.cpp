// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    map<char, int> m1;
	    map<int, bool> m2;
	    int max_freq = 0, min_freq = INT_MAX;
	    for(char & c : s)
	    {
	        m1[c]++;
	    }
	    for(map<char, int>::iterator itr = m1.begin(); itr != m1.end(); itr++)
	    {
	        m2[itr -> second] = true;
	        if(max_freq < itr -> second) max_freq = itr -> second;
	        if(min_freq > itr -> second) min_freq = itr -> second;
	    }
	    if(m2.size() <= 2 && (max_freq - min_freq <= 1 || min_freq == 1)) return true;
	    else return false;
	}
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}


  // } Driver Code Ends