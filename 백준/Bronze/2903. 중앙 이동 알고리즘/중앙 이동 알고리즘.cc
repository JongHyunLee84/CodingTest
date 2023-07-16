 #include <bits/stdc++.h>
 using namespace std;
 
 int n, ret = 2;
 int main() {
    cin >> n;
    while(n--){
        ret = ret * 2 - 1;
    }
    cout << ret * ret << '\n';
    return 0;
 }