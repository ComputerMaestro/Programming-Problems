#include <iostream>
#include <vector>
#include <string>

using namespace std;

void sort_string(string &);
void permute_string(string &, string &);

int main() {
	int t;
    cin >> t;
    vector<string> cases;
    for(;t > 0; t--)
    {
        string temp;
        cin >> temp;
        sort_string(temp);
        cases.push_back(temp);
    }
	
    for(string & str : cases)
    {
        string cur("");
        permute_string(str, cur);
        cout << endl;
    }
	
	return 0;
}

void sort_string(string & str)
{
    string temp = str;
    int c[26] = {0};
    for(char & ch : str)
    {
        c[int(ch - 'A')]++;
    }
    for(int i = 1; i < 26; i++)
    {
        c[i] += c[i-1];
    }
    for(int i = 0; i < str.size(); i++)
    {
        str[c[int(temp[i] - 'A')]-1] = temp[i];
        c[int(str[i] - 'A')]--;
    }
}

void permute_string(string & left, string & cur)
{
    if(left.size() == 0)
    {
        cout << cur << " ";
        return;
    }
    for(int i = 0; i < left.size(); i++)
    {
        string temps = left, tempc = cur + left[i];
        temps.erase(i, 1);
        permute_string(temps, tempc);
    }
    return;
}