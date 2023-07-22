#include <iostream>
using namespace std;
int i = 1, n;
int main()
{
    cin >> n;
    while(n > i){
        n -= i;
        i++;
    }
    if(i % 2 == 0)cout << n << '/' << i + 1 - n;
    else cout << i + 1 - n << '/' << n;
    return 0;
}
