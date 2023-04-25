#include <bits/stdc++.h>
using namespace std;

string s, ret, last;
int cnt;
map<char, int> mp;
int main()
{
    cin >> s;
    for (char i : s)
        if (mp.find(i) == mp.end())
        {
            mp[i] = 1;
        }
        else
        {
            mp[i] += 1;
        }
    for (auto i : mp)
        if (i.second % 2 != 0)
        {
            cnt++;
        }
    if (cnt > 1)
    {
        cout << "I'm Sorry Hansoo" << '\n';
    }
    else
    {
        for (auto i : mp)
        {
            if (i.second % 2 == 0)
            {
                for (int j = 0; j < i.second; j++)
                {
                    ret.insert(ret.size() / 2, string(1, i.first));
                }
            }
            else
            {
                for (int j = 0; j < i.second - 1; j++)
                {
                    ret.insert(ret.size() / 2, string(1, i.first));
                }
                last = string(1, i.first);
            }
        }
        ret.insert(ret.size() / 2, last);
        cout << ret << '\n';
    }

    return 0;
}