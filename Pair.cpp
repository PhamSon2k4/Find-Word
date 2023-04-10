#include <unordered_set>
#include <set>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n; 
    cin >> n;
    set<string> s;

    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        s.insert(str);
    }
    cout << s.size() << endl;
    for (string x : s)
    {
        cout << x << " ";
    }
    return 0;
}
