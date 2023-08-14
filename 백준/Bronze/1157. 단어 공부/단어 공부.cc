#include <bits/stdc++.h>
using namespace std;

int ret;
string s;
map<int, int> m;
vector<int> v;
int main()
{
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(s[i] >= 65 && 97 > s[i]){
            m[s[i] - 'A']++;
        }else {
            int temp = s[i] - 97;
            m[temp]++;
        }
    }
    for(int i=0; i<26; i++){
        ret = max(ret, m[i]);
    }
    for(int i=0; i<26; i++){
        if(m[i] == ret)v.push_back(i);
    }
    if(v.size() > 1)cout << '?' << '\n';
    else cout << (char)(v[0] + 'A') << '\n';
    return 0;
}
