#include <bits/stdc++.h>
using namespace std;

string s;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    while(1){
        getline(cin, s);
        if(s == ".")break;
        stack<char> q;
        bool isNo = 0;
        for(char i : s){
            // cout << i << ' ';
            if(i == '(' || i == '[')q.push(i);
            else if(i == ')'){
                if(q.size() && q.top() == '(')q.pop();
                else {
                    isNo = 1;
                    break;
                }
            }
            else if(i == ']'){
                if(q.size() && q.top() == '[')q.pop();
                else {
                    isNo = 1;
                    break;
                }
            } 
        }
        if(isNo || q.size())cout << "no" << '\n';
        else cout << "yes" << '\n';
    }
    
    
    return 0;
}
