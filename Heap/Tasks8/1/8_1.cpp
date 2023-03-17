#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> minHeap;
    vector<int> maxHeap;
    vector<double> medians;

    int first_num;
    cin >> first_num;
    medians.push_back(first_num);

    int second_num;
    cin >> second_num;
    medians.push_back(((double)first_num + second_num) / 2);

    if (second_num > first_num)
    {
        maxHeap.push_back(first_num);
        minHeap.push_back(second_num);
    }
    else
    {
        maxHeap.push_back(second_num);
        minHeap.push_back(first_num);
    }

    make_heap(maxHeap.begin(), maxHeap.end());
    make_heap(minHeap.begin(), minHeap.end(), greater<int>());

    int num = 0;
    for (int i = 2; i < n; ++i)
    {
        cin >> num;

        if (num < maxHeap.front())
        {
            maxHeap.push_back(num);
            push_heap(maxHeap.begin(), maxHeap.end());
        }
        else
        {
            minHeap.push_back(num);
            push_heap(minHeap.begin(), minHeap.end(), greater<int>());
        }

        if (((int)maxHeap.size() - (int)minHeap.size()) > 1)
        {
            int root = maxHeap.front();

            pop_heap(maxHeap.begin(), maxHeap.end());
            maxHeap.pop_back();

            minHeap.push_back(root);
            push_heap(minHeap.begin(), minHeap.end(), greater<int>());
        }
        else if (((int)minHeap.size() - (int)maxHeap.size()) > 1)
        {
            int root = minHeap.front();

            pop_heap(minHeap.begin(), minHeap.end(), greater<int>());
            minHeap.pop_back();

            maxHeap.push_back(root);
            push_heap(maxHeap.begin(), maxHeap.end());
        }

        if (maxHeap.size() > minHeap.size())
            medians.push_back(maxHeap.front());
        else if (minHeap.size() > maxHeap.size())
            medians.push_back(minHeap.front());
        else
            medians.push_back(((double)maxHeap.front() + minHeap.front()) / 2);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << fixed << setprecision(1) << medians[i] << '\n';
    }

    return 0;
}