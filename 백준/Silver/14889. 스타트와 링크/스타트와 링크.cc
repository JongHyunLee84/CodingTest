#include <bits/stdc++.h>
using namespace std;

int n, ar[24][24], ret = 1e9;
vector<vector<int>> v;

void combi(int idx, vector<int> vv){
    if(vv.size() == n/2){
        v.push_back(vv);
        // for(int i:vv)cout << i << ' ';
        // cout << '\n';
        return;
    }
    for(int i=idx+1; i<n; i++){
        vv.push_back(i);
        combi(i, vv);
        vv.pop_back();
    }
}

void compare(vector<int> vv){
    int sum1= 0, sum2 = 0;
    vector<int> against;
    for(int i=0; i<n; i++){
        if(find(vv.begin(), vv.end(), i) == vv.end())against.push_back(i);
    }
    
    // for(int i : vv)cout << i << ' ';
    // cout << '\n';

    for(int i=0; i<vv.size(); i++){
        for(int j=0; j<vv.size(); j++){
            if(i == j)continue;
            sum1 += ar[vv[i]][vv[j]];
        }
    }
    
    // cout << "sum1 : " << sum1 << '\n';
    
    // for(int i : against)cout << i << ' ';
    // cout << '\n';
    for(int i=0; i<vv.size(); i++){
        for(int j=0; j<vv.size(); j++){
            if(i == j)continue;
            sum2 += ar[against[i]][against[j]];
        }
    }
    // cout << "sum2 : " << sum2 << '\n';
    ret = min(ret, abs(sum2-sum1));
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> ar[i][j];
        }
    }
    vector<int> vv;
    combi(-1, vv);
    for(int i=0; i<v.size(); i++){
        compare(v[i]);
    }
    cout << ret << '\n';
    return 0;
}
