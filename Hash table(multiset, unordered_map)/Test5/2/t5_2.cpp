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

    map<int, int> mapCount;

    vector<int> input;
    int num;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        input.push_back(num);

        if (mapCount.find(num) != mapCount.end())
        {
            mapCount[num] = mapCount[num] + 1;
        }
        else
        {
            mapCount.insert(make_pair(num, 1));
        }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int num = input[i];
        if (mapCount[num] % 2 == 1)
            sum += num;
    }
    cout << sum << '\n';

    return 0;
}
