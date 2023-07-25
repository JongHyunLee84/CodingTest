#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, c;
map<int, int> mp1, mp2;

bool isTri(int a, int b, int c){
    vector<int> v = {a, b, c};
    sort(v.begin(), v.end());
    if(v[2] < v[0] + v[1])return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c;
    if(a == b && b == c && a == c){
        cout << a + b + c;
        return 0;
    }
    vector<int> v = {a, b, c};
    sort(v.begin(), v.end());
    int sum = v[0] + v[1];
    if(sum > v[2])cout << sum + v[2];
    else cout << sum * 2 - 1;
    
    return 0;
}
