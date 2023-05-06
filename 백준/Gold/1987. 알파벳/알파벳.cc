#include <bits/stdc++.h>
using namespace std;

int n, m, visited[24][24], ret = -30, dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
char ar[24][24];
string s;

void dfs(int y, int x) {
    // if(ret == 26)return;
    visited[y][x] = 1;
    s += ar[y][x];
    // cout << s << '\n';
    for(int i=0; i<4; i++){
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
        if(visited[ny][nx] || s.find(ar[ny][nx]) != string::npos)continue;
        dfs(ny,nx);
        visited[ny][nx] = 0;
        s.erase(s.size()-1, 1);
    }
    int size_ = s.size();
    if(ret < size_){
        ret = s.size();
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
    dfs(0,0);
    cout << ret << '\n';
    return 0;
}
