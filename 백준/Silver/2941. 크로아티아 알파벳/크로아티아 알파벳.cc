#include <bits/stdc++.h>
using namespace std;

string s;
int ret, i;

int main()
{
    cin >> s;
    int idx = s.size();
    s += "  ";
    while(i < idx) {
        // cout << i << '\n';
        if(s[i] == 'c' && s[i+1] == '=' || s[i+1] == '-'){
                i += 2;
                ret++;
        }else if(s[i] == 'd'){
            if(s[i+1] == '-'){
                i += 2;
                ret ++;
            }else if(s[i+1] == 'z' && s[i+2] == '='){
                i += 3;
                ret ++;
            }else {
                i++;
                ret++;
            }
        }else if(s[i] == 'l' && s[i+1] == 'j'){
            i += 2;
            ret ++;
        }else if(s[i] == 'n' && s[i+1] == 'j'){
            i += 2;
            ret ++;
        }else if(s[i] == 's' && s[i+1] == '='){
            i += 2;
            ret ++;
        }else if(s[i] == 'z' && s[i+1] == '='){
            i += 2;
            ret ++;
        }else {
            ret ++;
            i++;
        }
    }
    cout << ret;
    return 0;
}
