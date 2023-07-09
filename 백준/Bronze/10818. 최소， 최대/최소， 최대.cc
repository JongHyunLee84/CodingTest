#include <bits/stdc++.h>
using namespace std;

int a, ar[10004], b = -1e9, c = 1e9, temp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> a;
    for(int i=0; i<a; i++){
        cin >> temp;
        b = max(b, temp);
        c = min(c, temp);
    }
    cout << c << ' ' << b << '\n';
    // cout << c << '\n';
    return 0;
}
