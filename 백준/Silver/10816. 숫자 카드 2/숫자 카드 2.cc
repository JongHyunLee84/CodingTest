#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
map<int, int> mp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> ret;
        mp[ret]++;
    }
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> ret;
        cout << mp[ret] << ' ';
    }

    return 0;
}
