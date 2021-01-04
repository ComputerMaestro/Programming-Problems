#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <utility>

using namespace std;

void find_biggest_palindrome(string &);

int main() {
	int t;
	cin >> t;
	vector<string> cases;
	for(;t > 0; t--)
	{
	    string temp;
	    cin >> temp;
	    cases.push_back(temp);
	}
	
	for(string & str : cases)
	{
	    find_biggest_palindrome(str);
	}
}

void find_biggest_palindrome(string & str)
{
    vector<pair<string, int>> palins;
    string max = str.substr(0, 1), new_m = "";
    int m = 0;
    string S = "";
    bool flag = false, mid = false;
    for(int i = 0; i < str.size(); i++)
    {
        if((S.size() > 1) && (!mid) && (str[i] == S[S.size()-2]) && (!flag))
        {
            palins.push_back(pair<string, int>(S.substr(S.size()-2, 2) + str[i], i+1));
        }
        if(str[i] == S[S.size()-1])
        {
            palins.push_back(pair<string, int>(string(2, str[i]), i+1));
        }
        S += str[i];
    }
    for(auto & palin : palins)
    {
        new_m = palin.first;
        if(new_m.size() == 3)
        {
            S = str.substr(0, palin.second-3);
        }
        else
        {
            S = str.substr(0, palin.second-2);
        }
        for(int i = palin.second; (i < str.size()) && (S.size() > 0); i++)
        {
            if(str[i] == S[S.size()-1])
            {
                S.pop_back();
                new_m = str[i] + new_m + str[i];
            }
            else
            {
                if(new_m.size() > max.size())
                {
                    max = new_m;
                }
                break;
            }
            if(i == str.size()-1)
            {
                if(new_m.size() > max.size())
                {
                    max = new_m;
                }
                break;
            }
        }
        if(S.size() == 0)
        {
            if(new_m.size() > max.size())
            {
                max = new_m;
            }
        }
    }
    if(new_m.size() > max.size())
    {
        cout << new_m << endl;
    }
    else
    {
        cout << max << endl;
    }
}