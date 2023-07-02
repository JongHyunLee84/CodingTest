#include <bits/stdc++.h>
using namespace std;

int N, M, C, ar[15], dp[14][1 << 13][24];

int go(int bags, int jews, int capa){
    if(bags == M)return 0;
    int &ret = dp[bags][jews][capa];
    if(ret)return ret;
    ret = max(ret, go(bags+1, jews, C));
    for(int i=0; i<N; i++){
        bool isThere = (1 << i) & jews;
        bool isAvail = (capa - ar[i]) >= 0;
        if(!isThere && isAvail)ret = max(ret, go(bags, jews | (1<<i), capa - ar[i]) + 1);
    }
    return ret;
}

int main() {
    cin >> N >> M >> C;
    for(int i=0; i<N; i++)cin >> ar[i];
    cout << go(0,0,C);
    return 0;
}
// 가방에 순서대로 넣는게 아니라 있는 가방에 해당 보석이 들어가도 최대 무게를 넘지 않으면 무작위로 들어갈 수 있어야함.