#include <bits/stdc++.h>
using namespace std;

int ret, n, m, a[10][10], temp[10][10], visited[10][10], dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
vector<vector<pair<int, int>>> vv;
vector<pair<int, int>> v;

void dfs(int y, int x)
{
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << temp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "----------------------" << '\n';
    temp[y][x] = 2;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
        {
            continue;
        }
        if (visited[ny][nx] == 1 || temp[ny][nx] != 0)
        {
            continue;
        }

        dfs(ny, nx);
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                v.push_back({i, j});
            }
        }
    }
    int s = v.size();
    for (int i = 0; i < s; i++)
    {
        for (int j = i + 1; j < s; j++)
        {
            for (int k = j + 1; k < s; k++)
            {

                int cnt = 0;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        temp[i][j] = a[i][j];
                        visited[i][j] = 0;
                    }
                }

                temp[v[i].first][v[i].second] = 1;
                temp[v[j].first][v[j].second] = 1;
                temp[v[k].first][v[k].second] = 1;

                // dfs
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (temp[i][j] == 2 && visited[i][j] == 0)
                        {
                            dfs(i, j);
                        }
                    }
                }

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (temp[i][j] == 0)
                            cnt++;
                    }
                }
                if (cnt >= ret)
                    ret = cnt;
                // cout << "끝" << '\n';
            }
        }
    }

    cout << ret << '\n';
    return 0;
}
