#include <bits/stdc++.h>
using namespace std;

int n, a, b;
string s;
vector<string> v;

bool comp(string s1, string s2){
    if(s1.size() == s2.size())return s1 < s2;
    return s1.size() < s2.size();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        if(find(v.begin(), v.end(), s) == v.end()){
            v.push_back(s);
        }
    }
    sort(v.begin(), v.end(), comp);
    for(auto i : v)cout << i << '\n';
    return 0;
}
