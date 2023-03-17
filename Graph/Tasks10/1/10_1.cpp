#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Person
{
    bool sick = false;
    bool isSickCurrentRound = false;

    void infect()
    {
        sick = true;
        isSickCurrentRound = true;
    }
};

int main()
{
    int n;
    int m;
    cin >> n >> m;

    int t;
    int k;
    cin >> t >> k;

    Person** matrix = new Person * [n];
    for (int i = 0; i < n; ++i)
        matrix[i] = new Person[m];

    int row;
    int column;
    for (int i = 0; i < k; ++i)
    {
        cin >> row >> column;
        matrix[row - 1][column - 1].sick = true;
    }

    int countSick = k;
    for (int i = 0; i < t; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int l = 0; l < m; ++l)
            {
                if (matrix[j][l].sick && !matrix[j][l].isSickCurrentRound)
                {
                    if (j > 0 && !matrix[j - 1][l].sick)
                    {
                        matrix[j - 1][l].infect();
                        ++countSick;
                    }

                    if (j < n - 1 && !matrix[j + 1][l].sick)
                    {
                        matrix[j + 1][l].infect();
                        ++countSick;
                    }

                    if (l > 0 && !matrix[j][l - 1].sick)
                    {
                        matrix[j][l - 1].infect();
                        ++countSick;
                    }

                    if (l < m - 1 && !matrix[j][l + 1].sick)
                    {
                        matrix[j][l + 1].infect();
                        ++countSick;
                    }
                }

            }
        }

        for (int j = 0; j < n; ++j)
        {
            for (int l = 0; l < m; ++l)
            {
                matrix[j][l].isSickCurrentRound = false;
            }
        }
    }

    cout << n * m - countSick << '\n';

    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}