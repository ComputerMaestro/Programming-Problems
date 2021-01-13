#include <iostream>
#include <string>

using namespace std;

string remDup(string & str)
{
    int s = str.size();
    if(s <= 1)
    {
        return str;
    }
    string out = "";
    int i = 0;
    while(i < str.size())
    {
        int count = 1;
        char ch = str[i];
        i++;
        while((i < str.size()) && (ch == str[i]))
        {
            count++;
            i++;
        }
        if(count == 1)
        {
            out += ch;
        }
    }
    if(out.size() == s)
    {
        return out;
    }
    return remDup(out);
}

int main() {
	
	int t;
	cin >> t;
	
	while(t--)
	{
	    string str;
	    cin >> str;
	    
	    cout << remDup(str) << endl;
	}
	
	return 0;
}