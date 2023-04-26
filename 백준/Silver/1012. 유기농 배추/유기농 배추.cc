#include <bits/stdc++.h>
using namespace std;

int t, m, n, k, lx, ly, a[54][54], visited[54][54], cnt;
;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if (visited[ny][nx])
            continue;
        if (!a[ny][nx])
            continue;
        dfs(ny, nx);
    }
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> m >> n >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> lx >> ly;
            a[ly][lx] = 1;
        }
        for (int b = 0; b < n; b++)
        {
            for (int z = 0; z < m; z++)
            {
                if (a[b][z] && !visited[b][z])
                {
                    dfs(b, z);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
        cnt = 0;
        for (int c = 0; c < 54; c++)
        {
            for (int d = 0; d < 54; d++)
            {
                a[c][d] = 0;
                visited[c][d] = 0;
            }
        }
    }
    return 0;
}