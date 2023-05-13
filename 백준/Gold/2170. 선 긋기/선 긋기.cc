#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<int, int> v[1000001];
int n;
int ret, from, to;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> from >> to;
        v[i] = {from,to};
    }
    sort(v, v+n);
    from = v[0].first;
    to = v[0].second;
    for(int i=1; i<n; i++){
        if(v[i].first > to){
            ret += to - from;
            from = v[i].first;
            to = v[i].second;
        }else if(v[i].first <= to && v[i].second >= to){
            to = v[i].second;
        }
        // else if(v[i].second > to){
        //     to = v[i].second;
        // }
    }
    ret += to-from;
    cout << ret << '\n';
    return 0;
}
