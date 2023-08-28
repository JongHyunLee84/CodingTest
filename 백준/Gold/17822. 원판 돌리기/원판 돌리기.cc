#include <bits/stdc++.h>
using namespace std;

// x의 배수 인덱스들만 회전, d가 0이면 시계 1이면 반시계
int n, m, t, xi, di, ki, temp, ret;
vector<vector<int>> vv;

void rotate_(int x, int d, int k){
    for(int i=x; i<=n; i += x){
        if(d) rotate(vv[i-1].begin(), vv[i-1].begin() + k , vv[i-1].end()); 
        else rotate(vv[i-1].rbegin(), vv[i-1].rbegin() + k , vv[i-1].rend());
    }
    vector<pair<int,int>> erase_v;
    int total = 0, cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vv[i][j] && vv[i][j] == vv[i][(j+1)%m]){erase_v.push_back({i,j}); erase_v.push_back({i,(j+1)%m});}
            if(vv[i][j]){total += vv[i][j]; cnt++;}
        }
    }
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n-1; j++){
            if(vv[j][i] && vv[j][i] == vv[j+1][i]){erase_v.push_back({j,i}); erase_v.push_back({j+1, i});}
        }
    }
    double average = (double)total / (double)cnt;
    if(erase_v.size()){
        for(auto i : erase_v)vv[i.first][i.second] = 0;
    }
    else {
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vv[i][j] && (double)vv[i][j] > average)vv[i][j]--;
                else if(vv[i][j] && (double)vv[i][j] < average)vv[i][j]++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> t;
    for(int i=0; i<n; i++){
        vector<int> v(m);
        for(int j=0; j<m; j++){
            cin >> v[j];
        }
        vv.push_back(v);
    }
    for(int i=0; i<t; i++){
        cin >> xi >> di >> ki;
        rotate_(xi, di, ki);
        // 
        // cout << '\n';
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout << vv[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        //
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ret += vv[i][j];
        }
    }
    cout << ret << '\n';
    return 0;
}
