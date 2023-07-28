#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
string s;
map<string, int> mp;
set<string> ss;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    for(int i=0; i<s.size(); i++){
        string temp = "";
        for(int j=i; j<s.size(); j++){
            temp += s[j];
            ss.insert(temp);
        }
    }
    cout << ss.size();
 
    return 0;
}
