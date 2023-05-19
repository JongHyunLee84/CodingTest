#include <bits/stdc++.h>
using namespace std;
int n, ar[104][104], ret;
int x, y, d, g;

void next(int x, int y, int d, vector<pair<int,int>> &v) {
    if(d==0)v.push_back({y,x+1});
    else if(d==1)v.push_back({y-1,x});
    else if(d==2)v.push_back({y,x-1});
    else v.push_back({y+1,x});
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y >> d >> g;
        vector<pair<int,int>> v;
        v.push_back({y,x});
        next(x, y, d, v);
        int ny, nx ;
        for(int j=0; j<g; j++){
            for(int p=v.size()-1; p >0; p--){
                ny = v[p].first - v[p-1].first;
                nx = v[p].second - v[p-1].second;
                if(ny == 0){
                    if(nx < 0 )next(v[v.size()-1].second, v[v.size()-1].first, 3, v);//오른쪽
                    else next(v[v.size()-1].second, v[v.size()-1].first, 1, v);//왼쪽
                }
                else {
                    if(ny < 0)next(v[v.size()-1].second, v[v.size()-1].first, 2, v); // up
                    else next(v[v.size()-1].second, v[v.size()-1].first, 0, v);//down
                }
            }
        }
        
        for(auto j : v) ar[j.first][j.second] = 1;
    }
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(ar[i][j] && ar[i][j+1] && ar[i+1][j] && ar[i+1][j+1])ret++;
        }
    }
    cout << ret <<'\n';
    return 0;
}
