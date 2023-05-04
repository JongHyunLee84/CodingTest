#include <bits/stdc++.h>
using namespace std;  

int n, max_sum = -987654321;
string s;
vector<int> num_v;
vector<char> oper_v;

int calculate(int num, char oper, int nextNum){
    if(oper == '+')return num + nextNum;
    else if(oper == '*')return num * nextNum;
    else return num - nextNum;
}

void go(int idx, int sum) {
    // cout << idx << '\n';
    if(idx == num_v.size()-1){
        max_sum = max(sum, max_sum);
        return;
    }
    go(idx + 1,calculate(sum,oper_v[idx],num_v[idx + 1]));
    
    if(idx + 2 <= num_v.size() - 1){
        int temp = calculate(num_v[idx+1],oper_v[idx+1],num_v[idx + 2]);
        go(idx + 2, calculate(sum, oper_v[idx], temp));
    }
    return;
}

int main() {
    cin >> n >> s;
    for(int i=0; i<s.size(); i++){
        if(i % 2 == 0)num_v.push_back(s[i] - '0');
        else oper_v.push_back(s[i]);
    }
    // cout << num_v.size();
    // for(auto i : oper_v)cout << i << ' ';
    // cout << '\n';
    // for(auto i : num_v) cout << i << ' ';
    go(0, num_v[0]);
    cout << max_sum << '\n';
    return 0;
}
