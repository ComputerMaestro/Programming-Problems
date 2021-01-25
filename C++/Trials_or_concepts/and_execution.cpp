#include <iostream>

using namespace std;

bool return_boolean(bool output)
{
    cout << "function executed" << endl;
    return output;
}

main()
{
    bool a = false;

    if( a && return_boolean(true))
    {
        cout << "executed main" << endl;
    }
}