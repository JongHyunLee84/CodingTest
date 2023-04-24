#include <bits/stdc++.h>
using namespace std;

int N;
string ret;
map<char, int> m;

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (m.find(s[0]) != m.end()) {
            m[s[0]] += 1;
        } else {
            m.insert({s[0], 1});
        }
    }
    for(auto it : m) {
    if (it.second >= 5) {
        ret += it.first;
    } 
    }
    if (ret == "") {
        cout << "PREDAJA";
    } else {
        cout << ret;
    }
    return 0;
}