#include<bits/stdc++.h> 
using namespace std;     
typedef long long ll;
int n, m, fix[44], temp;
ll ar[44];

ll go(int idx){
    if(idx == 1)return 1;
    if(idx == 2){
        if(!fix[1] && !fix[2]){return 2;}
        else return 1;
    }
    if(ar[idx])return ar[idx];
    
    ll &ret = ar[idx];
    ret += go(idx-1);
    if(!fix[idx] && !fix[idx-1]){
    ret += go(idx-2);
    }
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){cin >> temp; fix[temp] = 1;}
    cout << go(n) << '\n';
    return 0;   
}
