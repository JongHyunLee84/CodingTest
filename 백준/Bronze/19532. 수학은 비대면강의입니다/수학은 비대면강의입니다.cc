#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, c, d, e, f;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> a >> b >> c >> d >> e >> f;
    for(int i=-999; i<=999; i++){
        for(int j=-999; j<=999; j++){
            if(a*i + b*j == c && d*i + e*j == f){
                cout << i << ' ' << j << '\n';
                return 0;
            }
        }
    }
    return 0;
}


