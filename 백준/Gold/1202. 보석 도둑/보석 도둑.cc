#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, m, v, c, ret;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    vector<pair<int,int>> jew(n);
    vector<int> bag(k);
    for(int i=0; i<n; i++){
        cin >> m >> v;
        jew[i] = {m,v};
    }
    for(int i=0; i<k; i++){
        cin >> c;
        bag[i] = c;
    }
    sort(bag.begin(), bag.end());
    sort(jew.begin(), jew.end());
    int j = 0;
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        while(j < n && jew[j].first <= bag[i])pq.push(jew[j++].second);
        if(pq.size()){
            ret += pq.top(); pq.pop();
        }
    }
    cout << ret << '\n';
    return 0;
}
