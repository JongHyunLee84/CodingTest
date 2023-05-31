#include <bits/stdc++.h>
using namespace std;

int n, ar[16][16], ret;

void go(pair<int,int> start, pair<int,int> end) {
    // cout << start.first << '.' << start.second << ' ' << end.first << '.' << end.second << '\n';
    if(end.first == n-1 && end.second == n-1){
        ret ++;
        return;
    }
    int dif_y = end.first - start.first;
    int dif_x = end.second - start.second;
    if(dif_y > 0 && dif_x > 0){
        // 세로
        if(end.first + 1 < n && !ar[end.first+1][end.second])go({start.first+1,start.second+1}, {end.first+1, end.second});
        // 대각
        if(end.second + 1 < n && end.first+1 < n && !ar[end.first][end.second+1] && !ar[end.first+1][end.second+1] && !ar[end.first+1][end.second])go({start.first+1, start.second+1},{end.first+1, end.second+1});
        // 가로
        if(end.second + 1 < n && !ar[end.first][end.second+1])go({start.first+1, start.second+1}, {end.first, end.second+1});
    }else if(dif_y > 0) {
        // 세로
        if(end.first + 1 < n && !ar[end.first+1][end.second])go({start.first+1,start.second}, {end.first+1, end.second});
        // 대각
        if(end.second + 1 < n && end.first+1 < n && !ar[end.first][end.second+1] && !ar[end.first+1][end.second+1] && !ar[end.first+1][end.second])go({start.first+1, start.second},{end.first+1, end.second+1});
    }else {
        if(end.second + 1 < n && !ar[end.first][end.second+1])go({start.first, start.second+1}, {end.first, end.second+1});
        if(end.second + 1 < n && end.first+1 < n && !ar[end.first][end.second+1] && !ar[end.first+1][end.second+1] && !ar[end.first+1][end.second])go({start.first, start.second+1},{end.first+1, end.second+1});
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> ar[i][j];
        }
    }
    go({0,0}, {0,1});
    cout << ret << '\n';
    return 0;
}
