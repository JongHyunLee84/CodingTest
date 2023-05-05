#include <bits/stdc++.h>
using namespace std;

int n, k, ar[100004], visited[100004];
queue<int> q;

int main()  {
    cin >> n >> k;
    q.push(n);
    ar[n] = 1;
    visited[n] = 1;
    if(n == k){
        puts("0"); puts("1");
        return 0; 
    } 
    while(q.size()) {
        int now = q.front();
        q.pop();
        for(int next : {now+1, now-1, now*2}) {
            if( 0 <= next && next <= 100000 ){
                if(!ar[next]){
                    ar[next] = ar[now] + 1;
                    q.push(next);
                    visited[next] = visited[now];
                } else if(ar[next] == ar[now] + 1){
                    visited[next] += visited[now];
                }
            }
        }
    }
    cout << ar[k]-1 << '\n';
    cout << visited[k] << '\n';
    return 0;    
}

