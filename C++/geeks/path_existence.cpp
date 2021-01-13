// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    bool DFS(vector<vector<int>>& grid, vector<vector<bool>>& explored, int i, int j)
    {
        explored[i][j] = true;
        if(grid[i][j] == 2)
        {
            return true;
        }
        if(i-1 >= 0)
        {
            if(!explored[i-1][j] && (grid[i-1][j] >=2))
            {
                if(DFS(grid, explored, i-1, j))
                {
                    return true;
                }
            }
        }
        if(i+1 < grid.size())
        {
            if(!explored[i+1][j] && (grid[i+1][j] >=2))
            {
                if(DFS(grid, explored, i+1, j))
                {
                    return true;
                }
            }
        }
        if(j-1 >= 0)
        {
            if(!explored[i][j-1] && (grid[i][j-1] >= 2))
            {
                if(DFS(grid, explored, i, j-1))
                {
                    return true;
                }
            }
        }
        if(j+1 < grid[0].size())
        {
            if(!explored[i][j+1] && (grid[i][j+1] >= 2))
            {
                if(DFS(grid, explored, i, j+1))
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool is_Possible(vector<vector<int>>& grid) {
        vector<vector<bool>> explored(grid.size(), vector<bool>(grid[0].size()));
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    return DFS(grid, explored, i, j);
                }
            }
        }
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends