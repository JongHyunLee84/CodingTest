#include <bits/stdc++.h>
using namespace std;

int n, m, dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1}, ret, visited[24][24];
char ar[24][24];
string s;
int ar2[24][24];

void go(int y, int x, int now, int cnt){
    // cout << now << '\n';
    ret = max(ret, cnt);
    if(ret == 26)return;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
        if(now & (1<<ar[ny][nx] - 'A'))continue;
        if(visited[ny][nx])continue;
        visited[ny][nx] = 1;
        go(ny, nx, now | (1 << ar[ny][nx] - 'A'), cnt+1);
        visited[ny][nx] = 0;
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<m; j++){
            ar[i][j] = s[j];
        }
    }

    visited[0][0] = 1;
    int temp = (1<<ar[0][0]-'A');

    go(0,0, temp, 1);
    cout << ret << '\n';
    return 0;
}
