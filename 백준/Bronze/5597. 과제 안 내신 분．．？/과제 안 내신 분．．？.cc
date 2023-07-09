#include <bits/stdc++.h>
using namespace std;

int ar[104], N, M, j, k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // cin >> N >> M;
    for(int i=1; i<=28; i++){
        cin >> M;
        ar[M] = 1;
    }
    for(int i=1; i<=30; i++){
        if(ar[i] == 0)cout << i << ' ';
    }
    return 0;
}
