#include <bits/stdc++.h>
using namespace std;

int n, ret, dp[16][1 << 16], cost[16][16], INF = 1e9;

int tsp(int here, int visited) {
    if(visited == (1 << n) - 1){
        return cost[here][0] ? cost[here][0] : INF;
    }
    int &ret = dp[here][visited];
    if(ret != 0 )return ret;
    ret = INF;
    for(int i=0; i<n; i++){
        if(visited & (1 << i)) continue;
        if(cost[here][i] == 0) continue;
        ret = min(ret, tsp(i, visited | (1<<i)) + cost[here][i]);
    }
    return ret;
}

int main()
{
    cin >> n; 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> cost[i][j];
        }   
    }
    
    cout << tsp(0, 1) << '\n';

    return 0;
}
