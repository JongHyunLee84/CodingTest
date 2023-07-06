#include <bits/stdc++.h>
using namespace std;

int N, W, py[1004], px[1004], dp[1004][1004], y, x;

int d(int first, int second) {
    int ret = abs(py[first] - py[second]) + abs(px[first] - px[second]);
    return ret;
}

int go(int first, int second) {
    if(first == W + 1 || second == W + 1)return 0;
    int &ret = dp[first][second];
    if(ret) return ret;
    int next = max(first, second) + 1;
    ret = min(go(next, second) + d(first, next), go(first, next) + d(second, next));
    return ret;
}

void solve() {
    int first = 0, second = 1;
    for(int i=2; i<W+2; i++){
        int next = max(first, second) + 1;
        if(dp[i][second] + d(i, first) < dp[first][i] + d(second, i)){
            cout << 1 << '\n';
            first = i;
        }else {
            cout << 2 << '\n';
            second = i;
        }
    }
}

int main()
{
    cin >> N >> W;
    for(int i=2; i<W+2; i++){
        cin >> y >> x;
        py[i] = y;
        px[i] = x;
    }
    py[0] = 1; px[0] = 1;
    py[1] = N; px[1] = N;

    cout << go(0,1) << '\n';
    solve();

    return 0;
}
