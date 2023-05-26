#include <bits/stdc++.h>
using namespace std;

int a, b, ret;

int main()
{
    cin >> a >> b;
    vector<int> va(a), vb(b);
    for(int i=0; i<a; i++){
        cin >> va[i];
    }
    for(int j=0; j<b; j++){
        cin >> vb[j];
    }
    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());
    for(int i=0; i<a; i++){
        int l = 0, r = b - 1, mid;
        while(l <= r) {
            mid = (l+r)/2;
            if(vb[mid] == va[i]){
                ret++;
                break;
            }else if(vb[mid] > va[i])r = mid - 1;
            else l = mid + 1;
        }
    }
    cout << (a + b) - 2*ret << '\n';

    return 0;
}
