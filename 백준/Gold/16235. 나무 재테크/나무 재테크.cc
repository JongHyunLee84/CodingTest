#include <bits/stdc++.h>
using namespace std;

int n, m, a[11][11], k, x, y, z, remain[11][11], ret;
vector<int> v[11][11];
int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1}, dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
void springSummer() {
    // cout << "here" << '\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // if(v[i][j].size() == 0) continue;
            int die_tree = 0;
            sort(v[i][j].begin(), v[i][j].end());
            vector<int> temp;
            // cout << v[i][j].size() << '\n';
            for(int Y : v[i][j]){
                // cout << Y << "and" << remain[i][j] << '\n';
                if(Y <= remain[i][j]){
                        remain[i][j] -= Y;
                        temp.push_back(Y+1);
                }else {
                    die_tree += Y / 2;
                }
            }
            // cout << "here" << '\n';
            // for(int tree : temp)cout << tree << '\n';
            v[i][j] = temp;
            remain[i][j] += die_tree;
        }
    }
}

void fall() {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // if(v[i][j].size() == 0)continue;
            for(int Y : v[i][j]){
                if(Y % 5 == 0){
                    for(int X = 0; X < 8; X++) {
                        int ny = dy[X] + i;
                        int nx = dx[X] + j;
                        if(ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
                        v[ny][nx].push_back(1);
                    }
                }
            }
        }
    }
}

void winter() {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            remain[i][j] += a[i][j];
        }
    }
}
int main()
{
    fill(&remain[0][0], &remain[0][0] + 11 * 11, 5);
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    for(int i=0; i<m; i++){
        cin >> x >> y >> z; x--; y--;
        v[x][y].push_back(z);
    }
    for(int i=0; i<k; i++){
        springSummer();
        fall();
        winter();
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ret += v[i][j].size();
        }
    }
    cout << ret << '\n';
    return 0;
}
