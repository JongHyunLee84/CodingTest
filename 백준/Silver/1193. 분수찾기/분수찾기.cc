#include <bits/stdc++.h>
using namespace std;

int cnt = 1, n, a, b, m;

int main()
{
    cin >> m;
    while(n < m){
        n += cnt;
        cnt++;
    }
    if(cnt % 2 == 0){
        a = cnt - 1;
        b = 1;
    }else {
        a = 1;
        b = cnt - 1;
    }
    // cout << n - 9 << '\n';
    for(int i=0; i<n-m; i++){
        if(cnt % 2 == 0){
            a--; b++;
        }else {
            a++; b--;
        }
    }
    cout << b << '/' << a << '\n';
    return 0;
}
