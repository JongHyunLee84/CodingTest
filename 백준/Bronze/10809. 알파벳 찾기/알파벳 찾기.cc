#include <iostream>
using namespace std;

int n, ret;
string s;
char c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    for(int i=0; i<26; i++){
        int is = 0;
        for(int j=0; j<s.size(); j++){
            // cout << i << u_char(i+'a') << ' ' << s[j] - 'a' << s[j] << '\n';
            if(i == s[j] - 'a'){
                cout << j << '\n';
                is = 1;
                break;
            }
        }
        if(is == 0)cout << "-1" << '\n';
    }
    
    return 0;
}
