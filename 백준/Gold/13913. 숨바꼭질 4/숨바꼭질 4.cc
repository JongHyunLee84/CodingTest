#include <bits/stdc++.h>
using namespace std;

int visited[100004],route[100004], a, b;
queue<int> q;
int main()
{
    cin >> a >> b;
    if(a == b){
        cout << 0 << '\n';
        cout << a << '\n';
        return 0;
    }
    q.push(a);
    visited[a] = 1;
    while(q.size()){
        int now = q.front(); q.pop();
        if(now == b)break;
        for(int next : {now+1, now-1, now*2}){
            if(next < 0 || next > 100000) continue;
            if(visited[next])continue;
            q.push(next);
            visited[next] = visited[now] + 1;
            route[next] = now;
        }
    }
    cout << visited[b]-1 << '\n';
    vector<int> v;
    v.push_back(b);
    while(1){
        if(route[b]){v.push_back(route[b]); b = route[b];}
        else break;
    }
    if(a == 0)v.push_back(a);
    for(int i=v.size()-1; i>=0; i--)cout << v[i] << ' ';
    return 0;
}
