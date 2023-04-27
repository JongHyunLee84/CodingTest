#include <bits/stdc++.h>
using namespace std;

int n, m, k, cnt, ret, ar[104][104], visited[104][104], dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
pair<int, int> p1, p2;
vector<int> v;
void dfs(int y, int x)
{
    ret++;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if (visited[ny][nx] || ar[ny][nx])
            continue;
        dfs(ny, nx);
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> p1.first >> p1.second;
        cin >> p2.first >> p2.second;
        for (int j = p1.second; j < p2.second; j++)
        {
            for (int z = p1.first; z < p2.first; z++)
            {
                ar[j][z] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!ar[i][j] && !visited[i][j])
            {
                dfs(i, j);
                cnt++;
                v.push_back(ret);
                ret = 0;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << cnt << '\n';
    for (int i : v)
        cout << i << ' ';
    return 0;
}