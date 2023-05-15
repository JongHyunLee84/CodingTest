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
    int sum = 0;
    int hi = 0;
    int lo = 0;
    while(true) {
        if(sum >= n) sum -= v[lo++];
        else if(hi == v.size())break;
        else sum += v[hi++];
        if(sum == n)cnt++;
    }
    
    cout << cnt << '\n';
    return 0;
}