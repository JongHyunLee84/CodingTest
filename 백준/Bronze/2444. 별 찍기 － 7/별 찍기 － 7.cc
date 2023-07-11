#include <bits/stdc++.h>
using namespace std;

int n, ret, a, b, c, d, e, f;
string s;

map<char, int> mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    a = 1;
    for(int i=1; i<=n-1; i++){
        for(int j=0; j<((n*2-1)-a)/2; j++)cout << ' ';
        for(int k=0; k<a; k++)cout << '*';
        a += 2;
        cout << '\n';
    }
    for(int i=1; i<=n*2-1; i++)cout << '*';
    cout << '\n';
    a -= 2;
    for(int i=1; i<=n-1; i++){
        for(int j=0; j<((n*2-1)-a)/2; j++)cout << ' ';
        for(int k=0; k<a; k++)cout << '*';
        a -= 2;
        cout << '\n';
    }   
    return 0;
}
