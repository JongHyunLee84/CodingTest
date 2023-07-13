#include <bits/stdc++.h>
using namespace std;

int ar[104][104], br[104][104], n, m;

int main()
{
    cin >> n >> m;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> ar[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> br[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << ar[i][j] + br[i][j] << ' ';
            }
            cout << '\n';
        }
    return 0;
}
