#include <bits/stdc++.h>
using namespace std;

int n, ar[1004], len, temp;

int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        auto lowerPos = lower_bound(ar, ar+len, temp);
        if(*lowerPos == 0)len++;
        *lowerPos = temp;
    }
    cout << len << '\n';
    return 0;
}
