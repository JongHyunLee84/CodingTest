#include <bits/stdc++.h>
using namespace std;

int n, ar[70][70];
string s;
string go(int y, int x, int idx){
    // cout << y << x << idx << '\n';
    string s = "";
    if(idx == 1){
        return to_string(ar[y][x]);
    }
    s += go(y, x, idx/2);
    s += go(y, x+idx/2, idx/2);
    s += go(y+idx/2, x, idx/2);
    s += go(y+idx/2, x+idx/2, idx/2);
    if(s == "1111")return "1";
    else if(s == "0000")return "0";
    else return "(" + s + ")";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<n; j++){
            ar[i][j] = s[j] - '0';
        }
    }
    cout << go(0, 0, n) << '\n';
    return 0;
}
