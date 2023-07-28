#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
string s;
map<string, int> mp;
set<string> ss;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s;
        mp[s]++;
    }
    for(int i=0; i<m; i++){
        cin >> s;
        if(mp[s] == 1){
            ss.insert(s);
            ret++;
        }
    }
    cout << ret << '\n';
    for(string i : ss)cout << i << '\n';
    return 0;
}
