#include <iostream>
using namespace std;

int n, ret;
string s;
char c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for(int i=0; i<n; i++){
        ret += s[i] - '0';
    }
    cout << ret << '\n';    
    
    return 0;
}
