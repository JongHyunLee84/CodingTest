#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;
ll n, m, ar[100003], ret = INF, sum, mx;

bool check(int mid) {
    if(mid < mx)return false;
    int temp = mid, cnt = 0;
    for(int i=1; i<=n; i++){
        if(temp - ar[i] < 0){
            temp = mid;
            cnt++;
        }
        temp -= ar[i];
    }
    if(temp != mid)cnt++;
    // cout << m << ">=" << cnt << '\n';
    return m >= cnt;
    
}
int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> ar[i];
        mx = max(mx, ar[i]);
        sum += ar[i];
    }
    ll l = 1, r = sum, mid;
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
