#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ret, ar[10004], r = 60000000004;

bool check(ll mid) {
    ll temp = m;
    for(int i=0; i<m; i++)temp += mid/ar[i];
    return n <= temp;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> ar[i];
    }
    if(n <= m){
        cout << n << '\n';
        return 0;
    }
    ll l = 0, mid;
    while(l <= r){
        mid = (l+r)/2;
        if(check(mid)){
            r = mid - 1;
            ret = mid;
        }else {
            l = mid + 1;
        }
    }
    // cout << ret << '\n';
    ll temp = m;
    for(int i=0; i<m; i++)temp += ((ret-1) / ar[i]);
    for(int i=0; i<m; i++){
        if(ret % ar[i] == 0)temp++;
        if(temp == n){
            cout << i + 1 << '\n';
            return 0;
        }
    }
    return 0;
}


