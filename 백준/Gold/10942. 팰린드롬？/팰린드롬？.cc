#include <bits/stdc++.h>
using namespace std;

int N, ar[2004], M, S, E, dp[2004][2004];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> ar[i];
    }
    for(int i=1; i<=N; i++){
        dp[i][i] = 1;
    }
    for(int i=1; i<=N; i++){
        if(ar[i] == ar[i+1])dp[i][i+1] = 1;
    }
    for(int i=2; i<=N; i++){
        for(int j=1; j<=N-i; j++){
            if(ar[j] == ar[j+i] && dp[j+1][j+i-1])dp[j][j+i] = 1;
        }
    }
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> S >> E;
        cout << dp[S][E] << '\n';
    }

    return 0;
}
