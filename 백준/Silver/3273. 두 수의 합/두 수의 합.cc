#include <bits/stdc++.h>
using namespace std;

int n, x, ar[100004], ret;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    cin >> x;
    sort(ar, ar+n);
    int a = 0;
    int b = n-1;
    
    while(a < b){
        if(ar[a] + ar[b] == x){
            ret++;
            a++;
            b--;
        } else if(ar[a] + ar[b] > x) {
            b--;
        } else {
            a++;
        }
    }
    cout << ret << '\n';
    return 0;
}
