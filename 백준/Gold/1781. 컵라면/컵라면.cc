#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a, b, ret;
vector<pair<int, ll>> v;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    for(auto i : v){
        pq.push(i.second);
        if(pq.size() > i.first)pq.pop();
    }
    while(pq.size()){
        ret += pq.top();
        pq.pop();
    }
    cout << ret << '\n';
    return 0;
}
