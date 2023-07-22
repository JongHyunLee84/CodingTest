#include <iostream>
using namespace std;
int ar[10004], a, b, min_ = 1e9, sum_;

void make_prime(int num){
    for(int i=num; i<=10000; i++){
        if(num*i <= 10000)ar[num*i] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i=2; i<5000; i++){
        make_prime(i);
    }
    cin >> a >> b;
    for(int i=a; i<=b; i++){
        if(ar[i] == 0 && i != 1){
            min_ = min(min_, i);
            sum_ += i;
        }
    }
    if(sum_ != 0)cout << sum_ << '\n' << min_;
    else cout << -1 << '\n';
    return 0;
}  
