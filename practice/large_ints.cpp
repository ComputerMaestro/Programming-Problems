#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string add(string & a, string & b)
{
    string output = "";
    int al = a.length(), bl = b.length();
    int l = min(al, bl);
    int temp, carry = 0;
    for(int i = 0; i < l; i++)
    {
        temp = (int)(a[al - i - 1] - '0') + (int)(b[bl - i - 1] - '0') + carry;
        carry = (temp%100 - temp%10)/10;
        output = to_string(temp%10) + output;
    }
    if(al > bl)
    {
        return a.substr(0, al - l) + output;
    }
    else
    {
        return b.substr(0, bl - l) + output;
    }
}

string mul(string & A, string & B)
{
    if(A.length() <= 1 && (B.length() <= 1))
    {
        return (int)(A[0] - '0')*(int)(B[0] - '0');
    }
    int al = A.length(), bl = B.length();
    string a = A.substr(0, al-floor(al/2)), b = A.substr(al - floor(al/2), floor(al/2));
    string c = B.substr(0, bl-floor(bl/2)), d = B.substr(bl - floor(bl/2), floor(bl/2));
    string output = add(add(mul(a, c)+string(floor(al/2)+floor(bl/2), '0'), mul(a, d)+string(floor(al/2), '0'), add(mul(b, c)+string(floor(bl/2), '0'), mul(b, d)));
    return  output;
}

// string sub(string & a,string & b)
// {

// }

int main()
{
    int a, b;
    cin >> a >> b;

    string A = to_string(a);
    string B = to_string(b);

    // cout << "Multiplication" << mul(A, B) << endl;
    cout << "Additon" << add(A, B) << endl;
    cout << string(5, '0') << endl;
    // cout << "Subtraction" << sub(A, B) << endl;

    return 0;
}