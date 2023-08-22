#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b, visited[1004];

int dfs(int node, vector<vector<int>> v){
    int ret = 1;
    for(int i : v[node]){
        if(visited[i])continue;
        visited[i] = 1;
        ret += dfs(i, v);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> m;
        vector<vector<int>> v(n);
        for(int j=0; j<m; j++){
            cin >> a >> b; a--; b--;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        memset(visited, 0, sizeof(visited));
        visited[0] = 1;
        int isTree = dfs(0, v);
        if(isTree == n && n-1 == m)cout << "tree" << '\n';
        else cout << "graph" << '\n';
    }
    
    
    return 0;
}
