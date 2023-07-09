#include <bits/stdc++.h>
using namespace std;

int ar[104], N, M, j, k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i=1; i<=N; i++)ar[i] = i;
    for(int i=0; i<M; i++){
        cin >> j >> k;
        vector<int> v;
        for(int q=k; q>=j; q--){
            v.push_back(ar[q]);
        }
        int idx = 0;
        for(int q=j; q<=k; q++){
            ar[q] = v[idx];
            idx++;
        }
    }
    for(int i=1; i<=N; i++)cout << ar[i] << ' ';
    return 0;
}
