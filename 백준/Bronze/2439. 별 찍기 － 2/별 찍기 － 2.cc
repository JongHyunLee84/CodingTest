#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> a;
    for(int i=1; i<=a; i++){
        for(int j=0; j<a-i; j++){
            cout << " ";
        }
        for(int k=1; k<=i; k++){
            cout << "*";
        }
        cout << '\n';
    }

    return 0;
}
