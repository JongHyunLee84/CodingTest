#include <bits/stdc++.h>
using namespace std;

int n, m, ar[54][54], visited[54][54], dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1}, ret;
char temp;
queue<pair<int,int>> q;
int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> temp;
            ar[i][j] = temp == 'W' ? 0 : 1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ar[i][j]){
                memset(visited, 0, sizeof(visited));
                q.push({i,j});
                visited[i][j] = 1;
                while(q.size()){
                    auto now = q.front(); q.pop();
                    for(int i=0; i<4; i++){
                        int ny = now.first + dy[i];
                        int nx = now.second + dx[i];
                        if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
                        if(visited[ny][nx] || !ar[ny][nx])continue;
                        visited[ny][nx] = visited[now.first][now.second] + 1;
                        ret = max(ret, visited[ny][nx]);
                        q.push({ny, nx});
                    }
                }
            }
        }
    }
    cout << ret-1 << '\n';
    return 0;
}
