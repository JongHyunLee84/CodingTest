#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, ar[8][8], temp[8][8], ret = INF;
vector<pair<int,int>> v;
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, 1, -1};

void print() {
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << temp[i][j] << ' ';
        }
        cout << '\n';
    }
}
void rotate_camera(pair<int,int> p, int dir){

    int ny = p.first, nx = p.second;
    temp[ny][nx] = 7;
    if(ar[p.first][p.second] == 1){
        while(true){
            ny += dy[dir];
            nx += dx[dir];
            if(ar[ny][nx] == 6 || ny < 0 || nx < 0 || ny >=n || nx >=m)break;
            temp[ny][nx] = 7;
        }
    }else if(ar[p.first][p.second] == 2){
        while(true){
            ny += dy[dir];
            nx += dx[dir];
            if(ar[ny][nx] == 6 || ny < 0 || nx < 0 || ny >=n || nx >=m)break;
            temp[ny][nx] = 7;
        }
        if(dir == 0)dir = 1;
        else if(dir == 1)dir = 0;
        else if(dir == 2)dir = 3;
        else if(dir == 3)dir ==2;
        ny = p.first, nx = p.second;
        while(true){
            ny += dy[dir];
            nx += dx[dir];
            if(ar[ny][nx] == 6 || ny < 0 || nx < 0 || ny >=n || nx >=m)break;
            temp[ny][nx] = 7;
        }
    }
    else if(ar[p.first][p.second] == 3){
        while(true){
            ny += dy[dir];
            nx += dx[dir];
            if(ar[ny][nx] == 6 || ny < 0 || nx < 0 || ny >=n || nx >=m)break;
            temp[ny][nx] = 7;
        }
        if(dir == 2)dir = 0;
        else if(dir == 0) dir =3;
        else if(dir == 3) dir = 1;
        else dir = 2;
        ny = p.first, nx = p.second;
        while(true){
            ny += dy[dir];
            nx += dx[dir];
            if(ar[ny][nx] == 6 || ny < 0 || nx < 0 || ny >=n || nx >=m)break;
            temp[ny][nx] = 7;
        }
    }
    else if(ar[p.first][p.second] == 4){
        while(true){
            ny += dy[dir];
            nx += dx[dir];
            if(ar[ny][nx] == 6 || ny < 0 || nx < 0 || ny >=n || nx >=m)break;
            temp[ny][nx] = 7;
        }
        if(dir == 2)dir = 0;
        else if(dir == 0) dir =3;
        else if(dir == 3) dir = 1;
        else if(dir == 1)dir = 2;
        ny = p.first, nx = p.second;
        while(true){
            ny += dy[dir];
            nx += dx[dir];
            if(ar[ny][nx] == 6 || ny < 0 || nx < 0 || ny >=n || nx >=m)break;
            temp[ny][nx] = 7;
        }
        if(dir == 2)dir = 0;
        else if(dir == 0) dir =3;
        else if(dir == 3) dir = 1;
        else if(dir == 1)dir = 2;
        ny = p.first, nx = p.second;
        while(true){
            ny += dy[dir];
            nx += dx[dir];
            if(ar[ny][nx] == 6 || ny < 0 || nx < 0 || ny >=n || nx >=m)break;
            temp[ny][nx] = 7;
        }
    }
    else { 
        for(int k=0; k<4; k++){
                    int ny = p.first, nx = p.second;
                    while(true){
                        ny += dy[k];
                        nx += dx[k];
                        if(ar[ny][nx] == 6 || ny < 0 || nx < 0 || ny >=n || nx >=m)break;
                        temp[ny][nx] = 7;
                    }
                }
    }
}

void go(int idx) {
    if(v.size() ==0){
        int sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(ar[i][j] == 0)sum++;
            }
        }
        ret = min(ret, sum);
        return;
    }
    if(idx == v.size()){
        int sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(temp[i][j] == 0)sum++;
            }
        }
        ret = min(ret, sum);
        // cout << '\n';
        // print();
        
        return;
    }
    int tt[8][8];
    memcpy(tt, temp, sizeof(temp));
    for(int i=0; i<4; i++){
        rotate_camera(v[idx],i);
        go(idx+1);
        memcpy(temp, tt, sizeof(tt));
    }
}


int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ar[i][j];
            if(ar[i][j] >= 1 && ar[i][j] <= 5){
                v.push_back({i,j});
            } else if(ar[i][j] == 6)temp[i][j] =6;
        }
    }
    go(0);
    cout << ret << '\n';

    return 0;
}