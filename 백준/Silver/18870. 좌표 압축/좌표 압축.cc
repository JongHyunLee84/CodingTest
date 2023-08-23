#include <bits/stdc++.h>
using namespace std;

int n, temp;
map<int, int> mp;
int main()
{
    cin >> n;
    vector<int> v(n), v2(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        v2[i] = v[i];
    }
    int idx = 1;
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        if(mp[v[i]])continue;
        mp[v[i]] = idx;
        idx++;
    }
    for(int i=0; i<n; i++){
        cout << mp[v2[i]]-1 << ' ';
    }
    return 0;
}
