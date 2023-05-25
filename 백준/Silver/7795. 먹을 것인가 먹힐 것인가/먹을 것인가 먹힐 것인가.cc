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
        vector<int> a(n),b(m);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<m; i++){
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        
        for(int i=0; i<n; i++){
            int lower = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            ret += lower;
        }
        cout << ret << '\n';
    }
    return 0;
}
