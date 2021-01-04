#include <iostream> 
#include <string> 
  
using namespace std; 
  
int main() 
{ 
    string str = "geeksforgeeks a = computer science"; 
    string str1 = "geeks"; 
    string str3;
  
    // Find first occurrence of "geeks" 
    while(getline(cin, str3, ' '))
    {
        if(str3 == "=")
        {
            cout << "yash" << endl;
        }
        cout << str3 << endl;
    }

    cout << str.find(str1); 
    cout << string::npos;
    // if (found != string::npos) 
    //     cout << "First occurrence is " << found << endl; 
  
    // Find next occurrence of "geeks". Note here we pass 
    // "geeks" as C style string. 
    char arr[] = "geeks"; 
    size_t found;
    found = str.find(arr, found+1); 
    if (found != string::npos) 
        cout << "Next occurrence is " << found << endl; 
  
    return 0; 
} 