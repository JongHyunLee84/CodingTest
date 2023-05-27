#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s, c, ret, mx , temp, ar[1000004], sum;

bool check(ll mid) {
    ll cnt = 0;
    for(int i=0; i<s; i++){
        cnt += (int)ar[i]/(int)mid;
    }
    // cout << cnt << '\n';
    return c <= cnt;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NUll); cout.tie(NUll);
    // cout << "18" << '\n';
    cin >> s >> c;
    for(int i=0; i<s; i++){
        cin >> ar[i];
        mx = max(mx, ar[i]);
        // cout << "22" << '\n';
    }
    ll l = 1, r = mx, mid;
    while(l <= r){
        mid = (l+r)/2;
        // cout << mid << '\n';
        if(check(mid)){
            ret = max(ret,mid);
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }

    for(int i=0; i<s; i++){
        sum += ar[i];
    }
    cout << sum - ret * c << '\n';
    return 0;
}
