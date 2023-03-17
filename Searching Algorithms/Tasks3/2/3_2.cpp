#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

void merge(int* arr, int start, int middle, int end)
{
    int* arr1 = new int[middle - start + 1];
    int* arr2 = new int[end - middle];
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
            if (arr1[i] < arr2[j])
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
        ++k;
    }

    delete[] arr1;
    delete[] arr2;
}

void mergesort(int* arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int Closest(int first, int second, int source)
{
    int newDistance = abs(first - source);
    int closestDistance = abs(second - source);
    if ((newDistance < closestDistance) || (newDistance == closestDistance && first < second))
        return first;

    return second;
}

int FindClosest(int* arr, int n, int x)
{
    int left = 0;
    int right = n;
    int middle = 0;
    while (left < right)
    {
        middle = (left + right) / 2;
        if (x < arr[middle])
        {
            if (middle > 0 && x > arr[middle - 1])
                return Closest(arr[middle - 1], arr[middle], x);

            right = middle;
        }
        else if (x > arr[middle])
        {
            if (middle < n - 1 && x < arr[middle + 1])
                return Closest(arr[middle], arr[middle + 1], x);

            left = middle + 1;
        }
        else
            return x;
    }
    return arr[middle];
}

void Solve(int* complexity, int* knowledge, int n, int m)
{
    for (int i = 0; i < m; ++i)
    {
        cout << FindClosest(complexity, n, knowledge[i]) << '\n';
    }
}

int main()
{
    int n;
    int m;
    cin >> n >> m;

    int* complexity = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> complexity[i];
    }
    int* knowledge = new int[m];
    for (int i = 0; i < m; ++i)
    {
        cin >> knowledge[i];
    }

    mergesort(complexity, 0, n - 1);

    Solve(complexity, knowledge, n, m);

    delete[] complexity;
    delete[] knowledge;

    return 0;
}
