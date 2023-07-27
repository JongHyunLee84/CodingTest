#include <bits/stdc++.h>
using namespace std;

int n, k, temp, sum;
vector<int> v;

int main()
{
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cout << v[n-k];
    return 0;
}
