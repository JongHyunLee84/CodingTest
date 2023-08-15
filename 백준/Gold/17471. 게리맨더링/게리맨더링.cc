#include <bits/stdc++.h>
using namespace std;

int n, pop[14], visited[14], temp, near, ret = 1e9;

void checkMax(vector<int> f, vector<int> s){
    int f_ = 0, s_ = 0;
    for(int i : f)f_ += pop[i];
    for(int i : s)s_ += pop[i];
    int gap = abs(f_ - s_);
    ret = min(ret, gap);
}

bool isConnect(vector<int> f, vector<vector<int>> v){
    queue<int> q;
    memset(visited, 0, sizeof(visited));
    if(f.size()){
        q.push(f[0]);
        while(q.size()){
            int temp = q.front(); q.pop();
            visited[temp] = 1;
            for(int i=0; i<v[temp].size(); i++){
                if(visited[v[temp][i]])continue;
                if(find(f.begin(), f.end(), v[temp][i]) != f.end()){
                    q.push(v[temp][i]);
                }
            }
        }
    }
    for(int i=0; i<f.size(); i++){
        if(visited[f[i]])continue;
        else return false;
    }
    return true;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)cin>>pop[i];
    vector<vector<int>> v;
    for(int i=1; i<=n; i++){
        cin >> temp;
        vector<int> temp_v;
        for(int j=0; j<temp; j++){
            cin >> near; near--;
            temp_v.push_back(near);
        }
        v.push_back(temp_v);
    }
    for(int i=1; i<(1<<n)-1; i++){
        vector<int> team1, team2;
        for(int j=0; j<n; j++){
            if(i & (1<<j))team1.push_back(j);
            else team2.push_back(j);
        }
        if(!isConnect(team1, v) || !isConnect(team2, v))continue;
        // cout << "team 1 : ";
        // for(int j : team1)cout << j << ' ';
        // cout << '\n';
        // cout << "team 2 : ";
        // for(int j : team2)cout << j << ' ';
        // cout << '\n';
        checkMax(team1, team2);
    }
    if(ret == 1e9)cout << -1 << '\n';
    else cout << ret << '\n';
    return 0;
}
