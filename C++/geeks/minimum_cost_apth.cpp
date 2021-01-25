// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


struct node
{
    int i, j, val;
    bool operator()(node & a, node & b)
    {
        return a.val > b.val;
    }
};
class Solution {
    int n = 0;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
public:
    bool isValid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    int minimumCostPath(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> shortest(n, vector<int>(n, INT_MAX));
        vector<vector<bool>> explored(n, vector<bool>(n, false));
        shortest[0][0] = grid[0][0];
        priority_queue<node, vector<node>, node> minheap;
        minheap.push({0, 0, grid[0][0]});
        node new_n{0, 0, grid[0][0]};
        while(!minheap.empty() && (new_n.i != n-1 || new_n.j != n-1))
        {
            new_n = minheap.top();
            minheap.pop();
            if(!explored[new_n.i][new_n.j])
            {
                explored[new_n.i][new_n.j] = true;
                for(int i = 0; i < 4; i++)
                {   
                    int p = new_n.i + dx[i];
                    int q = new_n.j + dy[i];
                    if(isValid(p, q) && !explored[p][q])
                    {
                        shortest[p][q] = min(shortest[new_n.i][new_n.j] + grid[p][q], shortest[p][q]);
                        minheap.push({p, q, shortest[p][q]});
                    }
                }
            }
        }
        return shortest[n-1][n-1];
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends