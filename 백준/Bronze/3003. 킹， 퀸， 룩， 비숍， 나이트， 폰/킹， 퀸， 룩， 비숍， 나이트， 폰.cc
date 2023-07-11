#include <bits/stdc++.h>
using namespace std;

int n, ret, a, b, c, d, e, f;
string s;

map<char, int> mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c >> d >> e >> f;
    cout << 1 - a << ' ' << 1 - b << ' ' << 2 - c << ' ' << 2 - d << ' ' << 2 - e << ' ' << 8 - f << '\n';
    return 0;
}
