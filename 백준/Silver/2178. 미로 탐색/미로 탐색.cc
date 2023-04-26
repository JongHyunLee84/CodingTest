#include <bits/stdc++.h>
using namespace std;
const int max_n = 104;
int n, m, a[max_n][max_n], visited[max_n][max_n], dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q;
void bfs(int y, int x)
{
    visited[y][x] = 1;
    q.push({y, x});
    while (q.size())
    {
        auto now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (visited[ny][nx])
                continue;
            if (!a[ny][nx])
                continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[now.first][now.second] + 1;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }
    bfs(0, 0);
    cout << visited[n - 1][m - 1] << '\n';
    return 0;
}