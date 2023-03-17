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
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    mergesort(arr, 0, n - 1);

    int num = arr[0];
    cout << num << " ";
    for (int i = 1; i < n; ++i)
    {
        if (num != arr[i])
        {
            num = arr[i];
            cout << num << " ";
        }
    }

    delete[] arr;
    return 0;
}
