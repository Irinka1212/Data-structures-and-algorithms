#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
    string s;
    cin >> s;

    unordered_set<char> set;

    int size = s.length();
    for (int i = 0; i < size; ++i)
    {
        char c = s[i];
        if (set.find(c) != set.end())
            continue;

        bool isSingle = true;
        for (int k = 0; k < size; ++k)
        {
            if (i != k && s[k] == c)
            {
                isSingle = false;
                set.insert(c);
                break;
            }
        }
        if (isSingle)
            std:cout << i << ' ';
    }

    return 0;
}