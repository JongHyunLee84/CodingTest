#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, x, y, min_x = 1e9, max_x = -1e9, min_y = 1e9, max_y = -1e9;
map<int, int> mp1, mp2;
int main()
{
    cin >> n;
    if(n == 1){
        cout << 0 << '\n';
        return 0;
    }
    for(int i=0; i<n; i++){
        cin >> x >> y;
        min_x = min(min_x, x); max_x = max(max_x, x);
        min_y = min(min_y, y); max_y = max(max_y, y);
    }
    cout << (max_x - min_x) * (max_y - min_y);

    return 0;
}
