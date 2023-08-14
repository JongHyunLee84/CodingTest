#include <bits/stdc++.h>
using namespace std;

string a, b;

string plus_(string a, string b) {
    reverse(a.begin(),a.end()); reverse(b.begin(),b.end());
    int idx = min(a.size(), b.size());
    string bigger = "";
    if(a.size() > b.size())bigger = a;
    else bigger = b;
    
    string ret = "";
    int p = 0;
    for(int i=0; i<idx; i++){
        int sum = (a[i] - '0') + (b[i] - '0') + p;
        // cout << sum << '\n';
        p = sum / 10;
        ret += (sum % 10) + '0';
        // cout << ret << '\n';
        // cout << p << '\n';
    }
    for(int i=idx; i<bigger.size(); i++){
        int sum = (bigger[i] - '0' + p);
        // cout << bigger[i] << '\n';
        // cout << "p" << p << '\n';
        // cout << sum << '\n';
        p = sum / 10;
        ret += (sum % 10) + '0';
        // cout << "hree" << '\n';
    }
    if(p)ret += p + '0';
    reverse(ret.begin(),ret.end());
    return ret;
}

int main()
{
    cin >> a >> b;
    cout << plus_(a,b) << '\n';
    return 0;
}
