#include <bits/stdc++.h>
using namespace std;

int n, m, f, e;

int main()
{
    cin >> n >> m;
    vector<int> v(n);
    for(int i=1; i<=n; i++){
        v[i-1] = i;
    }
    for(int i=0; i<m; i++){
        cin >> f >> e; f--; e--;
        vector<int> temp(e-f+1);
        for(int j=f; j<=e; j++){
            temp[j-f] = v[j];
        }
        reverse(temp.begin(), temp.end());
        for(int j=f; j<=e; j++){
            v[j] = temp[j-f];
        }
    }
    for(int i=0; i<n; i++)cout << v[i] << ' ';
    return 0;
}
