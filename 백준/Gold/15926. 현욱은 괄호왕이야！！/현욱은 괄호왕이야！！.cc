#include <bits/stdc++.h>
using namespace std;

int n, ar[200004], ret, cnt;
string s;
stack<int> st;
int main() {
    cin >> n >> s;
    for(int i=0; i<n; i++){
        if(s[i] == '(')st.push(i);
        else if(st.size()){
            ar[i] = ar[st.top()] = 1;
            st.pop();
        }
    }
    for(int i=0; i<n; i++){
        if(ar[i]){
            cnt++;
        }else {
            cnt = 0;
        }
        ret = max(ret, cnt);
    }
    cout << ret << "\n";
    return 0;
}

