#include<bits/stdc++.h>
using namespace std; 

const int INF_MIN = 987654321;
const int INF_MAX = -987654321;
int n, ar[14], pp, mm, mul, dv, mi = INF_MIN, mx = INF_MAX;

void go(int idx,int sum) {
    // cout << sum << '\n';
    if(idx == n-1){
        mi = min(mi, sum);
        mx = max(mx, sum);
        return ;
    }
    if(pp != 0) {
        sum += ar[idx+1];
        pp--;
        go(idx+1, sum);
        pp++;
        sum -= ar[idx+1];
    }
    if(mm != 0) {
        sum -= ar[idx+1];
        mm--;
        go(idx+1, sum);
        mm++;
        sum += ar[idx+1];
    }
    if(mul != 0) {
        sum *= ar[idx+1];
        mul--;
        go(idx+1, sum);
        mul++;
        sum /= ar[idx+1];
    }
    if(dv != 0) {
        sum /= ar[idx+1];
        dv--;
        go(idx+1, sum);
        dv++;
        sum *= ar[idx+1];
    }
    
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    cin >> pp >> mm >> mul >> dv;
    go(0, ar[0]);
    cout << mx << '\n' << mi << '\n';
    return 0;
}