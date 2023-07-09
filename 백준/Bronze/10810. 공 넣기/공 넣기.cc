#include <bits/stdc++.h>
using namespace std;

int ar[104], N, M, i, j, k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int z=1; z<=M; z++){
        cin >> i >> j >> k;
        for(int q=i; q<=j; q++){
            ar[q] = k;
        }
    }
    for(int z=1; z<=N; z++)cout << ar[z] << ' ';
    return 0;
}
