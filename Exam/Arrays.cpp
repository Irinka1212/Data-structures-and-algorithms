#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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


int main()
{
    int n;
    int m;
    cin >> n >> m;

    int* x = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }

    vector<int> y;
    int number;
    for (int i = 0; i < m; ++i)
    {
        cin >> number;
        y.push_back(number);
    }

    mergesort(x, 0, n - 1);

    vector<int> result;
    for (int i = 0; i < n; ++i)
    {
        result.push_back(x[i]);
    }

    int count = 0;
    for (int i = 0; i < m; ++i)
    {
        auto low = lower_bound(result.begin(), result.end(), y[i]);
        count = low - result.begin();
        cout << count << ' ';
    }

    delete[] x;

    return 0;
}
