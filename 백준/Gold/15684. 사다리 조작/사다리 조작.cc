#include <bits/stdc++.h>
using namespace std;

int n, m, h, connected[34][14], a, b, ret = 4, cnt;

void print(){
    cout << '\n';
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            cout << connected[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool check() {
    for(int i=0; i<n; i++){
        int idx = i;
        for(int j=0; j<h; j++){
            if(connected[j][idx]){
                if(idx && connected[j][idx-1]==connected[j][idx])idx -= 1;
                else idx += 1;
            }
        }
        if(idx != i)return false;
    }
    return true;
}

void go(int y, int x, int idx){
    // if(idx==3 && connected[3][1] && connected[3][2] && connected[4][0] && connected[4][1])print();
    if(idx > 3)return;
    if(check()){
        // 아래 잘 체크된거 있는데 ?
        // if(idx == 3)cout << connected[3][1] << ' ' << connected[3][2] << ' ' << connected[4][0] << ' ' << connected[4][1] << ' ' << connected[4][2] << ' ' << connected[4][3] << '\n';
        ret = min(ret, idx);
        return;
    }
    for(int i=y; i<h; i++){
        for(int j=0; j<n-1; j++){
            if(connected[i][j] || connected[i][j+1])continue;
            connected[i][j] = idx+2;
            connected[i][j+1] = idx+2;
            go(i, j, idx+1);
            connected[i][j] = 0;
            connected[i][j+1] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> h;
    if(m == 0){
        cout << 0 << '\n';
        return 0;
    }
    int idx = m;
    for(int i=0; i<m; i++){
        cin >> a >> b; a--; b--;
        connected[a][b] = idx+1;
        connected[a][b+1] = idx+1;
        idx++;
    }
    // for(int i=0; i<h; i++){
    //     for(int j=0; j<n-1; j++){
    //         if(connected[i][j] || connected[i][j+1])continue;
    //         connected[i][j] = 1;
    //         connected[i][j+1] = 1;
    //         go(1);
    //         connected[i][j] = 0;
    //         connected[i][j] = 0;
    //     }
    // }
    go(0, 0, 0);
    if(ret > 3)cout << -1 << '\n';
    else cout << ret << '\n';
    return 0;
}
