#include <bits/stdc++.h>
using namespace std;

int n, m, dy[4] = {0, -1, 0, 1}, dx[4] = {-1, 0, 1, 0}, py, px, fire[1504][1504], person[1504][1504], ret, y , x;
string s;
char ar[1504][1504];
queue<pair<int,int>> q;
int main()
{
    cin >> n >> m;
    fill(&fire[0][0], &fire[0][0] + 1504 * 1504, 1e9);
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<m; j++){
            ar[i][j] = s[j];
            if(s[j] == 'J'){
                py = i;
                px = j;
                person[i][j] = 1;
            } else if(s[j] == 'F'){
                q.push({i,j});
                fire[i][j] = 1;
            }
        }
    }
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
            if(ar[ny][nx] == '#' || fire[ny][nx] != 1e9)continue;
            fire[ny][nx] = fire[y][x] + 1;
            q.push({ny,nx});
        }
    }
    //     for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << fire[i][j] << ' ' ;
    //     }
    //     cout << '\n';
    // }
    // cout << '-' << '\n';
    q.push({py, px});
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        if(y == 0 || x == 0 || y == n-1 || x == m-1){
            ret = person[y][x];
            break;
        }
        for(int i=0; i<4; i++){
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
            if(ar[ny][nx] == '#' || person[ny][nx])continue;
            if(fire[ny][nx] <= person[y][x] + 1)continue;
            person[ny][nx] = person[y][x] + 1;
            q.push({ny,nx});
        }
    }
    //     for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << person[i][j] << ' ' ;
    //     }
    //     cout << '\n';
    // }
    if(ret)cout << ret << '\n';
    else cout << "IMPOSSIBLE" << '\n';
    return 0;
}
