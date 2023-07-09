#include <bits/stdc++.h>
using namespace std;

int a, ar[104], b, c;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> a;
    for(int i=0; i<a; i++)cin>> ar[i];
    cin >> b;
    for(int i=0; i<a; i++)if(b == ar[i])c++;
    cout << c << '\n';
    return 0;
}
