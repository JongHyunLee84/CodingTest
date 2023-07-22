#include <iostream>
using namespace std;
int a, v = 1, ret = 1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while(1){
        cin >> a;
        int b = 0;
        if(a == -1)return 0;
        for(int i=1; i<a; i++){
            if(a % i == 0)b += i;
        }
        if(b == a){
            cout << a << " = " << "1";
            for(int i=2; i<a; i++){
                if(a % i == 0)cout << " + " << i;
            }
            cout << '\n';
        }else cout << a << " is NOT perfect." << '\n';
    }
    return 0;
}  
