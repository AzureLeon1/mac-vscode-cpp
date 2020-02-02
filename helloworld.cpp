#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    // valid in C++14, invalid in C++11 (列表初始化和foreach)
    // vector<string> msg {"Hello", "C++", "World", "from", "VS Code!"};
    // for (const string& word : msg)
    // {
    //     cout << word << " ";
    // }
    // cout << endl;

    // valid in C++11
    string msg_array[5] = {"Hello", "C++", "World", "from", "VS Code!"};
    vector<string> msg(msg_array, msg_array+5);
    vector<string>::iterator it;
    for (it = msg.begin(); it < msg.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // test input
    int n;
    cin >> n;
    cout << n << endl;
    
    return 0;
}