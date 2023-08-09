#include <bits/stdc++.h>
using namespace std;

int n, m, temp, result = 1e9;
vector<pair<int,int>> houses, chicken;
vector<vector<int>> com;

void combi(int idx, vector<int> v){
    if(v.size() == m) {
        com.push_back(v);
        return;
    }
    for(int i = idx+1; i < chicken.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> temp;
            if(temp == 1)houses.push_back({i,j});
            else if(temp == 2)chicken.push_back({i,j});
        }
    }
    vector<int> v;
    combi(-1, v);
    // for(int i=0; i<com.size(); i++){
    //     for(int j=0; j<com[i].size(); j++){
    //         cout << com[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i=0; i<com.size(); i++){
        int ret = 0;
        for(int j=0; j<houses.size(); j++){
            int dis = 1e9;
            for(int k=0; k<m; k++){
                dis = min(dis, (abs(houses[j].first - chicken[com[i][k]].first) + abs(houses[j].second - chicken[com[i][k]].second)));
                // cout << dis << '\n';
            }
            ret += dis;
        }
        result = min(ret, result);
    }
    cout << result << '\n';
    return 0;
}
