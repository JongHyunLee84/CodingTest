#include <iostream>
using namespace std;

int n, ret;
string s;
char c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    getline(cin, s);
    for(int i=0; i<s.size(); i++){
        if(s[i] != ' '){
            n++;
            // cout << "hre";
        }
        else if(s[i] == ' '  && n == 0){
            // cout << "zzzzz" << '\n';
            continue;
        }
        else {
            n = 0;
            ret ++;
        }
    }
    if(n != 0)ret++;
    cout << ret << "\n";
    return 0;
}
