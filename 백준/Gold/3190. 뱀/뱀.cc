#include <bits/stdc++.h>
using namespace std;
int n, ar[104][104], k, l, cnt, direction = 0;
queue<pair<int,char>> turn;
list<pair<int,int>> v;
int a, b, dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};
char c;

bool move(){
    int ny = v.front().first + dy[direction];
    int nx = v.front().second + dx[direction];
    if(ny < 0 || nx < 0 || ny >= n || nx >= n || ar[ny][nx] == -1)return false;
    if(ar[ny][nx] == 1)v.push_front({ny,nx});
    else {
        v.push_front({ny,nx});
        auto temp = v.back();
        ar[temp.first][temp.second] = 0;
        v.pop_back();
    }
    ar[ny][nx] = -1;
    return true;
}

int main() {
    cin >> n >> k;
    for(int i=0; i<k; i++){
        cin >> a >> b;
        ar[--a][--b] = 1;
    }
    cin >> l;
    for(int i=0; i<l; i++){
        cin >> a >> c;
        turn.push({a,c});
    }
    ar[0][0] = -1;
    v.push_back({0,0});
    while(true) {
        if(move())cnt++;
        else break;
        
        // cout << '\n';
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout << ar[i][j] << ' ';
        //     }
            
        //     cout << '\n';
        // }
        // cout << "cnt : " << cnt << '\n';
        
        if(turn.size() && cnt >= turn.front().first){
            auto temp = turn.front();
            turn.pop();
            if(temp.second == 'L')direction = (direction + 3)%4;
            else direction = (direction+1)%4;
        }
        
    }
    cout << cnt+1 << '\n';
    return 0;
}