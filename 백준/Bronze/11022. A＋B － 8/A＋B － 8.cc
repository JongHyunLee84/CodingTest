#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> a;
    for(int i=1; i<=a; i++){
        cin >> b >> c;
        cout << "Case #" << i << ": " << b << " + " << c << " = " << b + c << '\n';
    }

    return 0;
}
