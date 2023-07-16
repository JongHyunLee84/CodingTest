 #include <bits/stdc++.h>
 using namespace std;
 
 int n, ret = 1, add = 6, times = 1;
 int main() {
    cin >> n;
    while(1){
        if(n <= ret){
            cout << times << '\n';
            break;
        }
        ret += add;
        add += 6;
        times++;
    }
    return 0;
 }