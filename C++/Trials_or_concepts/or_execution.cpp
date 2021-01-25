#include <iostream>

using namespace std;

bool return_true(bool output)
{
    cout << "function executed" << endl;
    return output;
}

main()
{
    bool a = false;

    if(a || return_true(true))
    {
        cout << "executed main" << endl;
    }
}