#include <bits/stdc++.h>
using namespace std;

int n, ret = 2;

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        ret = ret * 2 - 1;
    }
    cout << ret * ret << '\n';
    return 0;
}

// 1 -> 3
// 2 -> 5
// 3 -> 9
// 4 -> 17
// 5 -> 33