#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, ret = INF, ar[24][24], visited[24];

int go(vector<int> a, vector<int> b){
    int asum = 0;
    int bsum = 0;
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            if(i==j)continue;
            asum += ar[a[i]][a[j]];
            bsum += ar[b[i]][b[j]];
        }
    }
    return abs(asum - bsum);
}

void combi(int start, vector<int> temp_v) {
    if(temp_v.size() == n/2) {
        vector<int> start, link;
        for(int i=0; i<n; i++){
            if(visited[i])start.push_back(i);
            else link.push_back(i);
        }
        ret = min(ret, go(start, link));
        return;
    }
    for(int i=start+1; i<n; i++){
        visited[i] = 1;
        temp_v.push_back(i);
        combi(i, temp_v);
        visited[i] = 0;
        temp_v.pop_back();
    }
    return;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> ar[i][j];
        }
    }
    vector<int> tv;
    combi(-1, tv);
    cout << ret << '\n';
    return 0;
}
