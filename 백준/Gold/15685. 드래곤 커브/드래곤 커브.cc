#include <bits/stdc++.h>
using namespace std;

int n, ar[104][104], ret, x, y, d, g, dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0};
struct Dragon {
    int x, y, d;
};

Dragon dra[24];

void print() {
        for(int i=0; i<=8; i++){
        for(int j=0; j<=8; j++){
            cout << ar[i][j] << ' ';
        }
        cout << '\n';
        }
        cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y >> d >> g;
        vector<int> v;
        v.push_back(d);
        ar[y][x] = 1;
        int ny = y + dy[d];
        int nx = x + dx[d];
        ar[ny][nx] = 1;
        pair<int,int> last_point = {ny,nx};
        // print();
        
        for(int j=0; j<g; j++){
            for(int idx=v.size()-1; idx >=0; idx--){
                int dir = (v[idx]+1) % 4;
                int ny = last_point.first + dy[dir];
                int nx = last_point.second + dx[dir];
                last_point = {ny, nx};
                ar[ny][nx] = 1;
                v.push_back(dir);
                // print();
            }
        }
    }
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            int cnt = 0;
            cnt += ar[i][j];
            cnt += ar[i][j+1];
            cnt += ar[i+1][j];
            cnt += ar[i+1][j+1];
            if(cnt == 4)ret++;
        }
    }
    cout << ret << '\n';
    return 0;
}
