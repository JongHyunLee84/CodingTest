#include <bits/stdc++.h>
using namespace std;

int a, ar[10004], b, c, temp = 1;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // cin >> a;
    for(int i=1; i<=9; i++){
        cin >>a;
        if(b < a){
            b = a;
            c = i;
        }
    }
    cout << b << ' ' << c << '\n';
    // cout << c << '\n';
    return 0;
}
