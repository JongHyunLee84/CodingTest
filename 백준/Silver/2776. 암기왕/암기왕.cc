#include <bits/stdc++.h>
using namespace std;

int t, n, m, temp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> vn(n);
        for(int i=0; i<n; i++)cin >> vn[i];
        sort(vn.begin(),vn.end());
        cin >> m;
        for(int i=0; i<m; i++){
            cin >> temp;
            int l = 0, r = n-1, mid, ret = 0;
            while(l <= r){
                mid = (l+r)/2;
                if(vn[mid] == temp){
                    ret = 1;
                    break;
                }else if(vn[mid] > temp)r = mid-1;
                else l = mid + 1;
            }
            cout << ret << '\n';
        }

    }

    return 0;
}
