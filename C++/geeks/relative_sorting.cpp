#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>    // For hashing

using namespace std;

vector<int> sort_order(vector<int> &, vector<int> &);

int main() {
    int t;
    cin >> t;

    for(; t > 0; t--)
    {
        int N, M, temp;
        cin >> N >> M;

        vector<int> A1, A2, out;
        for(; N > 0; N--)
        {
            cin >> temp;
            A1.push_back(temp);
        }

        for(; M > 0; M--)
        {
            cin >> temp;
            A2.push_back(temp);
        }
        
        out = sort_order(A1, A2);
        for(int & i : out)
        {
            cout << i << " ";
        }
        cout << endl;
    }
	
	return 0;
}

vector<int> sort_order(vector<int> & A1, vector<int> & A2)
{
    unordered_map<int, int> um;
    vector<int> out;
	
	for(int i : A2)
	{
	    um[i] = 0;
	}
	
	for(int i : A1)
	{
	    unordered_map<int, int>::iterator itr = um.find(i);
        if(itr == um.end())
        {
            out.push_back(i);
        }
        else
        {
            um[i]++;
        }
	}
    sort(out.begin(), out.end());
    for(auto i = A2.rbegin(); i != A2.rend(); i++)
    {
        vector<int> temp(um[*i], *i);
        out.insert(out.begin(), temp.begin(), temp.end());
    }
    return out;
}