#include <bits/stdc++.h>
using namespace std;

int n, cnt, ret, ar[104][104], visited[104][104], dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int h)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n)
            continue;
        if (visited[ny][nx])
            continue;
        if (ar[ny][nx] <= h)
            continue;
        dfs(ny, nx, h);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ar[i][j];
        }
    }
    for (int h = 0; h <= 100; h++)
    {
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ar[i][j] > h && !visited[i][j])
                {
                    dfs(i, j, h);
                    cnt++;
                }
            }
        }
        if (cnt >= ret)
            ret = cnt;
    }

    cout << ret << '\n';
    return 0;
}