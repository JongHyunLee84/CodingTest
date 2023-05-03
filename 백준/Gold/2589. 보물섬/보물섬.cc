#include <bits/stdc++.h>
using namespace std;

// void bfs(int here){
//     queue<int> q; 
//     visited[here] = 1; 
//     q.push(here);
//     while(q.size()){
//         int here = q.front(); q.pop();
//         for(int there : adj[here]){
//             if(visited[there]) continue;
//             visited[there] = visited[here] + 1;
//             q.push(there);
//         }
//     }
// }
// [출처] [알고리즘 강의] 2주차. 그래프이론, 인접행렬, 인접리스트, DFS, BFS, 트리순회|작성자 큰돌


int n, m, ar[54][54], visited[54][54], dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1}, max_visit = -1, ret = -1, cnt;
char temp;
vector<pair<int, int>> land;

void bfs(int y, int x) {
    queue<pair<int,int>> q;
    visited[y][x] = 1;
    q.push({y,x});
    while(q.size()) {
        pair<int,int> here = {q.front().first, q.front().second}; q.pop();
        for(int i=0; i<4; i++){
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || !ar[ny][nx])continue;
            q.push({ny,nx});
            visited[ny][nx] = visited[here.first][here.second] + 1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            max_visit = max(max_visit, visited[i][j]);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            if (temp == 'L')
            {
                land.push_back({i, j});
                ar[i][j] = 1;
            }
            else
            {
                ar[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ar[i][j] == 1)
            {
                    max_visit = -1;
                    fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
                    // cnt = 0;
                    bfs(i, j);
                    // if(min_visit == 9999999){
                    //     continue;
                    //     // cout << i << '.' << j << ' ' << k.first << "." << k.second << '\n';
                    // }
                    // cout << min_visit << '\n';
                    ret = max(max_visit, ret);
            }
        }
    }
    cout << ret-1 << '\n';
    return 0;
}
// void bfs(int y, int x, int py, int px)
// {
//     if (y == py && x == px)
//     {
//         min_visit = min(cnt, min_visit);
//         // cout << "min_visit" <<min_visit << " cnt : " << cnt << '\n';
//         return;
//     }
//     for (int i = 0; i < 4; i++)
//     {
//         int ny = y + dy[i];
//         int nx = x + dx[i];
//         if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || !ar[ny][nx])
//             continue;
//         cnt++;
//         visited[ny][nx] = 1;
//         bfs(ny, nx, py, px);
//         visited[ny][nx] = 0;
//         cnt--;
//     }
// }

// 5 7
// WLLWWWL
// LLLWLLL
// LWLWLWW
// LWLWLLL
// WLLWLWW