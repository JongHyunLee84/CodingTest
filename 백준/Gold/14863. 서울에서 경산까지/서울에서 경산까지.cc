#include <bits/stdc++.h>
using namespace std;

int N, K, lt, lm, ct, cm, dp[104][1000000];
pair<int,int> load[104], cycle[104];

int go(int idx, int sumT, int sumM) {
    if(sumT > K)return -1e9;
    if(idx == N)return sumM;
    int &ret = dp[idx][sumM];
    if(ret != -1)return ret;
    ret = 0;
    ret = max(go(idx+1, sumT + load[idx+1].first, sumM + load[idx+1].second), go(idx+1, sumT + cycle[idx+1].first, sumM + cycle[idx+1].second));
    return ret;
}

int main()
{
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> lt >> lm >> ct >> cm;
        load[i] = {lt,lm};
        cycle[i] = {ct,cm};
    }
    memset(dp, -1, sizeof(dp));
    cout << max(go(0, load[0].first, load[0].second), go(0, cycle[0].first, cycle[0].second)) << '\n';
    return 0;
}
