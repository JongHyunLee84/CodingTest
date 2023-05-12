#include <bits/stdc++.h>
using namespace std;

int T, n;
string P, s;

int main(){
    cin >> T;
    for(int z=0; z<T; z++){
        cin >> P >> n >> s;
        deque<int> d;
        int temp = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '[' || s[i] == ']')continue;
            else if(s[i] == ',' && temp != 0){
                d.push_back(temp);
                temp=0;
            }
            else temp = temp * 10 + (s[i]-'0');
        }
        if(temp != 0)d.push_back(temp);
        
        bool rev = 0, error = 0;
        for(int i=0; i<P.size(); i++){
            if(P[i]=='R') rev = !rev;
            else {
                if(d.size()==0) {
                    error = 1;
                    break;
                }
                if(rev)d.pop_back();
                else d.pop_front();
            }
        }
        if(rev)reverse(d.begin(), d.end());
        if(error) cout << "error" <<'\n';
        else {
            cout << '[';
            for(int i=0; i<d.size(); i++){
             if(i==d.size()-1)cout << d[i];
             else cout << d[i] << ',';
            }
            cout << ']' << '\n';
        }
    }
    return 0;
}
