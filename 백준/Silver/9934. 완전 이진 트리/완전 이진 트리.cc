#include <bits/stdc++.h>
using namespace std;

int k, ar[1030] ;
vector<int> v[14];

void go(int start, int end, int level){
    if(start>end)return;
    if(start == end){
        v[level].push_back(ar[start]);
        return;
    }
    
    int mid = (start + end) / 2;
    v[level].push_back(ar[mid]);
    
    go(start, mid-1, level+1);
    go(mid+1, end, level+1);
}


int main() {
    cin >> k;
    int end = pow(2,k)-1;
    for(int i=0; i<end; i++){
        cin >> ar[i];
    }
    go(0, end, 0);
    for(int i=0; i<k; i++){
        for(int j : v[i]){
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}
