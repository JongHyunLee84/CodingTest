#include <bits/stdc++.h>
using namespace std;
string s, boom, ret;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> s >> boom ;
    int ss = boom.size();
    for(int i=0; i<s.size(); i++){
        ret += s[i];
        if(ret.size()>=ss){
            if(ret.substr(ret.size()-ss,ss) == boom){
                ret.erase(ret.size()-ss,ss);
            }
        }
    }
    if(ret.size())cout << ret << '\n';
    else cout << "FRULA" << '\n';
    return 0;
}
