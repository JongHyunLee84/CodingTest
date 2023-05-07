#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, h, visited[34][14], ret = INF;
int a, b;

bool check() {
    for(int i=1; i<=n; i++){
        int temp = i;
        for(int j=1; j<=h; j++){
            if(visited[j][temp])temp++;
            else if(visited[j][temp-1])temp--;
        }
        if(temp != i) return false;
    }
return true;    
}

void go(int start, int cnt){
    if(cnt > 3 || cnt >= ret) return;
    if(check()){
        ret = min(ret, cnt);
    }
    
    for(int i=start; i<=h; i++){
        for(int j=1; j<=n; j++){
            if(visited[i][j] || visited[i][j-1] || visited[i][j+1])continue;
            visited[i][j] = 1;
            go(i,cnt+1);
            visited[i][j] = 0;
        }
    }
}
int main() {
    cin >> n >> m >> h;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        visited[a][b] = 1;
    }
    
    go(1,0);
    if(ret == INF)cout << -1 << '\n';
    else cout << ret << '\n';
    return 0;
}
