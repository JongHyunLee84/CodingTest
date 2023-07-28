#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
string name, isCome;
set<string> s;
map<string, string> mp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> name >> isCome;
        s.insert(name);
        mp[name] = isCome;
    }
    vector<string> v;
    for(string i : s){
        if(mp[i] == "enter")v.push_back(i);
    }
    for(int i=v.size()-1; i>=0; i--){
        cout << v[i] << '\n';
    }
    return 0;
}
