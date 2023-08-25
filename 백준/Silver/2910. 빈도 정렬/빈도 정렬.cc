#include <bits/stdc++.h>
using namespace std;

int n, c, temp;
map<int,int> mp, mp2;
vector<pair<int,int>> v;

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return mp2[a.second] < mp2[b.second];
    }
    return a.first > b.first;
}

int main()
{
    cin >> n >> c;
    for(int i=0; i<n; i++){
        cin >> temp;
        mp[temp]++;
        if(!mp2[temp])mp2[temp] = i+1;
    }
    for(auto i : mp){
        v.push_back({i.second, i.first});
    }
    sort(v.begin(), v.end(), comp);
    for(auto i : v){
        for(int j = 0; j< i.first; j++){
            cout << i.second << ' ';
        }
    }
    return 0;
}
