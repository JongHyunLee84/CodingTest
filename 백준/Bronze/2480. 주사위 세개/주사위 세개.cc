#include <bits/stdc++.h>
using namespace std;

long long a, b, c;
int main()
{
cin >> a >> b >> c;

if(a == b && b == c)cout<<10000+a*1000;
else if(a == b || a == c)cout << 1000+a*100;
else if(b == c)cout<< 1000+b*100;
else cout << max({a,b,c})*100;
return 0;
}
