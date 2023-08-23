#include <bits/stdc++.h>
using namespace std;

int T, K, a, b, ret, visited[1004];
string s;
vector<string> v;

void rotate_(int idx, int dir){
        visited[idx] = 1;
        if(idx-1 >= 0 && !visited[idx-1] && v[idx][6] != v[idx-1][2]){
            rotate_(idx-1, dir * -1);
        }
        if(idx+1 < T && !visited[idx+1] && v[idx][2] != v[idx+1][6]){
            rotate_(idx+1, dir * -1);
        }

    if(dir == 1)rotate(v[idx].rbegin(), v[idx].rbegin()+1, v[idx].rend());
    else rotate(v[idx].begin(), v[idx].begin()+1, v[idx].end());
    // cout << idx << ' ' << v[idx] << '\n';
//     if(dir == 1)rotate(v[idx].begin(), v[idx].begin()+1, v[idx].end());
//     else rotate(v[idx].rbegin(), v[idx].rbegin()+1, v[idx].rend());
}

int main() {
 // 오른족 2, 왼쪽 6 인덱스
    cin >> T;
    
    for(int i=0; i<T; i++){
        cin >> s;
        v.push_back(s);
    }
    cin >> K;
    for(int i=0; i<K; i++){
        cin >> a >> b; a--;
        memset(visited, 0, sizeof(visited));
        rotate_(a, b);
        // cout << "---------" << '\n';
    }
    for(int i=0; i<T; i++){
        if(v[i][0] == '1')ret++;
    }
    cout << ret << '\n';
    return 0;
}
