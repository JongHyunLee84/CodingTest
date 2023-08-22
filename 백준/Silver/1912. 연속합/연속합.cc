#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ret = -1e9, temp, sum = -1e9;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        if(sum + temp > 0 && sum + temp > temp)sum += temp;
        else if(sum <= temp)sum = temp;
        else sum = -1e9;
        ret = max(ret, sum);
    }
    cout << ret << '\n';
    return 0;
}
