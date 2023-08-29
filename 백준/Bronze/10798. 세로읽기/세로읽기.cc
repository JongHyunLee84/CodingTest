#include <bits/stdc++.h>
using namespace std;

char ar[5][16], temp;
string s, ret;
int main()
{
    for(int i=0; i<5; i++){
        cin >> s;
        for(int j=0; j<s.size(); j++){
            ar[i][j] = s[j];
        }
    }
    for(int i=0; i<15; i++){
        for(int j=0; j<5; j++){
            if(ar[j][i] != NULL)ret += ar[j][i];
        }
    }
    cout << ret << '\n';
    return 0;
}
