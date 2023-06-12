#include <bits/stdc++.h>
using namespace std;

int n, k, temp, ar[104], dp[104][100004];

int go(int coins, int total) {
    if(total == 0) return 0;
    if(coins <= 0 || total < 0) return 1e9; 
    int &ret = dp[coins][total];
    if(ret != -1)return ret;
    
    return ret = min(go(coins-1, total), go(coins,total-ar[coins])+1);
}


int main()
{
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> ar[i];
        
    }
    memset(dp, -1, sizeof(dp));
    if(go(n, k) == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << go(n,k);
    }
    return 0;
}
