#include <bits/stdc++.h>
using namespace std;
int n, m, t, temp, ret, xi, di, ki, ar[54][54];


void rotate_(int idx, int dir, int cnt){
    vector<int> v;
    for(int i=0; i<m; i++)v.push_back(ar[idx][i]);
    if(dir == 0)rotate(v.rbegin(), v.rbegin()+cnt, v.rend());
    else rotate(v.begin(), v.begin()+cnt, v.end());
    for(int i=0; i<m; i++)ar[idx][i] = v[i];
}

void to_average() {
    double sum = 0;
    double d = 0;
    double average = sum / d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ar[i][j] == 0)continue;
            sum += ar[i][j];
            d++;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ar[i][j] == 0 )continue;
            if(ar[i][j] > (sum/d))ar[i][j]--;
            else if(ar[i][j] < (sum/d))ar[i][j]++;
        }
    }
    // cout << "sum: " << sum << "d : " << d << "average : " << sum/d << '\n';
}

void check() {
    vector<pair<int,int>> p;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ar[i][j] == 0)continue;
            if((ar[i][j]) == ar[i][ (j+1) % m]){
                p.push_back({i,j%m});
                p.push_back({i,(j+1)%m});
            }
            if(i != n-1){
                if( ar[i][j] == ar[i+1][j]){
                p.push_back({i,j});
                p.push_back({i+1, j});
            }
        }
    }
    }
    if(p.size() != 0){
        for(auto i : p){
            ar[i.first][i.second] = 0;
        }
    }else {
        to_average();
    }
    // cout << "start" << '\n';
    //         for(int i=0; i<n; i++){
    //         for(int j=0; j<m; j++){
    //             cout << ar[i][j] << ' ' ;
    //         }
    //         cout << '\n';
    //     }
}

int main()
{
    cin >> n >> m >> t;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ar[i][j];
        }
    }
    for(int i=0; i<t; i++){
        cin >> xi >> di >> ki;
        for(int j=xi; j<=n; j += xi){
            rotate_(j-1, di, ki);
        }
        check();
    }

    for(int i=0; i<n; i++){
        for(int j=0; j< m; j++){
            ret += ar[i][j];
        }
    }
    cout << ret << '\n';
    return 0;
}
