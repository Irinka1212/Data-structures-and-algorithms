#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


class Date
{
public:
    int index;
    string timestamp;
    int year = -1;
    int month = -1;
    int days = -1;
    int seconds = -1;
    int minutes = -1;
    int hours = -1;

    bool isNumber(char symbol)
    {
        return symbol >= '0' && symbol <= '9';
    }

    void parse()
    {
        int num = 0;
        for (int i = 0; i < 19; ++i)
        {
            if (isNumber(timestamp[i]))
            {
                num *= 10;
                num += timestamp[i] - '0';
            }
            else
            {
                if (hours == -1)
                    hours = num;
                else if (minutes == -1)
                    minutes = num;
                else if (seconds == -1)
                    seconds = num;
                else if (days == -1)
                    days = num;
                else if (month == -1)
                    month = num;
                else if (year == -1)
                    year = num;

                num = 0;
            }
        }
        if (year == -1)
            year = num;
    }

    int compare(const Date& other)
    {
        if (year > other.year)
            return -1;
        if (year < other.year)
            return 1;
        if (month > other.month)
            return -1;
        if (month < other.month)
            return 1;
        if (days > other.days)
            return -1;
        if (days < other.days)
            return 1;
        if (hours > other.hours)
            return -1;
        if (hours < other.hours)
            return 1;
        if (minutes > other.minutes)
            return -1;
        if (minutes < other.minutes)
            return 1;
        if (seconds > other.seconds)
            return -1;
        if (seconds < other.seconds)
            return 1;
        return 0;
    }
};
void merge(Date* arr, int start, int middle, int end)
{
    Date* arr1 = new Date[middle - start + 1];
    Date* arr2 = new Date[end - middle];
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
            int res = arr1[i].compare(arr2[j]);
            if (res != -1)
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


void mergesort(Date* arr, int l, int r)
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

    cin.ignore();

    Date* timestamps = new Date[n];
    for (int i = 0; i < n; ++i)
    {
        getline(cin, timestamps[i].timestamp);
        timestamps[i].parse();
        timestamps[i].index = i + 1;
    }

    mergesort(timestamps, 0, n - 1);

    for (int i = 0; i < n; ++i)
    {
        cout << timestamps[i].index << '\n';
    }

    delete[] timestamps;
    return 0;
}
