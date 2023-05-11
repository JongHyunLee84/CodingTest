#include <bits/stdc++.h>
using namespace std;   

int n, m, cnt,ar[54][54], visited[54][54], mx, com_size[2504], big;
int dy[4] = {0,-1,0,1}, dx[4] = {-1,0,1,0};

int dfs(int y, int x, int cnt){
    int plus = 1;
    visited[y][x] = cnt;
    for(int i=0; i<4; i++){
        if(!(ar[y][x] & (1<<i))){
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if(!visited[ny][nx]){
              plus += dfs(ny,nx,cnt);
            }
        }
    }
    return plus;
}


int main() {
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ar[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j])continue;
            cnt++;
            com_size[cnt] = dfs(i,j,cnt);
            mx = max(com_size[cnt], mx);
        }
    }
    
    // cout << "here" << '\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i + 1 < n){
                int first = visited[i][j];
                int second = visited[i+1][j];
                if(first != second){
                    big = max(big, com_size[first] + com_size[second]);
                }
            }
            if(j+1 < m){
                int first = visited[i][j];
                int second = visited[i][j+1];
                if(first != second){
                    big = max(big, com_size[first] + com_size[second]);
                }
            }
        }
    }
    // cout << "here";
    cout << cnt << '\n' << mx << '\n' << big << '\n';
    return 0;
}
