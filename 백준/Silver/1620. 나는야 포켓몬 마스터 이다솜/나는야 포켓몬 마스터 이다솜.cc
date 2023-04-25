#include <bits/stdc++.h>
using namespace std;

int n, m;
string s, name[100004];
map<string, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        name[i] = s;
        mp[s] = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (atoi(s.c_str()) != 0)
        {
            cout << name[atoi(s.c_str())] << '\n';
        }
        else
        {
            cout << mp[s] << '\n';
        }
    }
}