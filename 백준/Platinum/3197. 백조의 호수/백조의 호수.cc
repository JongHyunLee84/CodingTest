#include <bits/stdc++.h>
using namespace std;

char ar[1504][1504];
int n, m;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1}, cnt, visited[1504][1504], visited_[1504][1504], ret;
pair<int,int> p;
queue<pair<int,int>> q, lq, ltemp, temp;

void Qclear(queue<pair<int,int>> &q){
   queue<pair<int,int>> empty;
   swap(q,empty);
}  

int main() {
    cin >> n >> m ;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ar[i][j];
            if(ar[i][j] == 'L')p = {i,j};
            if(ar[i][j] == '.' || ar[i][j] == 'L') {
                visited[i][j] = 1;
                q.push({i,j});
            }
        }
    }
    lq.push(p);
    visited_[p.first][p.second] = 1;
     while(!ret){
    // for(int i=0; i<10; i++){
        // memset(visited, 0, sizeof(visited));
        while(lq.size()){
        // memset(visited_, 0, sizeof(visited_));
        int ly = lq.front().first;
        int lx = lq.front().second;
        lq.pop();
        if(ret)break;
    for(int i=0; i<4; i++){
        int ny = ly + dy[i];
        int nx = lx + dx[i];
        if(ny<0 || nx<0 || ny >= n || nx >= m)continue;
        if(visited_[ny][nx])continue;
        visited_[ny][nx] = 1;
        if(ar[ny][nx] == 'X')ltemp.push({ny,nx});
        else if(ar[ny][nx] == '.')lq.push({ny,nx});
        else if(ar[ny][nx] == 'L'){
            ret =cnt;
            break;
        }
    }
        if(ret)break;
        }
        if(ret)break;
        while(q.size()){
            int fy = q.front().first;
            int fx = q.front().second;
            q.pop();
                    for(int k=0; k<4; k++){
                        int ny = fy + dy[k];
                        int nx = fx + dx[k];
                        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx])continue;
                         if(ar[ny][nx] == 'X'){
                visited[ny][nx] = 1; 
                temp.push({ny,nx});
                ar[ny][nx] = '.'; 
            } 
                    }
        }
        q = temp;
        lq = ltemp;
        Qclear(temp);
        Qclear(ltemp);
        cnt++;
        // cout << "start" << '\n';
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout << ar[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << "end" << '\n';
    }
    // cout << "end" <<'\n';
    cout << ret << '\n';
    
    return 0;
}
