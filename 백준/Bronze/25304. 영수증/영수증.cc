#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, ret;

int main()
{
    cin >> a >> b;
    for(int i=0; i<b; i++){
        cin >> c >> d;
        ret += c*d;
    }
    
    if(a == ret)cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}
