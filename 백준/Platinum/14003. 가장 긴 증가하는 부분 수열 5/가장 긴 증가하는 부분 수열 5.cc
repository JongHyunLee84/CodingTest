#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, ar[1000004], temp, len;
pair<ll, ll> ans[1000004];
stack<int> st;
int main() {
    cin >> a;
    fill(ar, ar + 1000004, 1000000001);
    for(int i=0; i<a; i++){
        cin >> temp;
        auto lowerPos = lower_bound(ar,ar+len, temp);
        if(*lowerPos == 1000000001) len++;
        *lowerPos = temp;
        ans[i].first = lowerPos - ar;
        ans[i].second = temp;
    }
    cout << len << '\n';
    for(int i= a-1; i >=0; i--){
        if(ans[i].first == len - 1){
            st.push(ans[i].second);
            len --;
        }
    }
    while(st.size()){
        cout << st.top() << ' ';
        st.pop();
    }
    return 0;
}



