#include <bits/stdc++.h>
using namespace std;

int n, temp;
map<int, int> mp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n; 
    for(int i=0; i<n; i++){
        cin >> temp;
        mp[temp]++;
    }
    
    for(int i=1; i<=10000; i++){
        for(int j=0; j<mp[i]; j++){
            cout << i << '\n';
        }
    }

    return 0;
}
