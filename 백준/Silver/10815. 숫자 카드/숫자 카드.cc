#include <bits/stdc++.h>
using namespace std;

int n, temp;
map<int, int> mp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        mp[temp] = 1;
    }
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        if(mp[temp] == 1)cout << 1 << ' ';
        else cout << 0 << ' ';
    }

    return 0;
}
