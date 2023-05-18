#include <bits/stdc++.h>
using namespace std;

int n, l, cnt, nul=-1, a;

int main()
{
    cin >> n >> l;
    vector<pair<int, int>> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    for(auto i : v){
        if(i.second < nul)continue;
        if(i.first > nul) {
            a = (i.second - i.first)/l + ((i.second - i.first) % l ? 1 : 0);
            nul = i.first + l * a;
        } else {
            a = (i.second - nul) / l + ((i.second - nul) % l ? 1 : 0);
            nul = nul + a * l;
        }
        cnt += a;
    }
    cout << cnt << '\n';
    return 0;
}
