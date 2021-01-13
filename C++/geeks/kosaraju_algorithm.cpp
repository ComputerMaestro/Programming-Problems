// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    int t = 0;
	public:
	/*  Function to find the number of strongly connected components
    *   using Kosaraju's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */
    void DFS1(vector<int> * adj, int node, vector<bool> & explored, stack<int> & S)
    {
        explored[node] = true;
        for(int n : adj[node])
        {
            if(!explored[n])
            {
                DFS1(adj, n, explored, S);
            }
        }
        S.push(node);
    }
    
    void DFS2(vector<int> * adj, int node, vector<bool> & explored)
    {
        explored[node] = true;
        for(int & n : adj[node])
        {
            if(!explored[n])
            {
                DFS2(adj, n, explored);
            }
        }
    }
    
    int kosaraju(int V, vector<int> adj[]) {
        vector<int> adj_rev[V];
        vector<bool> explored(V, false);
        stack<int> S;
        for(int i = 0; i < V; i++)
        {
            for(int & v: adj[i])
            {
                adj_rev[v].push_back(i);
            }
        }
        
        for(int i = 0; i < V; i++)
        {
            if(!explored[i])
            {
                DFS1(adj_rev, i, explored, S);
            }
        }
        
        fill(explored.begin(), explored.end(), 0);
        int SCC = 0;
        while(!S.empty())
        {
            if(!explored[S.top()])
            {
                SCC++;
                DFS2(adj, S.top(), explored);
            }
            S.pop();
        }
        
        return SCC;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends