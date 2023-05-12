#include <bits/stdc++.h>
using namespace std;

int T, N, M, visited[1001];
int a, b;
vector<int> v[1004];

void dfs(int start){
    visited[start] = 1;
    for(int i : v[start]){
        if(!visited[i])dfs(i);
    }
}

int main(){
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N >> M;
        memset(visited, 0, sizeof(visited));
        for(int i=0; i<1004; i++)v[i].clear();
        int cnt = 0;
        for(int j=0; j<M; j++){
            cin >> a >> b; 
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int k=1; k<=N; k++){
            if(!visited[k]) {
                dfs(k);
                cnt++;
            }
        }
        if( M == N-1 && cnt == 1 ){
            cout << "tree" << '\n';
        } else {
            cout << "graph" << '\n';
        }
    }
    return 0;
}
