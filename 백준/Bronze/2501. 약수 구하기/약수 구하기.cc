#include <iostream>
using namespace std;
int a, b, v = 1, ret = 1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    while(ret <= 10000) {
        if(a % ret == 0){
            if(v == b){
                cout << ret << '\n';
                return 0;
            }
            v++;
        }
        ret ++;
    }    
    cout << 0 << '\n';
    return 0;
}  
