#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v;
    int num = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        v.push_back(num);
    }

    stack<int> positive;
    queue<int> negative;
    queue<int> result;

    int previous = v[0];
    if (previous < 0)
        negative.push(previous);
    else
        positive.push(previous);

    int current = 0;
    int size = v.size();
    for (int i = 1; i < size; ++i)
    {
        current = v[i];
        if (current > 0 && previous < 0)
        {

            while (!negative.empty() && !positive.empty())
            {
                int pos = positive.top();
                int neg = negative.front() * -1;

                if (pos > neg || pos == neg)
                    negative.pop();

                if (pos < neg || pos == neg)
                    positive.pop();
            }

            while (!negative.empty())
            {
                result.push(negative.front());
                negative.pop();
            }
        }

        if (current < 0)
            negative.push(current);
        else
            positive.push(current);

        previous = current;
    }

    while (!negative.empty() && !positive.empty())
    {
        int pos = positive.top();
        int neg = negative.front() * -1;

        if (pos > neg || pos == neg)
            negative.pop();

        if (pos < neg || pos == neg)
            positive.pop();
    }

    while (!negative.empty())
    {
        result.push(negative.front());
        negative.pop();
    }

    stack<int> reversePositive;
    while (!positive.empty())
    {
        reversePositive.push(positive.top());
        positive.pop();
    }

    while (!reversePositive.empty())
    {
        result.push(reversePositive.top());
        reversePositive.pop();
    }

    if (result.empty())
        cout << '\n';

    while (!result.empty())
    {
        cout << result.front() << ' ';
        result.pop();
    }

    return 0;
}