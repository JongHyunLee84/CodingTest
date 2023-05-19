#include <bits/stdc++.h>
using namespace std;
int n, ar[104][104], ret;
int x, y, d, g;
vector<int> dragon[4][11];
int dy[4] = {0,-1,0,1}, dx[4] = {1,0,-1,0};
void make_dragon() {
    for(int i=0; i<4; i++){
        dragon[i][0].push_back(i);
        dragon[i][1].push_back((i+1)%4);
        for(int j=2; j<=10; j++){
            int n = dragon[i][j-1].size();
            for(int k=n-1; k>=0; k--){
                dragon[i][j].push_back((dragon[i][j-1][k]+1)%4);
            }
            for(int k=0; k<n; k++){
                dragon[i][j].push_back((dragon[i][j-1][k]));
            }
        }
    }
}

void go(int x, int y, int d, int g){
    ar[y][x] = 1;
    for(int i=0; i<=g; i++){
        for(int j : dragon[d][i]){
            y += dy[j];
            x += dx[j];
            ar[y][x] = 1;
        }
    }
}

int main() {
    cin >> n;
    make_dragon();
    for(int i=0; i<n; i++){
        cin >> x >> y >> d >> g;
        go(x,y,d,g);
    }
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(ar[i][j] && ar[i][j+1] && ar[i+1][j] && ar[i+1][j+1])ret++;
        }
    }
    cout << ret <<'\n';
    return 0;
}
