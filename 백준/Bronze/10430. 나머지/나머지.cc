#include <bits/stdc++.h>
using namespace std;

int A, B, C; 

int main()
{
    cin >> A >> B >> C;
    cout <<  (A+B)%C << ' ' << ((A%C) + (B%C))%C << ' ' << (A*B)%C << ' ' << ((A%C) * (B%C))%C;

    return 0;
}
