#include <bits/stdc++.h>
using namespace std;

int n, m, ar[100004], k, j;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> ar[i];
        ar[i] += ar[i-1];
    }
    // for(int i=0; i<=n; i++)cout << ar[i] << '\n';
    for(int i=0; i<m; i++){
        cin >> k >> j;
        if(k == j) cout << ar[j] - ar[j-1] << '\n';
        else cout << ar[j] - ar[k-1] << '\n';
    }

    return 0;
}
