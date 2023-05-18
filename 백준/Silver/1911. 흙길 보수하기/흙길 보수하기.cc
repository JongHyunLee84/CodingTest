#include <bits/stdc++.h>
using namespace std;

int n, l, cnt, nul=-1;

int main()
{
    cin >> n >> l;
    vector<pair<int, int>> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    for(auto i : v){
        if(i.first>nul){
            nul = i.first + l - 1 ;
            cnt ++;
        }
        if(i.second - 1 > nul) {
            while(nul < i.second - 1){
                nul += l;
                cnt ++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
