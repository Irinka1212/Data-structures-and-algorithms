#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <map>
using namespace std;


int main()
{
    int n;
    cin >> n;

    map<string, int> mapCount;

    vector<string> input;
    string s;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        input.push_back(s);

        if (mapCount.find(s) != mapCount.end())
        {
            mapCount[s] = mapCount[s] + 1;
        }
        else
        {
            mapCount.insert(make_pair(s, 1));
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << mapCount[input[i]] << ' ';
    }

    return 0;
}
