#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ar[100004], mx;
ll ret = 1e18, sum;

bool check(ll mid) {
    ll cnt = 0;
    ll temp = mid;
    for(int i=0; i<n; i++){
        if(temp - ar[i] < 0){
            cnt++;
            temp = mid;
        }
        temp -= ar[i];
    }
    if(temp != mid)cnt++;
    return m >= cnt;
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin>>ar[i];
        sum += ar[i];
        mx = max(mx,ar[i]);
    }
    ll l = mx, r = sum, mid;
    while(l <= r) {
        mid = (l+r) / 2;
        if(check(mid)) {
            r = mid - 1;
            ret = min(ret, mid);
        }else l = mid + 1;
    }
    cout << ret << '\n';
    return 0;
}
