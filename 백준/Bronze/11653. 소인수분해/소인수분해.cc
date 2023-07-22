#include <iostream>
using namespace std;
int ar[10004], a = 2, b, min_ = 1e9, sum_, n;

void make_prime(int num){
    for(int i=num; i<=10000; i++){
        if(num*i <= 10000)ar[num*i] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    if(n == 1)return 0;
    while(n > 1){
        // cout << n << ' ' << a << '\n';
        if(n % a == 0){
            cout << a << '\n';
            n /= a;
        }
        else a++;
    }
    return 0;
}  
