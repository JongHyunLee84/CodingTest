#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, ar[104], ret;

bool isCreator(int num) {
    int sum = num;
    string s = to_string(num);
    for(char i : s){
        sum += i - '0';
    }
    if(sum == n)return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i=1; i<=1000000; i++){
        if(isCreator(i)){
            cout << i << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
    return 0;
}


