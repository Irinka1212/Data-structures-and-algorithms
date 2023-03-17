#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int d;
    cin >> n >> d;

    vector<int> v;

    int num = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        v.push_back(num);
    }

    auto beginIter = v.begin();
    auto endIter = v.begin() + d;

    long long sum = 0;
    int min = *min_element(beginIter, endIter);
    sum += min;

    int lastMin = min;
    for (int i = d; i < n; ++i)
    {
        int toBeRemoved = *beginIter;
        int toBeAdded = v[i];

        ++beginIter;
        ++endIter;

        if (lastMin != toBeRemoved)
        {
            if (lastMin > toBeAdded)
                min = toBeAdded;
        }
        else
            min = (lastMin >= toBeAdded) ? toBeAdded : *min_element(beginIter, endIter);

        sum += min;
        lastMin = min;
    }

    cout << sum;

    return 0;
}