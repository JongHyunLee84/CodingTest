#include <bits/stdc++.h>
using namespace std;

string s;
int ret, i, n;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        vector<char> v;
        char now = s[0];
        v.push_back(s[0]);
        bool isAgain = 0;
        for(int i=0; i<s.size(); i++){
            if(now == s[i])v.push_back(now);
            else {
                if(find(v.begin(), v.end(), s[i]) != v.end()){
                    isAgain = 1;
                    break;
                }else {
                    v.push_back(s[i]);
                    now = s[i];
                }
            }
        }
        if(isAgain != 1)ret ++;
    }
    cout << ret;
    return 0;
}
