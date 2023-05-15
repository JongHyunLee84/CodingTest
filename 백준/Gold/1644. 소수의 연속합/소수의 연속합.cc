#include <bits/stdc++.h>
using namespace std;

int n, cnt;
bool check[4000004];
vector<int> v;
int main()
{
    cin >> n;
    for(int i=2; i<=n; i++){
        if(check[i])continue;
        for(int j = 2*i; j <= n; j += i){
            check[j] = 1;
        }
    }
    for(int i=2; i<= n; i++) if(check[i] == 0)v.push_back(i);
    // for(int i : v) cout << i << ' ';
    int temp = 0;
    int idx = 0;
    int i = 0;
    while(i < v.size()) {
        temp += v[i];
        // cout << temp << "and" << n << '\n';
        if(temp == n)cnt++, temp = 0, i = ++idx;
        else if(temp > n)i = ++idx, temp=0;
        else i++;
    }
    
    cout << cnt << '\n';
    return 0;
}