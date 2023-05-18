#include <bits/stdc++.h>
using namespace std;

int n, l, cnt, nul=-1;
vector<pair<int, int>> v;
int ca, cb;
int main()
{
    cin >> n >> l;
    for(int i=0; i<n; i++){
        cin >> ca >> cb;
        v.push_back({ca, cb});
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
