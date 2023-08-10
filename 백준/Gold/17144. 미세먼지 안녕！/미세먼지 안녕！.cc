#include <bits/stdc++.h>
using namespace std;

int r, c, t, ar[54][54], temp[54][54], cleaner;
int dy[4] = {0, -1, 0, 1}, dx[4] = {-1, 0, 1, 0};
int count_(){
    int ret = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(ar[i][j] > 0)ret += ar[i][j];
        }
    }
    return ret;
}

void spread() {
    memset(temp, 0, sizeof(temp));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(ar[i][j] == -1)temp[i][j] = -1;
            else if(ar[i][j] > 0){
                int cnt = 0;
                for(int s=0; s<4; s++){
                    int ny = dy[s] + i;
                    int nx = dx[s] + j;
                    if(ny < 0 || nx < 0 || ny >= r || nx >= c)continue;
                    if(ar[ny][nx] == -1)continue;
                    temp[ny][nx] += ar[i][j] / 5;
                    cnt++;
                }
                temp[i][j] += ar[i][j] - (ar[i][j]/5) * cnt;
            }
        }
    }
    memcpy(ar, temp, sizeof(temp));
}

void clean() {
    memset(temp, 0, sizeof(temp));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(!i && j)temp[i][j-1] = ar[i][j];
            else if(!j && i < cleaner-1)temp[i+1][j] = ar[i][j];
            else if(i == cleaner-1 && j && j < c-1)temp[i][j+1] = ar[i][j];
            else if(i && j == c-1 && i <= cleaner-1)temp[i-1][j] = ar[i][j];
            else if(i == cleaner && j && j < c-1)temp[i][j+1] = ar[i][j];
            else if(i < r-1 && j == c-1)temp[i+1][j] = ar[i][j];
            else if(i == r-1 && j)temp[i][j-1] = ar[i][j];
            else if(i > cleaner && !j)temp[i-1][j] = ar[i][j];
            else temp[i][j] = ar[i][j];
        }
        temp[cleaner-1][0] = -1;
        temp[cleaner][0] = -1;
    }
    memcpy(ar, temp, sizeof(temp));
}

void print() {
            for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cout << ar[i][j] << ' ' ;
            }
            cout << '\n';
        }
}

int main()
{
    cin >> r >> c >> t;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> ar[i][j];
            if(ar[i][j] == -1)cleaner = i;
        }
    }
    for(int s=0; s<t; s++){
        spread();
        // cout << "spread" << '\n';
        // print();
        
        clean();
        // cout << "cleaned" << '\n';
        // print();
    }
    cout << count_() << '\n';
    return 0;
}
