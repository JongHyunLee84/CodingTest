#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ret = 1e18, n, atk, ti, ai, hi, sum;

struct Room {
    ll ti, ai,hi;
};
Room v[130005];
bool check(ll mid) {
    ll temp_hp = mid;
    ll temp_atk = atk;
    for(ll i=0; i<n; i++){
        if(v[i].ti == 1){
            ll mon_atk = v[i].ai, mon_hp = v[i].hi;
            if(temp_atk > mon_hp)continue;
            ll sol_atks = (mon_hp / temp_atk) + ((mon_hp % temp_atk) ? 1 : 0);
            ll mon_atks = (temp_hp / mon_atk) + ((temp_hp % mon_atk) ? 1 : 0);
            if(sol_atks > mon_atks)return false;
            else temp_hp -= (mon_atk * (sol_atks-1));
        }else {
            if(temp_hp + v[i].hi > mid){
                temp_hp = mid;
            } else {
                temp_hp += v[i].hi;
            }
            temp_atk += v[i].ai;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> atk;
    for(ll i=0; i<n; i++){
        cin >> v[i].ti >> v[i].ai >> v[i].hi;
        // cout << v[i].ti << v[i].ai << v[i].hi << '\n';
        sum += (v[i].hi * v[i].ai);
    }
    ll l = 1, r = sum, mid;
    while(l <= r){
        mid = (l+r)/2;
        // cout << l << '.' << r << '.' << mid << '\n';
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
