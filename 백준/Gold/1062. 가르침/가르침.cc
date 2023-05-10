#include <bits/stdc++.h>
using namespace std;

int n, k, ret;
string ar[54];
vector<char> v;

void combi(int start, vector<char> v){
    if(ret == n) return;
    if(v.size() == k){
        int cnt = 0;
        for(int i=0; i<n; i++){
            bool isHave = 1;
            for(char j : ar[i]){
                if(find(v.begin(), v.end(), j) == v.end()){
                    isHave = 0;
                    break;
                }
            }
            if(isHave)cnt++;
        }
        ret = max(cnt, ret);
    }
    
    for(int i=start+1; i<26; i++){
        if(find(v.begin(), v.end(), (char)i+'a')!=v.end())continue;
        v.push_back((char)i+'a');
        combi(i, v);
        v.pop_back();
    }
}

int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    if(k < 5) {
        cout << 0 << '\n';
        return 0;
    }
    v = {'a','n','t','i','c'};
    combi(-1, v);
    cout << ret << '\n';
    return 0;
}

