#include<bits/stdc++.h>
using namespace std; 
int n, k,a[10001], temp, INF = 987654321;

int main() {
    cin>>n>>k;
    fill(a, a + 10001, INF);
    a[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> temp;
        for(int j=temp; j <=k; j++){
            a[j] = min(a[j], a[j-temp]+1);
        }
    }
    if(a[k] >= INF)cout << -1 << '\n';
    else cout << a[k];
    return 0;
}