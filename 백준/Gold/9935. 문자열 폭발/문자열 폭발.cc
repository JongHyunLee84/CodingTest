#include <bits/stdc++.h>
using namespace std;

string s, bom, ret;

int main() {
        cin >> s >> bom;
        for(int i=0; i<s.size(); i++){
            ret += s[i];
            if(ret.size() >= bom.size() && ret.substr(ret.size() - bom.size(), bom.size()) == bom){
                ret.erase(ret.end()-bom.size(), ret.end());   
            }
        }
        if(ret.size())cout << ret << '\n';
        else cout << "FRULA" << '\n';
    return 0;
}