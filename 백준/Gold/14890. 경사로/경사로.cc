#include <bits/stdc++.h>
using namespace std;

int n, l, ar[104][104], visited[104], ret;
vector<int> hv, vv;

void count(int idx, char axis){
    int a[104];
    memset(a, 0, sizeof(a));
    memset(visited, 0, sizeof(visited));
    if(axis == 'h')for(int i=0; i<n; i++)a[i] = ar[idx][i];
    else for(int i=0; i<n; i++)a[i] = ar[i][idx];
    int first = a[0];
    int cnt = 1;
    for(int i=0; i<n; i++){
        if(i==0)continue;
        if(abs(a[i] - first) >= 2)continue;
        if(visited[i]){cnt++; continue;}
        if(a[i] < first){
            bool isNot =0;
            for(int j=i; j<i+l; j++){
                if(a[j] == a[i])continue;
                else isNot =1;
            }
            if(isNot)break;
            else {
                for(int j=i; j<i+l; j++){
                visited[j] =1;
            }
            }
        }
        else if(a[i] > first){
            if(i-l < 0)break;
            bool isNot = 0;
            for(int j=i-l; j<i; j++){
                if(visited[j]){
                    isNot = 1;
                    break;
                }
                if(a[j] == a[i]-1)continue;
                else {isNot = 1; break;}
            }
            if(isNot)break;
        }
        first = a[i];
        cnt ++;
    }
    if(cnt == n)ret++;
}

int main() {
    cin >> n >> l;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> ar[i][j];
        }
    }
    for(int i=0; i<n; i++){
        int temp = ar[i][0];
        bool isTrue = 1;
        for(int j=0; j<n; j++){
            if(ar[i][j] != temp)isTrue=0;
        }
        if(isTrue)ret++;
        else hv.push_back(i);
    }
        for(int i=0; i<n; i++){
        int temp = ar[0][i];
        bool isTrue = 1;
        for(int j=0; j<n; j++){
            if(ar[j][i] != temp)isTrue=0;
        }
        if(isTrue)ret++;
        else vv.push_back(i);
    }
    for(int i: vv)count(i,'v');
    for(int i: hv)count(i,'h');
    
    
    
    cout << ret << '\n';
    return 0;
}
