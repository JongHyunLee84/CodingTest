#include <bits/stdc++.h>
using namespace std;

int n, ret, a, b, c, d, e, f;
string s;
map<int, int> mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    for(char i : s)mp[tolower(i)]++;
    for(int i=97; i<=122; i++){
        if(mp[i] > a){
            a = mp[i];
            c = i;
            b = 1;
        }else if(mp[i] == a && a != 0){
            b++;
        }
    }
    if(b > 1)cout << '?' <<'\n';
    else cout << (char)toupper(char(c)) << '\n';
    return 0;
}
