/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

string s;
int a, n, ret;



int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a; 
        int q, d, ni, p;
        int temp = 0;
        q = a / 25;
        a -= q * 25;
        d = a / 10;
        a -= d * 10;
        ni = a / 5;
        a -= ni * 5;
        p = a / 1;
        cout << q << ' ' << d << ' ' << ni << ' ' << p << '\n';
    }
    return 0;
}
