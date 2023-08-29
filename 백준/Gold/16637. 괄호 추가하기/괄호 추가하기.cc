#include <bits/stdc++.h>
using namespace std;

vector<int> numV;
vector<char> operV;
string s;
int n, ret = -1e9;

int cal(int a, int b, char oper){
    if(oper == '+')return a + b;
    else if(oper == '-')return a - b;
    else return a * b;
}

void go(int idx, int now){
    // cout << idx << ' ' << now << '\n';
    if(idx == operV.size()){
        ret = max(ret, now);
        return;
    }
    
    go(idx+1, cal(now, numV[idx+1], operV[idx]));
    if(idx+2 < numV.size())go(idx+2, cal(now, cal(numV[idx+1], numV[idx+2], operV[idx+1]) ,  operV[idx]));
    
}

int main()
{
    cin >> n >> s;
    for(int i=0; i<s.size(); i++){
        // cout << i << ' ';
        if(i%2){
            operV.push_back(s[i]);
            // cout << s[i] << '\n';
        }
        else {
            numV.push_back(s[i]-'0');
            // cout << s[i] - '0' << '\n';   
        }
    }
    // for(int i : numV)cout << i << ' ';
    // cout << '\n';
    // for(char i : operV)cout << i << ' ';
    go(0, numV[0]);
    cout << ret << '\n';
    return 0;
}
