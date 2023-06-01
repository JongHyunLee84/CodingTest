#include <bits/stdc++.h>
using namespace std;

const int MAX_RET = 5000;
int n, m, ar[54][54], dp[54][54], visited[54][54], ret, dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
char temp;

int go(int y, int x) {
    if(y < 0 || x < 0 || y >= n || x >= m || ar[y][x] == -1) return 0;
    if(visited[y][x]){
        cout << -1 << '\n';
        exit(0);
    }
    int &ret = dp[y][x];
    if(ret > 0)return ret;
    
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i]*ar[y][x];
        int nx = x + dx[i]*ar[y][x];
        ret = max(ret, go(ny,nx)+1);
    }
    visited[y][x] = 0;
    return ret;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> temp;
            if(temp == 'H')ar[i][j] = -1;
            else ar[i][j] = temp - '0';
        }
    }
    cout << go(0,0) << '\n';

    return 0;
    
}