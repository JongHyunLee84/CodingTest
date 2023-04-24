#include <bits/stdc++.h>
using namespace std;

string a;

int main()
{
    cin >> a;
    int z = (int)'z';
    int ia = (int)'a';
    int ar[z - ia + 1];
    for (int i = 0; i < (z - ia + 1); i++)
        ar[i] = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int d = (int)a[i];
        ar[d - 97] += 1;
    }
    for (int v : ar)
        cout << v << ' ';
        return 0;
}