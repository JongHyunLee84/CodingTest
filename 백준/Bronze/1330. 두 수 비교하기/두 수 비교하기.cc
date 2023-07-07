#include <bits/stdc++.h>
using namespace std;

long long a, b;
int main()
{
    cin >> a >> b;
    if(a > b)cout << ">";
    else if(a < b)cout << "<";
    else cout << "==";

    return 0;
}
