#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void find(vector<int> &, int);
int BFS(vector<pair<vector<int>, int>> &, int, bool *, vector<int> &);
void execute_queries(int A, vector<int> B, vector<int> C, vector<int> D);

int main()
{
    int A, edges, queries;
    cin >> A >> queries;
    vector<int> B, C, D;
    for(int i = 0; i < A-1; i++)
    {
        B.push_back(0);
        cin >> B[B.size()-1];
        C.push_back(0);
        cin >> C[C.size()-1];
    }
    for(int i = 0; i < queries; i++)
    {
        D.push_back(0);
        cin >> D[D.size()-1];
    }
    execute_queries(A, B, C, D);

    return 0;
}
void remove(vector<int> & a, int key)
{
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == key)
        {
            a.erase(a.begin()+i);
        }
    }
}

int BFS(vector<pair<vector<int>, int>> & tree, int node, bool *exp, vector<int> & counts)
{
    if(tree[node-1].second > -1)
    {
        counts[tree[node-1].second] = 0;
        tree[node-1].second = -1;
    }
    exp[node-1] = true;
    int count = 1;
    for(int n : tree[node-1].first)
    {
        if(!exp[n-1])
        {
            count += BFS(tree, n, exp, counts);
        }
    }
    exp[node-1] = false;
    return count;
}

void execute_queries(int A, vector<int> B, vector<int> C, vector<int> D)
{
    vector<int> counts;
    bool exp[A] = {false};
    vector<pair<vector<int>, int>> tree(A);
    for(int i = 0; i < B.size(); i++)
    {
        tree[B[i]-1].first.push_back(C[i]);
        tree[B[i]-1].second = -1;
        tree[C[i]-1].first.push_back(B[i]);
        tree[C[i]-1].second = -1;
    }
    for(int q : D)
    {
        int b = B[q-1], c = C[q-1];
        remove(tree[b-1].first, c);
        remove(tree[c-1].first, b);
        int cnt_b = BFS(tree, b, exp, counts);
        counts.push_back(cnt_b);
        tree[b-1].second = counts.size()-1;
        int cnt_c = BFS(tree, c, exp, counts);
        counts.push_back(cnt_c);
        tree[c-1].second = counts.size()-1;
        int m = counts[0];
        for(int e : counts)
        {
            if(e > m)
            {
                m = e;
            }
        }
        cout << m << endl;
    }
}