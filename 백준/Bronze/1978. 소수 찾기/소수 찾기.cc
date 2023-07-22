#include <iostream>
using namespace std;
int n, a, v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        int b = 1, ret = 0;
        while(a >= b){
            if(a % b == 0)ret++;
            b++;
        }
        if(ret == 2)v++;
    }
    cout << v << '\n';
    return 0;
}  
