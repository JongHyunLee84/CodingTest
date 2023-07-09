#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> a;
    for(int i=0; i<a; i++){
        cin >> b >> c;
        cout << b + c << '\n';
    }

    return 0;
}
