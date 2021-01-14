#include <bits/stdc++.h>

using namespace std;

vector<int> kmp(string & str, string & pat)
{
    // Building LPS array
    int lps[pat.size()] = {0};
    int i = 1, j = 0;
    while(i < pat.size())
    {
        if(pat[j] == pat[i])
        {
            lps[i] = j+1;
            j++;
            i++;
        }
        else
        {
            if(j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j-1];
            }
        }
    }
    
    i = 0, j = 0;
    vector<int> out;
    while(i < str.size())
    {
        if(j < pat.size() && str[i] == pat[j])
        {
            if(j == pat.size()-1)
            {
                out.push_back(i - pat.size() + 1);
            }
            j++;
            i++;
        }
        else
        {
            if(j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j-1];
            }
        }
    }
    return out;
}

int main()
{
    string str, pat;
    cin >> str >> pat;
    vector<int> matches = kmp(str, pat);
    for(int & i : matches)
    {
        cout << i << endl;
    }

    return 0;
}