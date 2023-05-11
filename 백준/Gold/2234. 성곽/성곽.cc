#include <bits/stdc++.h>
using namespace std;

int m, n, ar[54][54], visited[54][54], cnt, room, max_room;
int dfs(int y, int x){
        if(ar[y][x] < 0)return 0;
        int rooms = 1;
        visited[y][x] = 1;
        if((ar[y][x] & (1<<0)) == 0 && x-1 >= 0 && !visited[y][x-1])rooms += dfs(y, x-1);
        if((ar[y][x] & (1<<1)) == 0 && y-1 >= 0 && !visited[y-1][x])rooms += dfs(y-1, x);
        if((ar[y][x] & (1<<2)) == 0 && x+1 < m && !visited[y][x+1])rooms += dfs(y, x+1);
        if((ar[y][x] & (1<<3)) == 0 && y+1 < n && !visited[y+1][x])rooms += dfs(y+1, x);
        
        return rooms;
}

int main() {
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ar[i][j];
        }
    }
    //     for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << ar[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j])continue;
            room = max(room, dfs(i,j));
            cnt++;
        }
    }
        for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k = 0; k<=3; k++){
                memset(visited, 0, sizeof(visited));
                if(ar[i][j] & (1<<k)){
                ar[i][j] &= ~(1<<k);
                // if(i == 3 && j == 0)cout << ar[i][j] << ' ';
                max_room = max(max_room, dfs(i,j));
                // cout << i << '.' << j << ':' << dfs(i,j) << '\n'; 
                ar[i][j] |= (1<<k);
                }

            }
            
     
        }
    }
    cout << cnt << '\n' << room << '\n' << max_room << '\n';
    return 0;
}
