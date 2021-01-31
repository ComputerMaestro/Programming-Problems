#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> find_cost(vector<int> & candies, int k)
{
    pair<int, int> costs(0, 0);
    
    sort(candies.begin(), candies.end());
    
    int bought = 0, i = 0;
    while(bought < candies.size())
    {
        costs.first += candies[i];
        bought += 1+k;
        i++;
    }
    
    bought = 0, i = candies.size()-1;
    while(bought < candies.size())
    {
        costs.second += candies[i];
        bought += 1 + k;
        i--;
    }
    
    return costs;
}

int main() {
	
	int t; cin >> t;
	
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    vector<int> candies; 
	    for(int i = 0; i < n; i++)
	    {
	        candies.push_back(0);
	        cin >> candies[i];
	    }
	    
	    pair<int, int> output = find_cost(candies, k);
	    cout << output.first << " " << output.second << endl;
	}
	
	return 0;
}