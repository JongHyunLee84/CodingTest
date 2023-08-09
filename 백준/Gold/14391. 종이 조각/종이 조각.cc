#include <bits/stdc++.h>
using namespace std;

int n, m, ar[6][6], visited[6][6], result;

int main()
{
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            ar[i][j] = s[j] - '0';
        }
    }
    for(int s=0; s<(1<<n*m); s++){
        int ret = 0;
        for(int i=0; i<n; i++){
            string str;
            for(int j=0; j<m; j++){
                if(s & (1 << i*m +j)){
                    str += ar[i][j] + '0';
                }else{
                    if(str!="")ret += stoi(str);
                    str = "";
                } 
            }
            if(str!="")ret += stoi(str);
        }
        for(int j=0; j<m; j++){
            string str;
            for(int i=0; i<n; i++){
                if(!(s & (1 << i*m +j))){
                    str += ar[i][j] + '0';
                }else{
                    if(str!="")ret += stoi(str);
                    str = "";
                } 
            }
            if(str!="")ret += stoi(str);
        }
        // cout << s << ' ' << ret << '\n';
        result = max(result, ret);
    }
    cout << result << '\n';
    return 0;
}
