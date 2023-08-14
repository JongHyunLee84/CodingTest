#include <bits/stdc++.h>
using namespace std;

int n, root, eli, temp, ret, visited[54];
vector<vector<int>> v(54);

int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        if(temp == -1){
        root = i;
        continue;
        }
        v[temp].push_back(i);
    }
    cin >> eli;
    queue<int> q;
    q.push(root);
    while(q.size()){
        int idx = q.front(); q.pop();
        visited[idx] = 1;
        if(idx == eli || find(v[eli].begin(), v[eli].end(), idx) != v[eli].end()){
            continue;
        }
        int isLeap = 0;
        for(int i : v[idx]){
            if(visited[i] || i == eli)continue;
            if(v[i].size()){
                q.push(i);
                isLeap = 1;
            }
            else {
                ret++;
                isLeap = 1;
            }
        }
        if(!isLeap)ret++;
    }
    cout << ret << '\n';
    return 0;
}
