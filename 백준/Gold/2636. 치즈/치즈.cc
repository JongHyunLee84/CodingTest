#include <bits/stdc++.h>
using namespace std;

int n, m, ar[104][104], visited[104][104], temp[104][104], dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1}, times, cheese;
pair<int,int> start = {0,0};
int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ar[i][j];
            temp[i][j] = ar[i][j];
        }
    }
    while(1){
        // cout << "here" << '\n';
        memset(visited, 0, sizeof(visited));
        queue<pair<int,int>> q;
        q.push(start);
        visited[0][0] = 1;
        int isZero = 1, temp_chese = 0;
        while(q.size()){
            auto now = q.front(); q.pop();
            for(int i=0; i<4; i++){
                int ny = dy[i] + now.first;
                int nx = dx[i] + now.second;
                if(ny >= n || nx >= m || ny < 0 || nx < 0)continue;
                if(visited[ny][nx])continue;
                if(ar[ny][nx] == 1){
                    temp[ny][nx] = 0;
                    visited[ny][nx] = 1;
                    isZero = 0;
                    temp_chese++;
                    continue;
                }
                visited[ny][nx] = 1;
                q.push({ny,nx});
            }
        }
        if(isZero)break;
        memcpy(ar, temp, sizeof(temp));
        cheese = temp_chese;
        times++;
    }
    cout << times << '\n' << cheese << '\n';
    
    return 0;
}

