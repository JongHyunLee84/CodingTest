#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a1, a0, c, n0, ret = 1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> a1 >> a0 >> c >> n0;
    for(int i=n0; i<=100; i++){
        if(a1 * i + a0 > c * i)ret = 0;
    }

    cout << ret << '\n';

    return 0;
}


