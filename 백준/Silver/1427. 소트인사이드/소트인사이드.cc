#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    
    cin >> s;
    for(char i : s){
        v.push_back(i - '0');
    }
    sort(v.begin(), v.end());
    for(int i = v.size()-1; i >=0; i--)cout << v[i];
    
    return 0;
}
