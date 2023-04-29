#include <bits/stdc++.h>
using namespace std;

int n, m, t, ret, ar[104][104], visited[104][104], dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void dfs(int y, int x)
{
    if(ar[y][x] == 1){
        ar[y][x] = 0;
        visited[y][x] = 1;
        return;
    }
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny<0 || nx<0 || ny >=n || nx>=m || visited[ny][nx])continue;
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
            cin >> ar[i][j];
        }
    }
    while(true)
    {
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (ar[i][j] == 1)
                    cnt++;
            }
        }

        if (cnt == 0)
            break;
        else
        {
            dfs(0,0);
            t++;
        }
        ret = cnt;
    }
    cout << t << '\n';
    cout << ret << '\n';
    return 0;
}