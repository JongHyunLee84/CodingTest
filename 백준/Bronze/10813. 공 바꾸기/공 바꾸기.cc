#include <bits/stdc++.h>
using namespace std;

int ar[104], N, M, j, k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i=1; i<=N; i++)ar[i] = i;
    for(int z=1; z<=M; z++){
        cin >> j >> k;
        int a = ar[j];
        int b = ar[k];
        ar[j] = b;
        ar[k] = a;
    }
    for(int z=1; z<=N; z++)cout << ar[z] << ' ';
    return 0;
}
