#include <bits/stdc++.h>
using namespace std;
const int max_ = 200004;
int n, k, ar[max_], visited[max_];
queue<int> q;
vector<int> v;
int main()  {
    cin >> n >> k;
    q.push(n);
    ar[n] = 1;
    visited[n] = n;
    
    while(q.size()) {
        int now = q.front();
        // cout << now << ':';
        //     for(int i : visited[now]) {
        //         cout << i << ' ';
        //     }
        //     cout << '\n';
        q.pop();
        for(int next : {now+1, now-1, now*2}) {
            if( 0 <= next && next <= 100000 ){
                if(!ar[next]){
                    ar[next] = ar[now] + 1;
                    q.push(next);
                    visited[next] = now;
                
                } 
                // if(next == k) {
                //     cout << ar[k]-1 << '\n';
                //     for(int i : visited[k]){
                //         cout << i << ' ';
                //     }
                //     exit(0);
                // }
                // else if(ar[next] == ar[now] + 1){
                //     visited[next] += 1;
                // }
            }
        }
        // visited[now] = {};
    }
    cout << ar[k]-1 << '\n';
    int temp = k;
    for(int i=0; i<ar[k]-1; i++){
        v.push_back(visited[temp]);
        temp = visited[temp];
    }
    reverse(v.begin(),v.end());
    v.push_back(k);
    for(int i : v) cout << i << ' ';
    return 0;    
}

