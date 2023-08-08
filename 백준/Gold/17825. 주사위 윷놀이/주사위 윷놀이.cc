#include <bits/stdc++.h>
using namespace std;

int horse[14], ar[54], mal[4];
vector<int> v[54];

void makeScore() {
    for(int i=1; i<=20; i++){
        ar[i] = i * 2;
    }
    ar[21] = 13; ar[22] = 16; ar[23] = 19;
    ar[24] = 22; ar[25] = 24; 
    ar[26] = 28; ar[27] = 27; ar[28] = 26;
    ar[29] = 25; ar[30] = 30; ar[31] = 35;
    
    for(int i=0; i<20; i++){
        v[i].push_back(i+1);
    }
    v[20].push_back(32); 
    v[5].push_back(21); v[21].push_back(22); v[22].push_back(23); v[23].push_back(29);
    v[10].push_back(24); v[24].push_back(25); v[25].push_back(29);
    v[15].push_back(26); v[26].push_back(27); v[27].push_back(28); v[28].push_back(29);
    v[29].push_back(30); v[30].push_back(31); v[31].push_back(20);
}

bool isMal(int mal_idx, int idx){
    // cout << mal_idx << ' ' << idx << '\n';
    if(mal_idx == 32)return false;
    for(int i=0; i<4; i++){
        if(i == idx) continue;
        if(mal[i] == mal_idx) return true;
    }
    return false;
}

int move(int here, int cnt){
    if(here == 32)return 32;
    if(v[here].size() >= 2){
        here = v[here][1]; cnt--;
    }
    if(cnt){
        queue<int> q;
        q.push(here);
        int there;
        while(q.size()) {
            int x = q.front(); q.pop();
            there = v[x][0];
            q.push(there);
            // cout <<"there " << there << '\n';
            if(there == 32)break;
            cnt --;
            if(cnt == 0)break;
        }
        return there;
    }else return here;
}

int go(int idx){
    // cout << idx << '\n';
    if(idx == 10)return 0;
    int ret = 0;
    for(int i=0; i<4; i++){
        // cout << ret << '\n';
        // cout << idx << '\n';
        int temp_idx = mal[i];
        // cout << "temp_idx " <<temp_idx << '\n';
        int mal_idx = move(temp_idx, horse[idx]);
        // cout << "mal_idx " << mal_idx  << "horse[idx] " << horse[idx] << '\n';
        if(isMal(mal_idx,i))continue;
        mal[i] = mal_idx;
        ret = max(ret, go(idx+1)+ar[mal_idx]);
        mal[i] = temp_idx;
    }
    return ret;
}

int main()
{
    makeScore();
    for(int i=0; i<10; i++){
        cin >> horse[i];
    }
    cout << go(0) << '\n';
    return 0;
}
