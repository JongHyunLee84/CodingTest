#include <bits/stdc++.h>
using namespace std;

int r, c, t, ar[54][54], ty, tx, v, ret;
queue<vector<int>> q;
vector<pair<int,int>> v1,v2,cleaner;
int dy1[] = {0, -1, 0, 1};
int dx1[] = {1, 0, -1, 0};
int dy2[] = {0, 1, 0, -1};
int dx2[] = {1, 0, -1, 0};  

vector<pair<int, int>> chung(int sy, int sx, int dy[], int dx[]){   
    vector<pair<int, int>> v; 
    int cnt = 0; 
    int y = sy; 
    int x = sx;
    while(true){ 
        int ny = y + dy[cnt];
        int nx = x + dx[cnt];  
        if(ny == sy && nx == sx)break;
        if(ny < 0 || ny >= r || nx < 0 || nx >= c){
            cnt++; 
            ny = y + dy[cnt];
            nx = x + dx[cnt];
        } 
        if(ny == sy && nx == sx)break;
        y = ny; x = nx; 
        v.push_back({ny, nx});
    }
    return v;
}

void go(vector<pair<int, int>> &v){  
    for(int i = v.size() - 1; i > 0; i--){
        ar[v[i].first][v[i].second] = ar[v[i - 1].first][v[i - 1].second];
    } 
    ar[v[0].first][v[0].second] = 0; 
    return;
}

int main()
{
    cin >> r >> c >> t;
    bool flag = 1;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> ar[i][j];
            if(ar[i][j]>0)q.push({i, j, ar[i][j]});
            else if(ar[i][j] == -1) {
                cleaner.push_back({i,j});
                if(flag){
                    v1 = chung(i, j, dy1, dx1);
                    flag = false;
                } else v2 = chung(i,j,dy2,dx2);
            }
        }
    }
    for(int s = 0; s<t; s++){
        memset(ar,0,sizeof(ar));
        for(int i=0; i<2; i++){
            ar[cleaner[i].first][cleaner[i].second] = -1;
        }
        while(q.size()){
            ty = q.front()[0];
            tx = q.front()[1];
            v = q.front()[2];
            q.pop();
            int cnt = 0;
            for(int i=0; i<4; i++){
                int ny = ty + dy1[i];
                int nx = tx + dx1[i];
                if(ny<0 || ny >= r || nx<0 || nx>=c || ar[ny][nx] == -1)continue;
                if((v / 5)>0){
                    ar[ny][nx] += v / 5;
                    cnt++;
                }
            }
            ar[ty][tx] += v - (v/5)*cnt; 
        }
    // cout << "start" << '\n';
    // for(int s=0; s<t; s++){
    // for(int i=0; i<r; i++){
    //     for(int j=0; j<c; j++){
    //         cout << ar[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "end" << '\n';
    // }
    go(v1);
    go(v2);
    // cout << "start" << '\n';
    // for(int s=0; s<t; s++){
    // for(int i=0; i<r; i++){
    //     for(int j=0; j<c; j++){
    //         cout << ar[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "end" << '\n';
    // }
            for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(ar[i][j]>0)q.push({i,j,ar[i][j]});
            }
        }
}
    
            for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                ret += ar[i][j];
            }
        }
        cout << ret+2 << '\n';
    return 0;
}
    // cout << "start" << '\n';
    // for(int s=0; s<t; s++){
    // for(int i=0; i<r; i++){
    //     for(int j=0; j<c; j++){
    //         cout << ar[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "end" << '\n';
    // }