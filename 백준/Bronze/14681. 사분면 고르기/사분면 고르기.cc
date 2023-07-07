#include <bits/stdc++.h>
using namespace std;

long long a, b;
int main()
{
    cin >> a >> b;
    if(a >= 1 && b >= 1) cout << 1;
    else if(a >= 1 && b <= -1)cout << 4;
    else if(a <= -1 && b <= -1)cout << 3;
    else cout << 2;
    return 0;
}
