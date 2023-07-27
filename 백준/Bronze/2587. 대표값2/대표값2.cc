#include <bits/stdc++.h>
using namespace std;

int n, temp, sum;
vector<int> v;

int main()
{
    for(int i=0; i<5; i++){
        cin >> temp;
        sum += temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cout << sum / 5 << ' ' << v[2] << '\n';
    return 0;
}
