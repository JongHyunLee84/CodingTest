#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, dp[34][34];

ll go(int full, int half) {
    if(full == 0 && half == 0)return 1;
    ll &ret = dp[full][half];
    if(ret)return ret;
    if(full > 0) ret += go(full-1, half+1);
    if(half > 0) ret += go(full, half-1);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(1) {
        // memset(dp, -1, sizeof(dp));
        cin >> n;
        if(n == 0)break;
        cout << go(n,0) << '\n';
    }
    return 0;
}
