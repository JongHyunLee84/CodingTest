#include <bits/stdc++.h>
using namespace std;

int k, ar[1030], visited[1030];

int main() {
    cin >> k;
    for(int i=1; i<=pow(2,k)-1; i++){
        cin >> ar[i];
    }
    for(int i=k; i>0; i--){
        int n = (pow(2,i) / 2);
        int temp = n;
        while(n<pow(2,k)){
            if(!visited[n] && ar[n] != 0){
                cout << ar[n] << ' ';
                visited[n] = 1;
            }
            n += temp;
        }
        cout << '\n';
    }
    return 0;
}
