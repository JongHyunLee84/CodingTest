#include <bits/stdc++.h>
using namespace std;

int N, K, a[14][14], y, x, dir, ret;
struct Point {
    int y, x, dir;
};
vector<int> v[14][14];
vector<Point> status;
const int dy[] = {0,0,-1,1}, dx[] = {1,-1,0,0};

void move(int y, int x, int dir, int i) {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0 || nx < 0 || ny >= N || nx >= N || a[ny][nx] == 2){
        status[i].dir ^= 1;
        ny = y + dy[status[i].dir];
        nx = x + dx[status[i].dir];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N || a[ny][nx] == 2) return;
    }
    vector<int> &here_v = v[y][x];
    vector<int> &next_v = v[ny][nx];
    auto pos = find(here_v.begin(), here_v.end(), i);
    if(a[ny][nx] == 1)reverse(pos, here_v.end());
    for(auto it = pos; it != here_v.end(); it++){
        next_v.push_back(*it);
        status[*it].y = ny;
        status[*it].x = nx;
    }
    here_v.erase(pos, here_v.end());
}

bool isOver() {
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(v[i][j].size() >= 4){
                return 1;
            }
        }
    }
    return 0;
}

bool simul() {
    for(int i=0; i<K; i++){
        int y = status[i].y;
        int x = status[i].x;
        int dir = status[i].dir;
        move(y,x,dir,i);
        if(isOver()) return 1;
    }
    return 0;
}

int main()
{
    cin >> N >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> a[i][j];
        }
    }
    for(int i=0; i<K; i++){
        cin >> y >> x >> dir; y--; x--; dir--;
        v[y][x].push_back(i);
        status.push_back({y,x,dir});
    }
    while(ret <= 1000){
        ret++;
        if(simul()){
            break;
        }
    }
    if(ret <1000)cout << ret << '\n';
    else cout << -1 << '\n';
    return 0;
}
