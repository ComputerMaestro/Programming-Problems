// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int n;
    int m;
    int new_color;
    int cur_color;
public:
    bool isValid(int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    void recurse_image(vector<vector<int>>& image, vector<vector<bool>>& explored, int x, int y)
    {
        explored[x][y] = true;
        image[x][y] = new_color;
        for(int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i], next_y = y + dy[i];
            if(isValid(next_x, next_y) && !explored[next_x][next_y] && (image[next_x][next_y] == cur_color))
            {
                recurse_image(image, explored, next_x, next_y);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();
        new_color = newColor;
        cur_color = image[sr][sc];
        vector<vector<bool>> explored(n, vector<bool>(m, false));
        recurse_image(image, explored, sr, sc);
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends