#include <bits/stdc++.h>
using namespace std; 
const int INF = 987654321; 
int dp[2504][2504], dp2[2504]; 
string s;  

int go(int here){
    // cout << "here" << '\n';
    if(here == s.size())return 0;
    if(dp2[here] != INF)return dp2[here];
    int &ret = dp2[here];
    for(int i = 0; here + i < s.size(); i++){
        if(dp[here][i]) ret = min(ret, go(here+i+1)+1);
    }
    return ret;
}

int main() {
    cin >> s;
    for(int i=0; i<s.size(); i++)dp[i][0] = 1;
    for(int i=0; i<s.size()-1; i++){
        if(s[i] == s[i+1])dp[i][1] = 1;
    }
    for(int i=2; i<s.size(); i++){
        for(int j=0; j<s.size()-i; j++){
            if(s[j] == s[j+i] && dp[j+1][i-2])dp[j][i] = 1;
        }
    }
    fill(dp2, dp2 + 2504, INF);
    cout << go(0);
    return 0;
} 
