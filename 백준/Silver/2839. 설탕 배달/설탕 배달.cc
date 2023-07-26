#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ret = 1e9;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int max_big = n / 5;
    for(int i=max_big; i>=0; i--){
        int sum = 0;
        if((n - i*5) % 3 == 0){
            sum += i;
            sum += (n - i*5) / 3;
            ret = min(ret, sum);
        }
    }
    if(ret != 1e9)cout << ret << '\n';
    else cout << -1 << '\n';
    return 0;
}


