#include <bits/stdc++.h>
using namespace std;

int n, visited[64][64][64], a[3];
int ar[6][3] = {
    {9,3,1},
    {9,1,3},
    {3,9,1},
    {3,1,9},
    {1,3,9},
    {1,9,3}
};
queue<vector<int>> q;

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    q.push({a[0],a[1],a[2]});
    visited[a[0]][a[1]][a[2]] = 1;
    while(q.size()){
        if(visited[0][0][0])break;
        int ta = q.front()[0];
        int tb = q.front()[1];
        int tc = q.front()[2];
        // cout << ta << ' ' << tb << ' '<< tc << '\n';
        q.pop();
        for(int i=0; i<6; i++){
            int ta_ = max(0,ta - ar[i][0]);
            int tb_ = max(0,tb - ar[i][1]);
            int tc_ = max(0,tc - ar[i][2]);
            if(visited[ta_][tb_][tc_])continue;
            visited[ta_][tb_][tc_] = visited[ta][tb][tc] + 1;
            q.push({ta_, tb_, tc_});
        }
    }
    cout << visited[0][0][0]-1 << '\n';
    
    return 0;
}