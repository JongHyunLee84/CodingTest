#include <iostream>
using namespace std;
int a, b, v, ret;
int main()
{
    cin >> a >> b >> v;
    int mm = a - b;
    cout << (v-b-1) / mm + 1 << '\n';
    return 0;
}  
