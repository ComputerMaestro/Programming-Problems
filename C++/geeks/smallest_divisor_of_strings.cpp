#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'findSmallestDivisor' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING t
 */

int findSmallestDivisor(string s, string t) {
    string temp = t;
    while(s.size() > temp.size())
    {
        temp += t;
    }
    if(temp == s)
    {
        cout << "div" << endl;
        string smallest(1, t[0]);
        int i = 1, j = 0;
        while(i < t.size())
        {
            cout << i << endl;
            cout << smallest << endl;
            string smallest_temp = "";
            bool flag = false;
            while((i < t.size()) && (t[i] == smallest[j]))
            {
                cout << "while" << endl;
                j++;
                i++;
                if(j == smallest.size())
                {
                    smallest_temp += smallest;
                    j = 0;
                }
            }
            if(i == t.size())
            {
                if(j == 0)
                {
                    return smallest.size();
                }
                else
                {
                    return t.size();
                }
            }
            else if(flag)
            {
                smallest = smallest_temp + smallest.substr(0, j+1) + string(1, t[i]);
            }
            else
            {
                smallest += t[i];
            }
            
            i++;
            j = 0;
        }
    }
    
    return -1;
}

int main()
{
    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int result = findSmallestDivisor(s, t);

    cout << result << endl;

    return 0;
}
