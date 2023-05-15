#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, s, e, cnt, x;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cin >> x;
    e = n-1;
    sort(v.begin(), v.end());
    while(s<e){
        if(v[s] + v[e] > x) e--;
        else if (v[s] + v[e] == x)cnt++, e--;
        else s++;
    }
    cout << cnt << '\n';
    return 0;
}