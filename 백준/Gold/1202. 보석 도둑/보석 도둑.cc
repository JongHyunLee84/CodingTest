#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
ll ret;

int main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
   cin >> n >> k;
   vector<pair<int,int>> jew(n);
   vector<int> bag(k);
   for(int i=0; i<n; i++){
       cin >> jew[i].first >> jew[i].second;
   }
   for(int i=0; i<k; i++){
       cin >> bag[i];
   }
   sort(jew.begin(),jew.end());
   sort(bag.begin(), bag.end());
   priority_queue<int> pq;
   int idx = 0;
    for(int i : bag){
        while(idx < n && i >= jew[idx].first){
            pq.push(jew[idx].second);
            idx++;
        }
        if(pq.size()){
            ret += pq.top(); pq.pop();
        }
        
    }
    cout << ret << '\n';
    return 0;
}
