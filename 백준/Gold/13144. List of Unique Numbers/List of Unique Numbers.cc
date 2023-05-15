#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll from, to, n, ar[100004], cnt[100004];
ll ret;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }

    while(to < n){
        if(!cnt[ar[to]]){
            cnt[ar[to]]++;
            to++;
        }
        else{
        ret += (to-from);
        cnt[ar[from]]--;
        from++;
        }
    }

    ret += (ll)(to-from) * (to-from+1) / 2;
    cout << ret << '\n';
    return 0;
}