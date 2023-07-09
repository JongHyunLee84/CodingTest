#include <bits/stdc++.h>
using namespace std;

double j, ar[1004], M, N, K, sum;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> K;
        ar[i] = K;
        M = max(M, K);
    }
    for(int i=0; i<N; i++){
        sum += ar[i] / M * 100;
    }
    cout << sum / N;
    return 0;
}
