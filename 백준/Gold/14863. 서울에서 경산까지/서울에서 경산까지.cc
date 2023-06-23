#include <bits/stdc++.h>
using namespace std;

int N, K, lt, lm, ct, cm, ret;
pair<int,int> load[104], cycle[104];
vector<pair<int,int>> v, v2;
void go(int idx,int end ,int sumT, int sumM, vector<pair<int,int>> &v) {
    if(sumT > K)return;
    if(idx == end){
        v.push_back({sumM,sumT});
        return;
    }
    go(idx+1, end, sumT + load[idx].first, sumM + load[idx].second, v);
    go(idx+1, end, sumT + cycle[idx].first, sumM + cycle[idx].second, v);
}

int main()
{
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> lt >> lm >> ct >> cm;
        load[i] = {lt,lm};
        cycle[i] = {ct,cm};
    }
    go(0, N/2, 0, 0, v);
    go(N/2, N, 0, 0, v2);
    // int endPoint = N % 2 != 0 ? N / 2 + 1 : N / 2;
    // for(int i=0; i<N/2; i++){
    //     cout << v[i].first << ' ' << v[i].second;
        
    // }
    // cout << '\n';
    // for(int i=0; i<endPoint; i++) {
    //     cout << v2[i].first << ' ' << v2[i].second << ' ';
    // }
    // cout << "end" << '\n';
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v2.size(); j++){
            if( (v[i].second + v2[j].second) <= K ){
                
            ret = max(ret, v[i].first + v2[j].first);
        }
        }

    }
    cout << ret << '\n';
    return 0;
}
