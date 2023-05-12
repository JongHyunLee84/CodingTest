#include <bits/stdc++.h>
using namespace std;

int n, visited[200001], cnt, ret;
stack<int> st;
string s;
int main(){
    cin >> n >> s;
    for(int i=0; i<n; i++){
        if(s[i] == '(')st.push(i);
        else {
            if(st.size()){
                visited[st.top()] =1;
                visited[i] =1;
                st.pop();
            }
        }
    }
    for(int i=0; i<n; i++){
        if(visited[i])cnt++;
        else {
            ret = max(ret, cnt);
            cnt = 0;
        }
    }
    ret = max(ret,cnt);
    cout << ret << '\n';
    
    return 0;
}
