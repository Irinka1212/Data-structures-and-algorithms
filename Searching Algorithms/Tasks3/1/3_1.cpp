#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long Cub(long long num)
{
    return num * num * num;
}

int main()
{
    long long n;
    cin >> n;

    long long num = 1;
    long long presents = 0;
    while (n > 0)
    {
        if (Cub(num) > n)
        {
            --num;
            n -= Cub(num);
            ++presents;
            num = 1;
        }
        else
            ++num;
    }

    cout << presents;

    return 0;
}

