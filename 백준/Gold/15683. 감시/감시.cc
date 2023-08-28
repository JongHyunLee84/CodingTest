#include <bits/stdc++.h>
using namespace std;

int n, m, ar[10][10], visited[10][10], ret = 1e9;
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1}; 
struct Camera {
    int num, y, x;
};
vector<Camera> v;

bool isBreak(int y, int x){
    if(y < 0 || x < 0 || y >= n || x >= m)return true;
    if(visited[y][x] == 6)return true;
    return false;
}

vector<pair<int,int>> spread(int here, int dir){
vector<pair<int, int>> _change; 
    int y = v[here].y; 
    int x = v[here].x; 
    if(visited[y][x] == 1){
        while(true){
            int ny = y + dy[dir]; 
            int nx = x + dx[dir]; 
            if(ny >= 0 && ny < n && nx >= 0 && nx < m && visited[ny][nx] != 6){
                if(visited[ny][nx] == 0){
                    visited[ny][nx] = 8; 
                    _change.push_back({ny, nx});
                }
                y = ny; 
                x = nx; 
            }else break;
        }
    }else if(visited[y][x] == 2){
        for(int i = 0; i <= 2; i +=2){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4]; 
                if(ny >= 0 && ny < n && nx >= 0 && nx < m && visited[ny][nx] != 6){
                    if(visited[ny][nx] == 0){visited[ny][nx] = 8;_change.push_back({ny, nx});}
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }else if(visited[y][x] == 3){
        for(int i = 0; i < 2; i++){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if(ny >= 0 && ny < n && nx >= 0 && nx < m && visited[ny][nx] != 6){
                    if(visited[ny][nx] == 0){visited[ny][nx] = 8;_change.push_back({ny, nx});}
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }else if(visited[y][x] == 4){
        for(int i = 0; i < 3; i++){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if(ny >= 0 && ny < n && nx >= 0 && nx < m && visited[ny][nx] != 6){
                    if(visited[ny][nx] == 0){visited[ny][nx] = 8;_change.push_back({ny, nx});}
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }else if(visited[y][x] == 5){
        for(int i = 0; i < 4; i++){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4]; 
                if(ny >= 0 && ny < n && nx >= 0 && nx < m && visited[ny][nx] != 6){
                    if(visited[ny][nx] == 0){visited[ny][nx] = 8;_change.push_back({ny, nx});}
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }
    return _change; 
}


void check() {
    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j])sum++;
        }
    }
    ret = min(ret, sum);
}

void go(int idx){

    if(idx == v.size()){
        check(); return;
    }
    

    for(int i=0; i<4; i++){
        auto temp = spread(idx, i);
        go(idx+1);
        for(auto j : temp)visited[j.first][j.second] = 0;
    }
    
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> visited[i][j];
            if(visited[i][j] >= 1 && visited[i][j] <= 5){
                Camera temp; temp.num = visited[i][j]; temp.y = i; temp.x = j;
                v.push_back(temp);
            }
        }
    }
    go(0);
    cout << ret << '\n';
    return 0;
}
