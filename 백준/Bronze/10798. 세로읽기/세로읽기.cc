#include <bits/stdc++.h>
using namespace std;
int sz;
string s;
char ar[9][19];

int main()
{
    for(int i=0; i<5; i++){
        cin >> s;
        for(int j=0; j<s.size(); j++){
            ar[i][j] = s[j];
        }
    }
    for(int j=0; j<15; j++){
    for(int i=0; i<5; i++){
        if(ar[i][j] != NULL)cout << ar[i][j];
    }
    }
    return 0;
}
