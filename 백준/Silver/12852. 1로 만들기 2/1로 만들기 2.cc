#include <bits/stdc++.h>
using namespace std;

int n, dp[1000004], prev_[1000004];

int main()
{
    cin >> n;
    fill(dp, dp + 1000004, 1e9);
    dp[1] = 0;
    for(int i=2; i<=n; i++){
        if(i-1 >= 1){
            dp[i] = dp[i-1] + 1;
            prev_[i] = i-1;
        }
        if(i % 2 == 0 && dp[i] > dp[i/2]+1){
            dp[i] = dp[i/2] + 1;
            prev_[i] = i / 2;
        }
        if(i % 3 == 0 && dp[i] > dp[i/3] + 1){
            dp[i] = dp[i/3] + 1;
            prev_[i] = i / 3;
        }
    }
    cout << dp[n] << '\n';
    int temp = n;
    int repeat = dp[n];
    while(repeat--) {
        cout << temp << ' ';
        temp = prev_[temp];
    }
    cout << 1 << '\n';
    return 0;
}
