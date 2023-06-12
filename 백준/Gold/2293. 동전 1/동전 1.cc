#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
int n, k, dp[10004], temp, INF = 1e9;

int main() {
    cin >> n >> k;
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        cin >> temp;
        for(int j=temp; j<=k; j++){
            dp[j] += dp[j-temp];
        }
    }
    cout << dp[k] << '\n';
    return 0;
}
