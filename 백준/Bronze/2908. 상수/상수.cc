#include <bits/stdc++.h>
using namespace std;

int n, ret;
string s, a, b;
char c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
     stoi(a) > stoi(b) ? cout << a : cout << b;
    return 0;
}
