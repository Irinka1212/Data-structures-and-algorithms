#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

static const int SIZE = 1000001;
vector<int> _internal_tree[SIZE];

class IntegerTree
{
public:
    void addChild(int parent, int child)
    {
        _internal_tree[parent].push_back(child);
    }

    int countChildren(int parent)
    {
        int count = 0;
        for (auto begin = _internal_tree[parent].begin(); begin != _internal_tree[parent].end(); ++begin)
        {
            count += countChildren(*begin) + 1;
        }

        return count;
    }
};

int main()
{
    IntegerTree tree;

    int n;
    cin >> n;

    int index;
    int num;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> index >> num;
        tree.addChild(index, num);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << tree.countChildren(i) << ' ';
    }

    return 0;
}
