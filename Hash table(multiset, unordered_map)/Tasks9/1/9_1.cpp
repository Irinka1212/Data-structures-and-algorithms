#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int CountBrokenDoors(const vector<long long>& keys, const vector<long long>& doors)
{
    int countBrokenDoors = 0;
    unordered_multiset<long long> ownedKeys;
    int size = keys.size();
    for (int i = 0; i < size; ++i)
    {
        long long key = keys[i];
        long long door = doors[i];

        ownedKeys.insert(key);

        auto it = ownedKeys.find(door);
        if (it != ownedKeys.end())
            ownedKeys.erase(it);
        else
            ++countBrokenDoors;
    }

    return countBrokenDoors;
}

int main()
{
    int n;
    cin >> n;

    vector<long long> keys;
    long long k = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        keys.push_back(k);
    }

    vector<long long> doors;
    long long d = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> d;
        doors.push_back(d);
    }

    cout << CountBrokenDoors(keys, doors);

    return 0;
}