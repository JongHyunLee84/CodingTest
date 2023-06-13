#include<bits/stdc++.h>
using namespace std; 

int n, m1, m2, c, dp[10004];

int main() {
    while(1){
        scanf("%d %d.%d", &n, &m1, &m2);
        if(n == 0)break;
        int cost = m1 * 100 + m2;
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=n; i++){
            scanf("%d %d.%d", &c, &m1, &m2);
            int p = m1 * 100 + m2;
            for(int j=p; j<=cost; j++){
                dp[j] = max(dp[j], dp[j-p]+c);
            }
        }
        cout << dp[cost] << '\n';
    }
    return 0;
}
