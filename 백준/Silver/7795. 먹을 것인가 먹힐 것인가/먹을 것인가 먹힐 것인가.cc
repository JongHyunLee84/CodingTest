#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, n, m, temp;
vector<ll> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> m;
        ll ret = 0;
        vector<int> a,b;
        for(int i=0; i<n; i++){
            cin >> temp;
            a.push_back(temp);
        }
        for(int i=0; i<m; i++){
            cin >> temp;
            b.push_back(temp);
        }
        sort(b.begin(), b.end());
        
        // for(ll i : b)cout << i << ' ';
        // cout << '\n';
        
        for(int i=0; i<n; i++){
            int lower = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            int upper = upper_bound(b.begin(),b.end(), a[i]) - b.begin();
            // cout << a[i] << " lower" << lower << " upper" << upper << '\n';
            if(lower == upper){
                if(b[lower-1] < a[i]){
                    ret += lower;
                }
            } else {
                if(b[lower-1] < a[i]){
                    ret += lower;
                }
            }
            // cout << ret << '\n';
        }
        v.push_back(ret);
    }
    for(ll i : v) cout<< i << '\n';
    return 0;
}
