#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
map<pair<int,int>, int> mp;
queue<pair<int,int>> q;

void go(int y, int x, int cnt){
    if(mp[{y, x}])return;
    mp[{y,x}] = cnt + 1;
    q.push({y,x});
}

int bfs(int y, int x){
    mp[{y,x}] = 1;
    q.push({y,x});
    while(q.size()){
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();
        go(a, nx, mp[{ny,nx}]);
        go(ny, b, mp[{ny,nx}]);
        go(0, nx, mp[{ny,nx}]);
        go(ny, 0, mp[{ny,nx}]);
        go(min(a, nx+ny), max(0, ny+nx-a), mp[{ny,nx}]);
        go(max(0, ny+nx - b), min(b, ny+nx), mp[{ny,nx}]);
    }
    if(mp[{c,d}])return mp[{c,d}] - 1;
    else return -1;
}

int main()
{
    cin >> a >> b >> c >> d;
    cout << bfs(0,0) << '\n';
    return 0;
}
