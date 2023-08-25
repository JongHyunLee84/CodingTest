#include <bits/stdc++.h>
using namespace std;

int a, b, v;

int main()
{
    cin >> a >> b >> v;
    if(a >= v){
        cout << 1 << '\n';
        return 0;
    }
    int c = v - a;
    int d = a - b;
    int e = c % d == 0 ? c / d : c / d + 1;
    cout << e + 1;
    return 0;
}
