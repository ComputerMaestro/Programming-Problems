#include <bits/stdc++.h>

using namespace std;

bool ispar(string x)
{
    stack<char> S;
    for(int i = 0; i < x.size(); i++)
    {
        char c = x[i];
        switch(c)
        {
            case '(': S.push(c);
            break;
            case '{': S.push(c);
            break;
            case '[': S.push(c);
            break;
            case ')': if(S.empty() || (S.top() != '(')) {return false;}
            else {S.pop();}
            break;
            case ']': if(S.empty() || (S.top() != '[')) {return false;}
            else {S.pop();}
            break;
            case '}': if(S.empty() || (S.top() != '{')) {return false;}
            else {S.pop();}
            break;
        }
    }
    if(S.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int t;
    string a;
    cin >> t;
    while(t--)
    {
        cin >> a;
        if(ispar(a))
        {
            cout << "balanced" << endl;
        }
        else
        {
            cout << "not balanced" << endl;
        }
        
    }

    return 0;
}