#include <bits/stdc++.h>
using namespace std;

int n, ar[1004], cnt[1004], prev_[1004], idx, ret;

void go(int idx) {
    if(idx == -1)return;
    go(prev_[idx]);
    cout << ar[idx] << ' ';
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)cin >> ar[i];
    memset(prev_, -1, sizeof(prev_));
    for(int i=0; i<n; i++){
        int mx = 0;
        for(int j=0; j<i; j++){
            if(ar[j] < ar[i] && mx < cnt[j]){
                mx = cnt[j];
                prev_[i] = j;
            }
        }
        cnt[i] = mx + 1;
        if(ret < cnt[i]){
            ret = cnt[i];
            idx = i;
        }
    }
    cout << ret << '\n';
    go(idx);
    return 0;
}
