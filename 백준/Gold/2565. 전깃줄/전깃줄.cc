#include <bits/stdc++.h>
using namespace std;

int n, a, b, len, ar[1004];
vector<pair<int,int>> v;

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        auto lowerPos = lower_bound(ar, ar + len, v[i].second);
        if(*lowerPos == 0)len++;
        *lowerPos = v[i].second;
    }
    
    cout << n - len << '\n';
    return 0;
}
