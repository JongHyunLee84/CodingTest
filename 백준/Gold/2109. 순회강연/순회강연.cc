#include <bits/stdc++.h>
using namespace std;

int n, a, b, max_d, ret, visited[10004];
vector<pair<int,int>> v;

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }return a.first > b.first;
}

int main()
{
    cin >> n; 
    for(int i=0; i<n; i++){
        cin >> a >> b;
        max_d = max(max_d, b);
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), comp);
    for(int i=0; i<n; i++){
        if(!visited[v[i].second])visited[v[i].second] = v[i].first;
        else {
            for(int j=v[i].second; j >= 1; j--){
                if(!visited[j]){visited[j] = v[i].first; break;}
            }
        }
    }
    for(int i=1; i<=max_d; i++){
        ret += visited[i];
        // cout << visited[i] << ' ';
    }
    cout << ret << '\n';
    return 0;
}
