#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, mp, mf, ms, mv, temp, ret = INF;
int ar[19][5];
vector<vector<int>> v, rv[7500];
vector<int> lv;

// bool compare(vector<int> a, vector<int> b){
//     if(a.size() == b.size()) return a > b;
//     else {
//         if(a.size() > b.size()){
//             for(int i=0; i<b.size(); i++){
//                 return a[i] > b[i];
//             }
//         }
//         else if(a.size() < b.size()){
//             for(int i=0; i<a.size(); i++){
//                 return a[i] > b[i];
//             }
//         }
//     }
// }
void combi(int start, vector<int> b) {
    if(b.size() == temp){
        v.push_back(b);
        return;
    }
    
    for(int i=start+1; i<n; i++){
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
}

int main() {
    cin >> n >> mp >> mf >> ms >> mv;
    for(int i=0; i<n; i++){
        cin >> ar[i][0] >> ar[i][1] >> ar[i][2] >> ar[i][3] >> ar[i][4];
    }
    vector<int> b;
    for(int i=1; i<=n; i++){
        temp = i;
        combi(-1,b);
    }
    for(auto i : v){
        int pi = 0, fi = 0, si= 0, vi=0, ci=0;
        vector<int> a;
        for(auto j : i){
            a.push_back(j);
            pi += ar[j][0];
            fi += ar[j][1];
            si += ar[j][2];
            vi += ar[j][3];
            ci += ar[j][4];
        }
        if(pi >= mp && fi >= mf && si >= ms && vi >= mv) {
            // cout<< pi << '.' << fi << '.' << si << '.' << vi << '.' << ci << '\n';
            // for(int i : a) cout << i << ' ';
            // cout << '\n';
            ret = min(ret, ci);
            if(ret == ci)rv[ret].push_back(a);
        }
    }
    // for(auto i:rv[ret]){
    //     for(auto j:i) cout << j << ' ';
    //     cout << '\n';
    // }
    // sort(lv.begin(), lv.end());
    if(ret > 7500){
        cout << -1 << '\n';
    }else {
        sort(rv[ret].begin(), rv[ret].end());
        cout << ret << '\n';
        for(int i:rv[ret][0]) cout << i+1 << ' ';
    }
    // for(auto i:v) {
    //     for(auto j:i){
    //         cout << j << ' ';
    //     }
    //     cout << '\n';
    // }
    return 0;
}