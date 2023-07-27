#include <bits/stdc++.h>
using namespace std;

int n, a, b;
vector<pair<int,int>> v;

bool comp(pair<int,int> p, pair<int,int> p2){
    if(p.first == p2.first)return p.second <= p2.second;
    else return p.first < p2.first;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), comp);
    for(auto i : v)cout << i.first << ' ' << i.second << '\n';
    
    return 0;
}
