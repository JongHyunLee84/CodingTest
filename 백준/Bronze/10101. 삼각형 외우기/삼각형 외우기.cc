#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, c;
map<int, int> mp1, mp2;
int main()
{
    cin >> a >> b >> c;
    if(a == 60 && b == 60 && c == 60)cout << "Equilateral" << '\n';
    else if(a + b + c == 180 && a == b || a == c || b == c)cout << "Isosceles" << '\n';
    else if(a + b + c == 180 && a != b && a != c && b != c)cout << "Scalene" << '\n';
    else cout << "Error" << '\n';
    return 0;
}
