#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int ar[14][14], visited[14][14], n, ret = INF, dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

int check() {
    int temp = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(visited[i][j])temp += ar[i][j];
        }
    }
    return temp;
}

void go(int start, int cnt){
    if(!ret) return;
    if(cnt == 3){
    //     cout << '\n';
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
        ret = min(ret, check());
        return;
    }
    for(int i=start; i<=n-1; i++){
        for(int j=2; j<=n-1; j++){
            if(visited[i][j] || visited[i-1][j] || visited[i+1][j] || visited[i][j-1] || visited[i][j+1])continue;
            visited[i][j] = 1;
            visited[i+1][j] = 1;
            visited[i-1][j] = 1;
            visited[i][j-1] = 1;
            visited[i][j+1] = 1;
            go(i, cnt+1);
            visited[i][j] = 0;
            visited[i+1][j] = 0;
            visited[i-1][j] = 0;
            visited[i][j-1] = 0;
            visited[i][j+1] = 0;            
        }
    }
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> ar[i][j];
        }
    }
    go(2,0);
    cout << ret << '\n';
    return 0;
}