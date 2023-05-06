#include <bits/stdc++.h>
using namespace std;

int n, m, visited[30], dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1}, ret;
char ar[24][24];


void dfs(int y, int x, int cnt) {
    ret = max(cnt, ret);
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
        if(visited[(int)ar[ny][nx] - 'A'])continue;
        
        visited[(int)ar[ny][nx] - 'A'] = 1;
        dfs(ny,nx,cnt+1);
        visited[(int)ar[ny][nx] - 'A'] = 0;
    }
}
int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ar[i][j];
        }
    }
    visited[(int)ar[0][0] - 'A'] = 1; 
    dfs(0,0,1);
    cout << ret << '\n';
    return 0;
}
