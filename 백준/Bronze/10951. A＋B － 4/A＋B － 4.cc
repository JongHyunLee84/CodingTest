#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    while(getline(cin, s)){
        int a = s[0] - '0', b = s[2] - '0';
        cout << a + b << '\n';
    }
    return 0;
}
