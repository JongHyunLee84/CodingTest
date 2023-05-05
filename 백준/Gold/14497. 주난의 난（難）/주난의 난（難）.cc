#include <bits/stdc++.h>
using namespace std;

char ar[304][304];
int n, m, y, x1, y2, x2;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1}, cnt, visited[304][304];
queue<pair<int, int>> q;

int main() {
    cin >> n >> m ;
    cin >> y >> x1 >> y2 >> x2;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ar[i][j];
        }
    }
    y--; x1--; y2--; x2--;
    q.push({y,x1});
    visited[y][x1] = 1;
    
    while(ar[y2][x2] != '0'){
        cnt++;
        queue<pair<int,int>> temp;
        
        while(q.size()){
            int ty = q.front().first;
            int tx = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int ny = ty + dy[i];
                int nx = tx + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
                if(visited[ny][nx])continue;
                visited[ny][nx] = cnt;
                if(ar[ny][nx] != '0'){
                    ar[ny][nx] = '0';
                    temp.push({ny,nx});
                }else q.push({ny,nx});
            }
        }
        q = temp;
    }
    cout << visited[y2][x2] << '\n';
    
    return 0;
}
