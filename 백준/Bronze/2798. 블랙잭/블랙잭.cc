#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, ar[104], ret;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(ar[i] + ar[j] + ar[k] <= m)ret = max(ret, ar[i]+ar[j]+ar[k]);
                if(ret == m){
                    cout << ret << '\n';
                    return 0;
                }
            }
        }
    }
    cout << ret << '\n';
    return 0;
}


