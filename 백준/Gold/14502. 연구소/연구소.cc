#include <bits/stdc++.h>
using namespace std;

int n, m, ar[12][12], visited[12][12], temp_ar[12][12], dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1}, ret;
vector<vector<int>> vv;
vector<pair<int, int>> blank;
void combi(int idx, vector<int> v){
    if(v.size() == 3){
        vv.push_back(v);
        return;
    }
    for(int i=idx+1; i<blank.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}

void print() {
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << visited[i][j] << ' ' ;
        }
        cout << '\n';
    }
    cout << '\n';
}

void count_(){
    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j])sum++;
        }
    }
    // if(sum == 6)print();
    ret = max(ret, sum);
}

void dfs(int y, int x){
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
        if(visited[ny][nx])continue;
        visited[ny][nx] = 2;
        temp_ar[ny][nx] = 1;
        dfs(ny,nx);
    }
}

void spread() {
    memset(temp_ar, 0, sizeof(temp_ar));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j] == 2){temp_ar[i][j] = 1; dfs(i,j);}
        }
    }
}




int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ar[i][j];
            if(!ar[i][j])blank.push_back({i,j});
        }
    }
    vector<int> v;
    combi(-1, v);
    // for(auto i : vv){
    //     for(int j : i){
    //         cout << j << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i=0; i<vv.size(); i++){
        memcpy(visited, ar, sizeof(visited));
        for(int j : vv[i]){
            auto temp = blank[j];
            visited[temp.first][temp.second] = 1;
        }
        spread();
        count_();
        
        // print();
        // cout << '\n';
    }
    cout << ret << '\n';
    return 0;
}
