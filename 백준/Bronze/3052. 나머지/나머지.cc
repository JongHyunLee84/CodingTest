#include <bits/stdc++.h>
using namespace std;

int ar[104], N, M, j, k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    vector<int> v;
    for(int i=1; i<=10; i++){
        cin >> N;
        N = N % 42;
        if(find(v.begin(), v.end(), N) == v.end()){
            v.push_back(N);
        }
    }
    cout << (int)v.size() << '\n';
    return 0;
}
