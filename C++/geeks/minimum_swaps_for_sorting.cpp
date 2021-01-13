// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution {
private:
public:
	int minSwaps(vector<int>&nums){
	    int swaps = 0;
	    vector<pair<int, int>> dup;
	    for(int i = 0; i < nums.size(); i++)
	    {
	        dup.push_back(pair<int, int>(nums[i], i));
	    }
	    sort(dup.begin(), dup.begin()+nums.size());
	    vector<bool> explored(nums.size(), false);
	    for(int i = 0; i < nums.size(); i++)
	    {
	        if(explored[i] || (dup[i].second == i))
	        {
	            continue;
	        }
	        explored[i] = true;
	        int idx = dup[i].second, cycle_nodes = 1;
	        while(idx != i)
	        {
	            cycle_nodes++;
	            explored[idx] = true;
	            idx = dup[idx].second;
	        }
	        swaps += cycle_nodes-1;
	    }
	    return swaps;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends