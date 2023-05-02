#include <bits/stdc++.h>
using namespace std;

int n, m, temp, result = 99999999;
vector<pair<int, int>> chicken, home;
vector<vector<int>> chicken_combi;
vector<int> test;
void combi(int a, vector<int> v)
{
    if (v.size() == m)
    {
        chicken_combi.push_back(v);
        return;
    }
    for (int i = a + 1; i < chicken.size(); i++)
    {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            test.push_back(temp);
            if (temp == 1)
            {
                home.push_back({i, j});
            }
            else if (temp == 2)
            {
                
                chicken.push_back({i, j});
            }
        }
    }
    // for(int i : test) cout << i << ' ';
    // for (auto i : chicken)
    //     cout << i.first << i.second << '\n';
    vector<int> v;
    combi(-1, v);

    for (auto clist : chicken_combi)
    {
        int ret = 0;
        for (auto h : home)
        {
            int max_min = 987654321;
            for (int c : clist)
            {
                int lo = abs(h.first - chicken[c].first) + abs(h.second - chicken[c].second);
                max_min = min(lo, max_min);
            }
            ret += max_min;
        }
        result = min(ret, result);
    }

    cout << result << '\n';
    return 0;
}