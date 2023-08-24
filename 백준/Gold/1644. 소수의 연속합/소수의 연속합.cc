#include <bits/stdc++.h>
using namespace std;

int n, ar[4000004], sum[2000004], ret;

int main() {
    
    cin >> n;
        for(int i=2; i<=n; i++){
        if(ar[i])continue;
        for(int j=i*2; j<=n; j+=i){
            ar[j] = 1;
        }
    }
    int idx = 0;
    for(int i=2; i<=n; i++){
        if(!ar[i]){
            sum[idx] = i;
            idx++;
        }
    }
    
    int l = 0, r = 0, temp = 0;
    while(1){
        if(temp >= n)temp -= sum[l++];
        else if(r > idx)break;
        else if(temp < n)temp += sum[r++];
        if(temp == n)ret++;
    }
    cout << ret << '\n';
    return 0;
}

