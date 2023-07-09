#include <bits/stdc++.h>
using namespace std;

int a, ar[10004], b, c;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    for(int i=0; i<a; i++)cin>> ar[i];
    
    for(int i=0; i<a; i++)if(b > ar[i])cout<< ar[i] << ' ';
    // cout << c << '\n';
    return 0;
}
