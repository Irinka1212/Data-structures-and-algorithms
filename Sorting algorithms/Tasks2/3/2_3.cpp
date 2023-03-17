#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Efficiency
{
    double diam;
    double time;
    int index;

    double calculate()
    {
        return (diam * diam) / time;
    }
};
void merge(Efficiency* arr, int start, int middle, int end)
{
    Efficiency* arr1 = new Efficiency[middle - start + 1];
    Efficiency* arr2 = new Efficiency[end - middle];
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
            if (arr1[i].calculate() > arr2[j].calculate())
            {
                arr[k] = arr1[i];
                ++i;
            }
            else if (arr1[i].calculate() < arr2[j].calculate())
            {
                arr[k] = arr2[j];
                ++j;
            }
            else
            {
                if (arr1[i].diam > arr2[j].diam)
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


void mergesort(Efficiency* arr, int l, int r)
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

    Efficiency* boys = new Efficiency[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> boys[i].diam >> boys[i].time;
        boys[i].index = i + 1;
    }

    mergesort(boys, 0, n - 1);
    for (int i = 0; i < n; ++i)
    {
        cout << boys[i].index << " ";
    }

    delete[] boys;

    return 0;
}