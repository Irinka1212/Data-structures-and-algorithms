#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    char koceto;
    cin >> koceto;

    int n = str.length();
    vector<int> distance;
    distance.reserve(n);

    int firstIndex = -1;;
    int secondIndex = -1;
    for (int i = 0; i < n; ++i)
    {
        if (str[i] == koceto)
        {
            if (firstIndex == -1 && secondIndex == -1)
            {
                firstIndex = i;
                for (int y = i; y >= 0; --y)
                    distance.push_back(y);
            }
            else
            {
                secondIndex = i;
                for (int y = firstIndex + 1; y <= (secondIndex + firstIndex) / 2; ++y)
                        distance.push_back(y - firstIndex);

                for (int y = ((secondIndex + firstIndex) / 2) + 1; y <= secondIndex; ++y)
                        distance.push_back(secondIndex - y);

                firstIndex = secondIndex;
            }
       }
    }

    if (secondIndex == -1)
    {
        for (int y = firstIndex + 1; y < n; ++y)
            distance.push_back(y - firstIndex);
    }
    else
    {
        for (int y = secondIndex + 1; y < n; ++y)
            distance.push_back(y - secondIndex);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << distance[i] << " ";
    }
 
    return 0;
}#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    char koceto;
    cin >> koceto;

    int n = str.length();
    vector<int> distance;
    distance.reserve(n);

    int firstIndex = -1;;
    int secondIndex = -1;
    for (int i = 0; i < n; ++i)
    {
        if (str[i] == koceto)
        {
            if (firstIndex == -1 && secondIndex == -1)
            {
                firstIndex = i;
                for (int y = i; y >= 0; --y)
                    distance.push_back(y);
            }
            else
            {
                secondIndex = i;
                for (int y = firstIndex + 1; y <= (secondIndex + firstIndex) / 2; ++y)
                    distance.push_back(y - firstIndex);

                for (int y = ((secondIndex + firstIndex) / 2) + 1; y <= secondIndex; ++y)
                    distance.push_back(secondIndex - y);

                firstIndex = secondIndex;
            }
        }
    }

    if (secondIndex == -1)
    {
        for (int y = firstIndex + 1; y < n; ++y)
            distance.push_back(y - firstIndex);
    }
    else
    {
        for (int y = secondIndex + 1; y < n; ++y)
            distance.push_back(y - secondIndex);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << distance[i] << " ";
    }

    return 0;
}