#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 100000;
int su, si, visited[INF+2];
ll cnt[INF+2];


int main() {
    cin >> su >> si;
    if(su == si){
        cout << 0 << '\n';
        cout << 1 << '\n';
        return 0;
    }
    queue<int> q;
    q.push(su);
    visited[su] = 1;
    cnt[su] = 1;
    while(q.size()){
        int now = q.front(); q.pop();
        
        for(int next : {now+1, now-1, now*2}){
            if(0 <= next && next <= INF){
            if(!visited[next]){
                visited[next] = visited[now] + 1;
                cnt[next] += cnt[now];
                q.push(next);
            }else if(visited[next] == visited[now]+1){
                cnt[next] += cnt[now];
            }
        }
        }
        
    }
    cout << visited[si]-1 << '\n';
    cout << cnt[si] << '\n';
    return 0;
}
