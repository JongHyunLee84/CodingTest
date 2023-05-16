#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, ret = INF, ar[24][24];

void go(int num){
    vector<int> start, link;
    int asum = 0;
    int bsum = 0;
    for(int i=0; i<n; i++){
        if(num & (1<<i))start.push_back(i);
        else link.push_back(i);
    }
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            if(i==j)continue;
            asum += ar[start[i]][start[j]];
            bsum += ar[link[i]][link[j]];
        }
    }
    ret = min(ret, abs(asum - bsum));
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> ar[i][j];
        }
    }
    for(int i=0; i < (1<<n); i++){
        int cnt = 0;
        for(int j=0; j < n; j++){
            if(i & (1<<j))cnt++;
        }
        if(cnt == n/2)go(i);
    }
    cout << ret << '\n';
    return 0;
}
