#include <bits/stdc++.h>
using namespace std;

int t, w, temp, ar[1004][2], dp[1004][2][34];

int go(int ti, int lo, int move){
    
    if(move < 0) return -1e9;
    if(ti > t) return move >= 0 ? 0 : -1e9;
    int &ret = dp[ti][lo][move];
    if(~ret){
        // cout << ti << ' ' << lo << ' ' << move << '\n';
        return ret;
    }
    return ret = max(go(ti+1, lo, move), go(ti+1, lo^1, move-1)) + ar[ti][lo];
}

int main()
{
    cin >> t >> w;
    for(int i=1; i<=t; i++){
        cin >> temp;
        if (temp == 1) {
            ar[i][0] = 1;
        } else {
            ar[i][1] = 1;
        }
    }
    memset(dp, -1,sizeof(dp));
    cout << max(go(1,0,w), go(1,1,w-1)) << '\n';
    return 0;
}
