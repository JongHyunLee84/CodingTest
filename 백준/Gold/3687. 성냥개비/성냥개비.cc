#include <bits/stdc++.h>
using namespace std;

int N, sticks, ar[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
string dp[104], max_str = "111111111111111111111111111111111111111111111111119";

string get_min_str(string a, string b){
    if(a.size() == b.size()) return (a > b ? b : a);
    if(a.size() < b.size())return a;
    else return b;
}

string find_max(int s) {
    string ret = "";
    if(s & 1){
        s -= 3;
        ret += "7";
    }
    while(s){
        ret += "1";
        s -= 2;
    }
    return ret;
}

int main() {
    cin>>N;
    fill(dp, dp + 104, max_str);
    dp[0] = "";
    for(int i=2; i<=100; i++){
        for(int j=0; j<10; j++){
            if(i-ar[j] < 0)continue;
            if(j == 0 && dp[i-ar[j]] == "")continue;
            dp[i] = get_min_str(dp[i], dp[i-ar[j]] + to_string(j));
        }
    }
    for(int i=0; i<N; i++){
        cin >> sticks;
        cout << dp[sticks] << ' ' << find_max(sticks) << '\n';
    }
    return 0;
}
