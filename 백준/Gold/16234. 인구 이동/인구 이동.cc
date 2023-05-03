#include <bits/stdc++.h>
using namespace std;

int n, l, r, ar[54][54], visited[54][54], cnt, dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1}, psum;
bool check;
vector<pair<int,int>> v;
void dfs(int y, int x) {
    if(visited[y][x])return;
    visited[y][x] = 1;
    v.push_back({y,x});
    psum += ar[y][x];
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
        // cout << abs(ar[y][x]-ar[ny][nx]) << '\n';
        if(abs(ar[y][x]-ar[ny][nx]) < l || abs(ar[y][x]-ar[ny][nx]) > r) continue;
        dfs(ny,nx);
    }
}


int main() {
    cin >> n >> l >> r;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> ar[i][j];
        }
    }
    while(!check){
        check = true;
        for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dfs(i,j);
            // cout << v.size() << "end\n";
            if(v.size() > 1){
                check = false;
                for(auto k : v){
                    ar[k.first][k.second] = psum / v.size();
                }
            }
            v.clear();
            psum = 0;
        }
    }
    memset(visited, 0, sizeof(visited));
    if(!check){
        cnt ++;
    }
    }
    cout << cnt << '\n';
    return 0;
}
