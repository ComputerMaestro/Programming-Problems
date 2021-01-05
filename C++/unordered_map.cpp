#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, int> um;

    um[1] = 0;
    um[5] = 4;
    um[4] = 2;

    unordered_map<int, int>::iterator i = um.find(5);
    cout << i -> second << endl;

    i -> second = 6;

    auto j = um.find(5);

    cout << j -> second << endl;

    return 0;
}
