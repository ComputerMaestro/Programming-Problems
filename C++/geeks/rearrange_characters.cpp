#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool rearrange(string str)
{
    priority_queue<int> mh;
    int freq[26] = {0};
    
    for(char & c : str)
    {
        freq[(int)(c - 'a')]++;
    }
    
    for(int & f : freq)
    {
        mh.push(f);
    }
    
    int top = mh.top(), covered = 0;
    mh.pop();
    
    while(!mh.empty())
    {
        covered += mh.top();
        mh.pop();
        if(covered >= top)
        {
            return true;
        }
    }
    
    return false;
}

int main() {
	
	int t; cin >> t;
	
	while(t--)
	{
	    string str;
	    cin >> str;
	    
	    cout << rearrange(str) << endl;
	}
	
	return 0;
}