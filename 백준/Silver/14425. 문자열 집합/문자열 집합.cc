#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
string temp;
map<string, int> mp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> temp;
        mp[temp] = 1;
    }
    for(int i=0; i<m; i++){
        cin >> temp;
        if(mp[temp] == 1)ret++;
    }
    cout << ret << '\n';
    return 0;
}
