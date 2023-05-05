#include <bits/stdc++.h>
using namespace std;

int n, m, jy, jx, by, bx, visited[304][304], dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1}, ret, cnt, find_;
char ar[304][304];

void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
        if(visited[ny][nx])continue;
        if(ar[ny][nx] == '0' && !visited[ny][nx])dfs(ny,nx);
        else if(ar[ny][nx] == '1'){
            ar[ny][nx] = '0';
            visited[ny][nx] = 1;
        }
        else if(ar[ny][nx] == '#') {
            find_ = 1;
            break;
        }
    }
}

int main() {
    cin >> n >> m ;
    cin >> jy >> jx >> by >> bx;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ar[i][j];
        }
    }
    if(jy == by && jx == bx){
        cout << 0 << '\n';
        return 0;
    }
    
    // while(!ret)
    while(!ret){
        memset(visited, 0, sizeof(visited));
        dfs(jy-1,jx-1);
    //     cout << "end" << '\n';
    //     for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << ar[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
        cnt++;
        if(find_){
            ret = cnt;
            break;
        }
    }
    cout << ret << '\n';
    return 0;
}

    //     for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << ar[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }