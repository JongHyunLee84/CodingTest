#include <bits/stdc++.h>
using namespace std;

int n, ar[1000004], ret[1000004];
stack<int> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    memset(ret, -1, sizeof(ar));
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> ar[i];
        while(s.size() && ar[s.top()] < ar[i]){
            ret[s.top()] =  ar[i]; s.pop();
        }
        s.push(i);
    }
    for(int i=0; i<n; i++)cout << ret[i] << ' ';

    return 0;
}
