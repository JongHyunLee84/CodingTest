#include <bits/stdc++.h>
using namespace std;

int n, k, idx = 0;
vector<pair<int,int>> jew;
vector<int> bag;
int a, b;
long long ret;
int main()
{
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        jew.push_back({a,b});
    }
    for(int i=0; i<k; i++){
        cin >> a;
        bag.push_back(a);
    }
    sort(jew.begin(), jew.end());
    sort(bag.begin(), bag.end());
    priority_queue<int> pq;
    for(int i : bag){
        while(idx < n && i >= jew[idx].first){
            pq.push(jew[idx].second);
            idx++;
        }
        if(pq.size()){
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret << '\n';
    return 0;
}
