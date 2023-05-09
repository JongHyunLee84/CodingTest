#include<bits/stdc++.h>
using namespace std;

int n, ar[24], ret = 987654321;
string s;
void go(int idx){
    if(idx == n){
        // for(int i=0; i<n; i++)cout << ar[i] << '\n';
        // cout << "end\n";
        int sum = 0;
        for(int i=1; i<= (1 << (n - 1)); i *= 2){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(ar[j] & i)cnt++;
            }
            sum += min(cnt, n -cnt);
        }
        ret = min(ret, sum);
        return;
    }
    go(idx+1);
    ar[idx] = ~ar[idx];
    go(idx+1);
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        int temp = 1;
        for(int j=0; j<n; j++){
            if(s[j]=='T')ar[i] |= temp;
            temp *= 2;
        }
    }
    go(0);
    cout << ret << '\n';
    return 0;
}
