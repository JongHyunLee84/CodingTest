#include <bits/stdc++.h>
using namespace std;

int n, k, ar[104], visited[104], ret;

int main() {
    cin >> n >> k;
    for(int i=0; i<k; i++){
        cin >> ar[i];
    }
    vector<int> v;
    for(int i=0; i<k; i++){
        // cout << "here" << '\n';
        if(visited[ar[i]])continue;
        else {
            if(v.size() == n){
                int last_idx = 0, pos; 
                for(int now : v){
                    int next_idx = 1e9;
                    for(int j=i+1; j<k; j++){
                        if(now == ar[j]){
                            next_idx = j; break;
                        }
                    }
                    if(last_idx < next_idx){
                        last_idx = next_idx;
                        pos = now;
                    }
                }
                v.erase(find(v.begin(), v.end(), pos));
                // cout << pos << '\n';
                visited[pos] = 0;
                ret++;
            }
            v.push_back(ar[i]);
            visited[ar[i]] = 1;
        }
    }
    cout << ret << '\n';
    return 0;
}

