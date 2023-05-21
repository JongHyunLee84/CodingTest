#include <bits/stdc++.h>
using namespace std;
const int INF = -987654321;
int n, ret = INF, temp, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=1; i<= n; i++){
        cin >> temp;
        sum += temp;
        ret = max(ret, sum);
        if(sum < 0) sum = 0;
    }
    cout << ret << '\n';
    return 0;
}