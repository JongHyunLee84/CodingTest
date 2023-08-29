#include <bits/stdc++.h>
using namespace std;

int cnt;
string s;

int main()
{
    getline(cin, s);
    if(s[0] == ' ')cnt--;
    if(s[s.size()-1] == ' ')cnt--;
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' ')cnt++;
    }
    cout << cnt+1 << '\n';
    

    return 0;
}
