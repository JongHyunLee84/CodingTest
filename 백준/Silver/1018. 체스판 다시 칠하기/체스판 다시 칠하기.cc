#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, n, ret = 1e9;
string s;
string ar[54];

void how_many(int y, int x){
    string first = "BWBWBWBW", second = "WBWBWBWB";
    int sum = 0;
    for(int i=y; i<y+8; i++){
        if((i-y)%2 == 0){
        for(int j=x; j<x+8; j++){
            if(ar[i][j] != first[j-x])sum++;
        }
        }
        else {
        for(int j=x; j<x+8; j++){
            if(ar[i][j] != second[j-x])sum++;
        }
        }
    }
    ret = min(ret, sum);
    
    first = "WBWBWBWB";
    second = "BWBWBWBW";
    sum = 0;
        for(int i=y; i<y+8; i++){
            if(sum >= ret)break;
        if((i-y)%2 == 0){
        for(int j=x; j<x+8; j++){
            if(ar[i][j] != first[j-x])sum++;
        }
        }
        else {
        for(int j=x; j<x+8; j++){
            if(ar[i][j] != second[j-x])sum++;
        }
        }
    }
    ret = min(ret, sum);
    }


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> m >> n;
    for(int i=0; i<m; i++){
        cin >> ar[i];
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i+7 > m || j+7 > n)continue;
            how_many(i,j);
        }
    }
    cout << ret << '\n';
    return 0;
}


