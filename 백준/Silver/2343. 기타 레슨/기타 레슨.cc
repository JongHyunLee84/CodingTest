#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;
ll n, m, ar[100003], ret = INF;

bool check(int mid) {
    int minus = 0, cnt = 0;
    for(int i=1; i<n; i++){
        // cout << ar[i] - minus << "==" << mid << "or" << ar[i+1]-minus << '>' << mid << '\n';
        if( (ar[i]-minus) > mid)return false;
        else if( (ar[i]-minus) == mid ){
            minus = ar[i];
            cnt++;
        } else if( (ar[i+1]-minus) > mid) {
            minus = ar[i];
            cnt++;
        } else if( (ar[i+1]-minus) == mid){
            minus = ar[i+1];
            cnt++;
        }
    }
    if(minus != ar[n])cnt++;
    // cout << m << ">=" << cnt << '\n';
    return m >= cnt;
    
}
int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> ar[i];
        ar[i] += ar[i-1];
    }
    ll l = 1, r = ar[n], mid;
    while(l <= r) {
        mid = (l+r)/2;
        if(check(mid)){
            ret = min(ret, mid);
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    cout << ret << '\n';
    return 0;
}
