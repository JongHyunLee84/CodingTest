#include <bits/stdc++.h>
using namespace std;

long long a, b;
int main()
{
cin >> a >> b;
int c = a*60+b;
c -= 45;
if(c < 0){
    cout << 23 << ' ' << b + 15;
    return 0;
}
cout << c / 60 << ' ' << c % 60;
return 0;
}
