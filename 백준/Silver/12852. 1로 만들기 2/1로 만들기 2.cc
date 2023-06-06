#include <bits/stdc++.h>
using namespace std;

int n, dp[10000004], pre[10000004];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n ;
    dp[1] = 0;
    dp[2] = 1;
    pre[2] = 1;
    pre[3] = 1;
    dp[3] = 1;
    for(int i=4; i<=n; i++){
        dp[i] = dp[i-1];
         pre[i] = i-1;
        if(i % 3 == 0 && dp[i] > dp[i/3]){
            dp[i] = dp[i/3];
            pre[i] = i / 3;
        }
        if(i % 2 == 0 && dp[i] > dp[i/2]){
            dp[i] = dp[i/2];
            pre[i] = i / 2;
        }
        dp[i] += 1;
    }
    cout << dp[n] << '\n';
    int idx = n;
    while(pre[idx] != 0){
        cout << idx << ' ';
        idx = pre[idx];
    }
    cout << 1 << '\n';
    return 0;
}
