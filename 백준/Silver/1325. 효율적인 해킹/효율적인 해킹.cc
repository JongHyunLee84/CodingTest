#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, cnt[10004], visited[10004], ret;
vector<vector<int>> v(10004);
set<int> s;
int main()
{
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        v[b].push_back(a);
    }
    for(int i=1; i<= n; i++){
        memset(visited, 0, sizeof(visited));
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        int sum = 0;
        while(q.size()){
            int f = q.front(); q.pop();
            for(int j : v[f]){
                if(!visited[j]){
                    visited[j] = 1;
                    sum++;
                    q.push(j);
                }
            }
        }
        cnt[i] = sum;
        ret = max(ret, sum);
    }
    for(int i=1; i<=n; i++){
        if(cnt[i] == ret)s.insert(i);
    }
    for(int i : s)cout << i << ' ';
    return 0;
}
