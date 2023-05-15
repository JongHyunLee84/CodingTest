#include <bits/stdc++.h>
using namespace std;

int n, ret, a, b;
vector<pair<int,int>> v;

int main()
{
    cin >> n; 
    for(int i=0; i<n; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        if(ret >= v[i].first)ret += v[i].second;
        else ret = v[i].first + v[i].second;
    }
    cout << ret << '\n';
    return 0;
}
