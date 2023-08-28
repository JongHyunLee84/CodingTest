#include <bits/stdc++.h>
using namespace std;

int t, ret, temp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for(int z=0; z<t; z++){
        cin >> temp;
        int two = 0, five = 0;
        for(int i=2; i<=temp; i*=2){
            two += temp / i;
        }
        for(int i=5; i<=temp; i*=5){
            five += temp / i;
        }
        cout << min(two, five) << '\n';
        }
    return 0;
}
