#include <bits/stdc++.h>
using namespace std;

int t, n;
string s, ar;

// deque<int> split(string s, char del){
//     deque<int> de;
    
//     while(1){
//         auto pos = s.find(del);
//         if(pos == string::npos)break;
        
//         int temp = stoi(s.substr(0, pos));
//         de.push_back(temp);
//         s.erase(s.begin(), s.begin() + pos + 1);
//     }
//     if(s.size())de.push_back(stoi(s));
//     // for(int i : li)cout << i << ' ';
//     // cout << '\n';
//     return de;
// }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for(int z=0; z<t; z++){
        cin >> s >> n >> ar; ar.erase(ar.begin()); ar.erase(ar.end()-1);
        int isFront = 1, isBreak = 0;
        
        deque<int> de;
        
        int temp = 0;
        for(int i=0; i<ar.size(); i++){
            if(ar[i] == ',' && temp){
                de.push_back(temp);
                temp = 0;
            }else {
                temp = temp * 10 + (ar[i]-'0');
            }
        }
        if(temp)de.push_back(temp);
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'R')isFront ^= 1;
            else {
                if(!de.size()){
                    isBreak = 1;
                    cout << "error" << '\n';
                    break;
                }
                if(isFront)de.pop_front();
                else de.pop_back();
            }
        }
        if(isBreak) continue;
        if(de.size() == 0){
            cout << "[]" << '\n';
            continue;
        }
        if(isFront){
            cout << '[';
            for(int i=0; i<de.size()-1; i++)cout << de[i] << ',';
            cout << de.back() << ']';
            cout << '\n';
        }else {
            cout << '[';
            for(int i=de.size()-1; i >=1; i--)cout << de[i] << ',';
            cout << de.front() << ']';
            cout << '\n';
        }
    }
    return 0;
}