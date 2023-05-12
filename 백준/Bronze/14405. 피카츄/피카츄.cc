#include <bits/stdc++.h>
using namespace std;

string s;
bool isYes = 1;
int main(){
    cin >> s;
    int ss = s.size();
    int cnt =0;
    for(int i=0; i<s.size(); i++){
        
        if(s[i] == 'p'){
            if(i <= ss-2 && s[i+1] == 'i'){
                cnt += 2;
                continue;
            }
            else {
                isYes = 0;
                break;
            }
        }
        if(s[i] == 'k'){
            if(i <= ss-2 && s[i+1] == 'a'){
                cnt += 2;
                continue;
            }
            else {
                isYes = 0;
                break;
            }
        }
        if(s[i] == 'c'){
            if(i <= ss-3 && s[i+1] == 'h' && s[i+2] == 'u'){
                cnt += 3;
                continue;
            }
            else {
                isYes = 0;
                break;
            }
        }
    }
    if(isYes && ss == cnt)cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return 0;
}
