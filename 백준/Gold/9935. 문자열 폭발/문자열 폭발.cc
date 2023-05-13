#include <bits/stdc++.h>
using namespace std;
string s, boom, ret;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> s >> boom ;
    int ss = boom.size();
    stack<char> st;
    for(char i : s) {
        st.push(i);
        if(st.size() >= ss && st.top() == boom[ss-1]){
            string temp = "";
            for(auto j : boom)temp+=st.top(), st.pop();
            reverse(temp.begin(),temp.end());
            if(temp != boom){
                for(auto j : temp)st.push(j);
            }
        }
    }
    if(st.size()){
        while(st.size()){
            ret += st.top();
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        cout << ret << '\n';
    }
    else cout << "FRULA" << '\n';
    return 0;
}
