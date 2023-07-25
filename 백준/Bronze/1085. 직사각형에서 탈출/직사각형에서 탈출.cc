#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main()
{
    cin >> a >> b >> c >> d;
    c -= a;
    d -= b;
    cout << min({a, b, c, d});

    return 0;
}
