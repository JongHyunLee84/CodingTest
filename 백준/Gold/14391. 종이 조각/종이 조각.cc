#include <bits/stdc++.h>
using namespace std;   

int n, m, ar[5][5], arr[5], ret;
string temp;



void go(int a[5], int y){
    if(y >= n){
        vector<string> v;
        int sum = 0;
        
        for(int i=0; i<n; i++){
            string s = "";
            for(int j=0; j<m; j++){
                if( !(a[i] & (1<<j)) ){
                    s += to_string(ar[i][j]);
                }else {
                    if(s != "")v.push_back(s);
                    s = "";
                }
            }
            if(s != "")v.push_back(s);
        }
        
        for(int i=0; i<m; i++){
            string s = "";
            for(int j=0; j<n; j++){
                if( (a[j] & (1<<i)) ){
                    s += to_string(ar[j][i]);
                }else {
                    if(s != "")v.push_back(s);
                    s = "";
                }
            }
            if(s != "")v.push_back(s);
            
        }
    

        
        for(string i : v)sum += stoi(i);
        // if(sum > 2000) {
        //     for(int i=0; i<n; i++){
        //         cout << ar[n] << '\n';
        //     }
        // }
        ret = max(ret, sum);
        return;
    }
    for(int i=0; i<(1<<m); i++){
        a[y] = i;
        go(a, y+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> temp;
        for(int j=0; j<m; j++){
            ar[i][j] = temp[j] - '0';
        }
    }
    go(arr,0);
    cout << ret << '\n';
    return 0;
}
