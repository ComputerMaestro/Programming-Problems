// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    void DFS(vector<vector<char>>& grid, vector<vector<bool>>& explored, int i, int j)
    {
        explored[i][j] = true;
        for(int a = i-1; a <= i+1; a++)
        {
            if((a >= grid.size()) || (a < 0))
            {
                continue;
            }
            for(int b = j-1; b <= j+1; b++)
            {
                if((b >= grid[0].size()) || (b < 0))
                {
                    continue;
                }
                if((!(explored[a][b])) && (grid[a][b] == '1'))
                {
                    DFS(grid, explored, a, b);
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), islands = 0;
        vector<vector<bool>> explored(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((!explored[i][j]) && (grid[i][j] == '1'))
                {
                    islands++;
                    DFS(grid, explored, i, j);
                }
            }
        }
        
        return islands;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends