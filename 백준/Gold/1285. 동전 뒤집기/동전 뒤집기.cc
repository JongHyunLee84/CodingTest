#include <bits/stdc++.h>
using namespace std;

int n, ar[24][24], ret = 1e9;
string s;

void go(int idx){
    if(idx == n){
        int cnt = 0;
        for(int i=0; i<n; i++){
            int isChange = 0;
            for(int j=0; j<n; j++){
                isChange += ar[j][i];
            }
            if(isChange > n/2)cnt += n - isChange;
            else cnt += isChange;
        }
        ret = min(ret, cnt);
        return;
    }
    go(idx+1);
    for(int i=0; i<n; i++){
        ar[idx][i] ^= 1;
    }
    go(idx+1);
    for(int i=0; i<n; i++){
        ar[idx][i] ^= 1;
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<n; j++){
            if(s[j] == 'T'){
                ar[i][j] = 1;
            }
        }
    }
    go(0);
    cout << ret << '\n';
    return 0;
}

