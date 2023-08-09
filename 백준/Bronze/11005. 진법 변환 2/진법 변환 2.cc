#include <bits/stdc++.h>
using namespace std;

int n, b;
string s;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> b;
    while(n != 0){
        int mod = n % b;
        if(mod >= 10)s += 'A' + (mod - 10);
        else s += mod + '0';
        n /= b;
    }
    reverse(s.begin(), s.end());
    if(s[0] == '0')for(int i=1; i<s.size(); i++)cout<<s[i];
    else cout << s << '\n';
    return 0;
}
