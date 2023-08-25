#include <bits/stdc++.h>
using namespace std;

int n, ret = 1e9, mp, mf, ms, mv;
struct Ingre {
    int mp, mf, ms, mv, ci;
};
Ingre ar[19];
vector<vector<int>> total;

int sum_(vector<int> v){
    int result = 0;
    for(int i : v){
        result += ar[i].ci;
    }
    return result;
}

bool check(vector<int> v){
    int tp = 0, tf = 0, ts = 0, tv = 0;
    for(int i : v){
        tp += ar[i].mp; tf += ar[i].mf; ts += ar[i].ms; tv += ar[i].mv;
    }
    if(tp >= mp && tf >= mf && ts >= ms && tv >= mv)return true;
    else return false;
}

void go(int idx, vector<int> v){
    // if(idx > 8) return;
    // cout << idx << ' ' << n << '\n';
    if(idx == n){
        // cout << "30" << '\n';
        if(check(v)){
        int result = sum_(v);
        if(ret > result){
            // cout << result << '\n';
            // for(int i : v)cout << i << ' ';
            // cout << '\n';
            ret = result;
            total.clear();
            total.push_back(v);
        }else if(ret == result){
            total.push_back(v);
        }
        }
        return;
    }
    go(idx+1, v);
    v.push_back(idx);
    go(idx+1, v);
}

int main()
{
    cin >> n >> mp >> mf >> ms >> mv;
    for(int i=0; i<n; i++){
        cin >> ar[i].mp >> ar[i].mf >> ar[i].ms >> ar[i].mv >> ar[i].ci;
    }
    vector<int> v;
    go(0, v);
    // cout << "here" << '\n';
    sort(total.begin(), total.end());
    if(ret == 1e9)cout << -1 << '\n';
    else {
    cout << ret << '\n';
    for(int i : total[0])cout << i+1 << ' ';
    }
    return 0;
}
