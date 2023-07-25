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
    while(1) {
    cin >> a >> b >> c;
    if(a == 0 && b == 0 && c ==0)break;
    if(a == b && b == c && c == a)cout << "Equilateral" << '\n';
    else if(isTri(a,b,c) && a == b || a == c || b == c)cout << "Isosceles" << '\n';
    else if(isTri(a,b,c) && a != b && a != c && b != c)cout << "Scalene" << '\n';
    else cout << "Invalid" << '\n';
    }
    return 0;
}
