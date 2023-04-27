#include <bits/stdc++.h>
using namespace std;
int n, m, j, l, cnt;
vector<int> a, b;
int main()
{
    cin >> n >> m >> j;
    for (int i = 1; i <= n; i++)
    {
        a.push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        b.push_back(i);
    }
    for (int i = 0; i < j; i++)
    {
        cin >> l;
        auto fi = find(b.begin(), b.end(), l);
        if (fi != b.end())
        {
            continue;
        }

        if (l < b[0])
        {
            while (find(b.begin(), b.end(), l) == b.end())
            {
                cnt++;
                for (int i = 0; i < b.size(); i++)
                {
                    b[i] = b[i] - 1;
                }
            }
        }
        else
        {
            while (find(b.begin(), b.end(), l) == b.end())
            {
                cnt++;
                for (int i = 0; i < b.size(); i++)
                {
                    b[i] = b[i] + 1;
                }
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}