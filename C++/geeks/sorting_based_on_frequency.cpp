#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> & a, pair<int, int> & b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<pair<int, int>> frequencySort(vector<int> & A)
{
    map<int, int> m;
    for(int & a: A)
    {
        m[a]++;
    }
    vector<pair<int, int>> pairs;
    for(auto a = m.begin(); a != m.end(); a++)
    {
        pairs.push_back(pair<int, int>(a->first, a->second));
    }
    sort(pairs.begin(), pairs.end(), cmp);
    return pairs;
}

int main() {
	
	int t;
	cin >> t;
	
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int> A;
	    for(int i = 0; i < n; i++)
	    {
	       A.push_back(0);
	       cin >> A[A.size()-1];
	    }
	    
	    vector<pair<int, int>> pairs = frequencySort(A);
        for(pair<int, int> & p: pairs)
        {
            while(p.second--)
            {
                cout << p.first << endl;
            }
        }
	}
	
	return 0;
}