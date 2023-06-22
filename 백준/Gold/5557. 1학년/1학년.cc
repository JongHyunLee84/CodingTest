#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, ar[104], dp[104][24];

ll go(int idx, int sum){
    // cout << idx << ' ' << sum << '\n';
    if(sum > 20 || sum < 0)return 0;
    if(idx == N-2){
        if(sum == ar[N-1])return 1;
        else return 0;
    }
    ll &ret = dp[idx][sum];
    if(ret != -1)return ret;
    ret = 0;
    ret += go(idx+1, sum+ar[idx+1]);
    ret += go(idx+1, sum-ar[idx+1]);
    return ret;
}

int main()
{
    cin>> N;
    for(int i=0; i<N; i++)cin>>ar[i];
    memset(dp, -1, sizeof(dp));
    cout << go(0, ar[0]) << '\n';

    return 0;
}
