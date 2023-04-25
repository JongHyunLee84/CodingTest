#include <bits/stdc++.h>
using namespace std;

int n, m;
string f, s;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        map<string, int> mp;
        int ret = 1;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> f >> s;
            mp[s] += 1;
        }
        for (auto i : mp)
            ret *= (i.second + 1);
        cout << ret - 1 << '\n';
    }
    return 0;
}