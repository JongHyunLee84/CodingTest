#include <bits/stdc++.h>
using namespace std;

int N, dp[1004][1004], a, b, c, visited[54];
struct Quest {
  int str, intel, pnt;  
};
Quest ar[54];

int go(int str, int intel) {
    // cout << str << ' ' << intel << '\n';
    int &ret = dp[str][intel];
    if(ret != -1)return ret;
    ret = 0;
    int pnt = 0;
    vector<int> v;
    for(int i=0; i<N; i++){
        if(ar[i].str <= str || ar[i].intel <= intel){
            ret++;
            if(!visited[i]){
                visited[i] = 1;
                pnt += ar[i].pnt;
                v.push_back(i);
            }
        }
    }
    
    for(int p=0; p<=pnt; p++){
        int nextStr = min(1000, str + p);
        int nextInt = min(1000, intel + pnt - p);
        ret = max(ret, go(nextStr, nextInt));
    }
    for(int i : v)
        visited[i] = false;
    return ret;
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> a >> b >> c;
        ar[i] = {a,b,c};
    }
    memset(dp, -1, sizeof(dp));
    cout << go(1, 1);
    return 0;
}
