#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
map<int, int> mp1, mp2;
int main()
{
    for(int i=0; i<3; i++){
        cin >> a >> b;
        mp1[a]++; mp2[b]++;
    }
    for(int i=1; i<=1000; i++){
        if(mp1[i] == 1)c = i;
        if(mp2[i] == 1)d = i;
    }
    cout << c << ' ' << d << '\n';

    return 0;
}
