#include <bits/stdc++.h>
using namespace std;

int n, m, k, visited[30][30], dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1}, ret;
char ar[30][30];

void dfs(int y, int x, int cnt) {
    // cout << y << '.' << x << '\n';
    if(y==1 && x==m) {
        // cout << cnt << '\n';
        if(cnt == k)ret++;
        return;
    }
    for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 1 || nx < 1 || ny > n || nx > m || visited[ny][nx])continue;
            visited[ny][nx] = 1;
            dfs(ny, nx, cnt+1);
            visited[ny][nx] = 0;
    }
}

int main() {
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> ar[i][j];
            if(ar[i][j] == 'T')visited[i][j] = 1;
        }            
    }
    visited[n][1] = 1;
    dfs(n,1,1);
    cout << ret << '\n';
    return 0;
}
