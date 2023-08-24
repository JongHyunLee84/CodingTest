#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<string> v;

bool comp(string a, string b){
    if(a.size() == b.size()){
        return a < b;
    }
    return a.size() < b.size();
}


int main() {
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> s;
            string temp = "";
            for(int j=0; j<s.size(); j++){
                if(s[j] - '0' >= 0 && s[j] -'0' <= 9){
                    if(temp == "0"){
                        temp = "";
                    }
                    temp += s[j];
                }else if(temp != ""){
                    v.push_back(temp);
                    temp = "";
                }
            }
            if(temp.size())v.push_back(temp);
        }
        sort(v.begin(), v.end(), comp);
        for(string i : v)cout << i << '\n';
    return 0;
}