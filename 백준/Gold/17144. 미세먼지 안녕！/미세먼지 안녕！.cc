#include <bits/stdc++.h>
using namespace std;

int n, m, t, ar[54][54], temp[54][54], ret;
int dy1[] = {0, -1, 0, 1}, dx1[] = {1, 0, -1, 0};
int dy2[] = {0, 1, 0, -1}, dx2[] = {1, 0, -1, 0};
vector<pair<int,int>> v1, v2; 

void mise() {
    memset(temp, 0, sizeof(temp));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ar[i][j]>0){
                for(int k=0; k<4; k++){
                    int ny = i + dy1[k];
                    int nx = j + dx1[k];
                    if(ny < 0 || nx < 0 || ny >= n || nx >= m || ar[ny][nx] == -1)continue;
                    temp[ny][nx] += ar[i][j] / 5;
                    temp[i][j] -= ar[i][j] / 5;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ar[i][j] += temp[i][j];
        }
    }
}

vector<pair<int,int>> rotate(int sy, int sx, int dy[], int dx[]){
    vector<pair<int,int>> v;
    int cnt = 0;
    int y = sy;
    int x = sx;
    while(true){
        int ny = y + dy[cnt];
        int nx = x + dx[cnt];
        if(ny == sy && nx == sx)break;
        if(ny < 0 || nx < 0 || ny >= n || nx >= m){
            cnt ++;
            ny = y + dy[cnt];
            nx = x + dx[cnt];
        }
        if(ny == sy && nx == sx)break;
        v.push_back({ny,nx});
        y = ny; x = nx;
    }
    return v;
}

void go(vector<pair<int,int>> v){
    for(int i = v.size()-1; i>0; i--){
        ar[v[i].first][v[i].second] = ar[v[i-1].first][v[i-1].second];
    }
    ar[v[0].first][v[0].second] = 0;
}

int main() {
    cin >> n >> m >> t;
    bool flag = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ar[i][j];
            if(ar[i][j] == -1){
                if(flag){
                    v1 = rotate(i,j, dy1, dx2);
                    flag = false;
                }else {
                    v2 = rotate(i,j,dy2,dx2);
                }
            }
        }
    }
    while(t--) {
        mise();
        go(v1);
        go(v2);
        // cout << "start" << '\n';
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout << ar[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ret += ar[i][j];
        }
    }
    cout << ret+2 << '\n';
    return 0;
}