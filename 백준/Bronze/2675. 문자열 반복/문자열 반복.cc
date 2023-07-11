#include <iostream>
using namespace std;

int n, ret;
string s;
char c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> ret >> s;
        for(int j = 0; j<s.size(); j++){
            for(int k = 0; k<ret; k++){
                cout << s[j];
            }   
        }
        cout << '\n';
    }
    
    return 0;
}
