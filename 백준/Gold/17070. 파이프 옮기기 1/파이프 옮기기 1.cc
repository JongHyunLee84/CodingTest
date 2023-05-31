#include <bits/stdc++.h>
using namespace std;

int n, dp[20][20][3] ,ar[16][16], ret;

bool check(int y, int x, int dir){
    if(dir == 0 || dir == 2){
        if(!ar[y][x])return true;
    }else if(dir == 1){
        if(!ar[y][x] && !ar[y-1][x] && !ar[y][x-1])return true;
    }
    return false;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> ar[i][j];
        }
    }
    dp[0][1][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check(i, j+1, 0))dp[i][j+1][0] += dp[i][j][0];
            if(check(i+1, j+1, 1))dp[i+1][j+1][1] += dp[i][j][0];
            
            if(check(i+1, j, 2))dp[i+1][j][2] += dp[i][j][2];
            if(check(i+1, j+1, 1))dp[i+1][j+1][1] += dp[i][j][2];
            
            if(check(i, j+1, 0))dp[i][j+1][0] += dp[i][j][1];
            if(check(i+1, j+1, 1))dp[i+1][j+1][1] += dp[i][j][1];
            if(check(i+1, j, 2))dp[i+1][j][2] += dp[i][j][1];
        }
    }
    ret = dp[n-1][n-1][0];
    ret += dp[n-1][n-1][1];
    ret += dp[n-1][n-1][2];
    cout << ret << '\n';
    return 0;
}
