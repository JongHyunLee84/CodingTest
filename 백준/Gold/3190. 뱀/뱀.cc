#include <bits/stdc++.h>
using namespace std;

int n, ar[104][104], k, l, a, b, ret, cnt, dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0}, dir;
char c;
vector<pair<int, char>> v;
list<pair<int,int>> li;
bool move() {
    int ny = dy[dir] + li.back().first;
    int nx = dx[dir] + li.back().second;
    if(ny < 0 || nx < 0 || ny >= n || nx >= n)return false;
    if(ar[ny][nx] == 2)return false;
    if(!ar[ny][nx]){
        ar[li.front().first][li.front().second] = 0;
        li.pop_front();
    }
    ar[ny][nx] = 2;
    li.push_back({ny, nx});
    return true;
}

void rotate_(char ch){
    if(ch == 'L')dir = (dir + 3) % 4;
    else dir = (dir + 1) % 4;
}

int main()
{
    cin >> n >> k;
    for(int i=0; i<k; i++){
        cin >> a >> b; a--; b--;
        ar[a][b] = 1;
    }
    cin >> l;
    for(int i=0; i<l; i++){
        cin >> a >> c;
        v.push_back({a,c});
    }
    ar[0][0] = 2;
    li.push_back({0,0});
    while(1){
        ret++;
        if(!move())break;
        if(ret == v[cnt].first){
            rotate_(v[cnt].second);
            cnt++;
        }
    }
    cout << ret << '\n';
    return 0;
}
