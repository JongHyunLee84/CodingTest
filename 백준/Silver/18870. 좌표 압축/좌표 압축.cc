#include <bits/stdc++.h>
using namespace std;

int n, temp, ar[1000004];
set<int> s;
map<int, int> mp;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        ar[i] = temp;
        s.insert(temp);
    }
    int index = 0;
    for(auto i : s){
        mp[i] = index;
        index++;
    }
    for(int i=0; i<n; i++)cout << mp[ar[i]] << ' ';
    return 0;
}
