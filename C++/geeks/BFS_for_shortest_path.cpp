#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int BFS(vector<vector<int>> & mat, queue<pair<int, pair<int, int>>> & q, vector<vector<bool>> & explored, int x, int y)
{
    int i = q.front().second.first, j = q.front().second.second, count = q.front().first;
    if(x == i && y == j)
    {
        return count;
    }
    q.pop();
    explored[i][j] = true;
    if(i-1 >= 0)
    {
        if(!explored[i-1][j] && (mat[i-1][j] == 1))
        {
            q.push(pair<int, pair<int, int>>(count+1, pair<int, int>(i-1, j)));
        }
    }
    if(i+1 < mat.size())
    {
        if(!explored[i+1][j] && (mat[i+1][j] == 1))
        {
            q.push(pair<int, pair<int, int>>(count+1, pair<int, int>(i+1, j)));
        }
    }
    if(j-1 >= 0)
    {
        if(!explored[i][j-1] && (mat[i][j-1] == 1))
        {
            q.push(pair<int, pair<int, int>>(count+1, pair<int, int>(i, j-1)));
        }
    }
    if(j+1 < mat[0].size())
    {
        if(!explored[i][j+1] && (mat[i][j+1] == 1))
        {
            q.push(pair<int, pair<int, int>>(count+1, pair<int, int>(i, j+1)));
        }
    }
    
    if(q.empty())
    {
        return -1;
    }
    return BFS(mat, q, explored, x, y);
}

int minSteps(vector<vector<int>>& mat, int x, int y)
{
    if(x > mat.size() || y > mat[0].size() || x < 0 || y < 0)
    {
        return -1;
    }
    vector<vector<bool>> explored(mat.size(), vector<bool>(mat[0].size(), false));
    queue<pair<int, pair<int, int>>> q;
    q.push(pair<int, pair<int, int>>(0, pair<int, int>(0, 0)));
    
    return BFS(mat, q, explored, x, y);
}

int main() {
	
	int t;
	cin >> t;
	
	while(t--)
	{
	    int n, m, x, y;
	    cin >> n >> m;
	    
	    vector<vector<int>> mat(n, vector<int>(m));
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < m; j++)
	        {
	            cin >> mat[i][j];
	        }
	    }
	    
	    cin >> x >> y;
	    cout << minSteps(mat, x, y) << endl;
	}
	
	return 0;
}