#include <bits/stdc++.h>
using namespace std;

int n, s[24], h[24], dp[104];

int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    for(int i=0; i<n; i++){
        cin >> h[i];
    }    
    dp[0] = -1e9;
    for(int j=0; j<n; j++){
        for(int i = 100; i >= s[j]; i--){
        dp[i] = max(dp[i], dp[i-s[j]] + h[j]);
    }
    }
    cout << dp[100] << '\n';

    return 0;
}
