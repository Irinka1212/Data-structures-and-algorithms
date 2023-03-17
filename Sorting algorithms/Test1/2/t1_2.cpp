#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Team
{
    int players;
    int othersPlayers;
    int index;

    double getPoints()
    {
        return (double)(players * players) / (double)othersPlayers;
    }
};

void merge(Team* arr, int start, int middle, int end)
{
    Team* arr1 = new Team[middle - start + 1];
    Team* arr2 = new Team[end - middle];
    for (int i = 0; i < middle - start + 1; ++i)
    {
        arr1[i] = arr[start + i];
    }
    for (int i = 0; i < end - middle; ++i)
    {
        arr2[i] = arr[middle + i + 1];
    }

    int  i = 0, j = 0, k = start;
    while (i < middle - start + 1 || j < end - middle)
    {
        if (i >= middle - start + 1)
        {
            arr[k] = arr2[j];
            ++j;
        }
        else if (j >= end - middle)
        {
            arr[k] = arr1[i];
            ++i;
        }
        else
        {
            if (arr1[i].getPoints() > arr2[j].getPoints())
            {
                arr[k] = arr1[i];
                ++i;
            }
            else if (arr1[i].getPoints() < arr2[j].getPoints())
            {
                arr[k] = arr2[j];
                ++j;
            }
            else
            {
                if (arr1[i].players >= arr2[j].players)
                {
                    arr[k] = arr1[i];
                    ++i;
                }
                else
                {
                    arr[k] = arr2[j];
                    ++j;
                }

            }

        }
        ++k;
    }

    delete[] arr1;
    delete[] arr2;
}

void mergesort(Team* arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int n;
    cin >> n;

    Team* team = new Team[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> team[i].players >> team[i].othersPlayers;
        team[i].index = i + 1;
    }

    mergesort(team, 0, n - 1);

    for (int i = 0; i < n; ++i)
    {
        cout << team[i].index << " ";
    }

    delete[] team;
    return 0;
}
