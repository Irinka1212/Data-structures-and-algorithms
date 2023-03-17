#include<bits/stdc++.h> 

using namespace std;

void findUnique(set<string>& s, string str, size_t position)
{
    if (position > str.size())
        return;

    s.insert(str);

    findUnique(s, str, position + 1);

    if (str[position] == '1')
    {
        str[position] = '0';
        findUnique(s, str, ++position);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> masks;
    int num;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        masks.push_back(num);
    }

    set<string> s;
    string str;
    for (int i = 0; i < n; ++i)
    {
        str = bitset<20>(masks[i]).to_string();
        findUnique(s, str, 0);
    }


    cout << s.size() << '\n';

    return 0;
}
