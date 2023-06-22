
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, ar[34], C, ret;
vector<int> v, v2;

void go(int idx, int end, vector<int> &v, int sum){
    // cout << "here" << '\n';
    if(sum > C)return;
    if(idx > end){
        v.push_back(sum);
        return;
    }
    go(idx+1, end, v, sum + ar[idx]);
    go(idx+1, end, v, sum);
    return;
}

int main()
{
    cin >> N >> C;
    for(int i=0; i<N; i++){
        cin >> ar[i];
    }
    
    go(0, N / 2 - 1, v, 0);
    go(N / 2, N-1, v2, 0);
    // cout << "here" << '\n';
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    

    for(int i : v){
        if(C-i >= 0) ret += ((int)(upper_bound(v2.begin(), v2.end(), C-i) - v2.begin()));
    }
    cout << ret << '\n';
    return 0;
}
