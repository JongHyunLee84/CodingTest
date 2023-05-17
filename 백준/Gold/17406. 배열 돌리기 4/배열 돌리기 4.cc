#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, k, ret = INF;
vector<tuple<int,int,int>> v;
vector<int> per;
struct Board {
    int a[54][54];
    
    void rotate(tuple<int,int,int> tp){
        int temp[54][54];
        memset(temp, 0, sizeof(temp));
        int r, c, s;
        tie(r,c,s) = tp;
        int line = (r+s) - (r-s); // 4
        int lines = ((r+s) - (r-s) + 1)/2; // 2
        pair<int,int> start = {r-s,c-s}; // 1,2
        pair<int,int> end = {r+s,c+s}; // 5,6
        for(int i=0; i<lines; i++){
            for(int j=0; j<line; j++){
                temp[start.first][start.second+j+1] = a[start.first][start.second+j];
                temp[start.first + j + 1][end.second] = a[start.first+j][end.second];
                temp[end.first][end.second - j - 1] = a[end.first][end.second-j];
                temp[end.first - j -1][start.second] = a[end.first - j][start.second];
            }
            start.first++; start.second++;
            end.first--; end.second--;
            line -= 2;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(temp[i][j])a[i][j] = temp[i][j];
            }
        }
    }
    
    void check() {
        // cout << "start" << '\n';
        for(int i=1; i<=n; i++){
            int cnt = 0;
            for(int j=1; j<=m; j++){
                cnt += a[i][j];
                // cout << a[i][j] << ' ' ;
            }
            // cout << '\n';
            ret = min(ret, cnt);
        }
    }
};

int main() {
    cin >> n >> m >> k;
    Board b;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> b.a[i][j];
        }
    }
    for(int i=0; i<k; i++){
        per.push_back(i);
        int aa, bb, cc;
        cin >> aa >> bb >> cc;
        v.push_back({aa,bb,cc});
    }
    do {
        Board temp = b;
        for(int i:per)temp.rotate(v[i]);
        temp.check();
    } while(next_permutation(per.begin(), per.end()));
    cout << ret << '\n';
    return 0;
}