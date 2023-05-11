#include <bits/stdc++.h>
using namespace std;   
int m, s, tempi;
string temps;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> temps;
        if(temps == "add") {
            cin >> tempi;
            s |= (1 << tempi);
        }
        else if(temps == "remove"){
            cin >> tempi;
            s &= ~(1 << tempi);
            }
        else if(temps == "check" ){
            cin >> tempi;
            if(s & (1<<tempi))cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(temps == "toggle"){
            cin >> tempi;
            s ^= (1<<tempi);
            }
        else if(temps == "all") s = (1<<21)-1;
        else s = 0;
    }
    return 0;
}