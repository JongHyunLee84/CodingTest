#include <bits/stdc++.h>
using namespace std;

long long a, b, c;
int main()
{
cin >> a >> b >> c;
int d = a*60+b+c;

if(d/60 > 23){
    cout << (d / 60) - 24 << ' ' << d % 60;
    return 0;
}
cout << d / 60 << ' ' << d % 60;
return 0;
}
