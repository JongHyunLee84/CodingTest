#include <bits/stdc++.h>
using namespace std;

int ar[9][9], br[104][104], a = -1, b, c, temp;

int main()
{
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> temp;
            if(temp > a){
                a = temp;
                b = i + 1;
                c = j + 1;
            }
        }
    }
    cout << a << ' ' << b << ' ' << c;
    return 0;
}
