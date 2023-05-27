#include <bits/stdc++.h>
using namespace std;

int t, n, m, temp;

int check(int temp, vector<int> &v){
    int l = 0, r = v.size() - 1;
    int mid;
    
    while(l <= r) {
        mid = (l+r)/2;
        if(v[mid] > temp)r = mid - 1;
        else if(v[mid] == temp)return 1;
        else l = mid + 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t; 
    while(t--){
        cin>>n;
        vector<int> v;
        while(n--){
            cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        cin>>m;
        while(m--){
            cin >> temp;
            cout << check(temp,v) << '\n';;
        }
    }
    return 0;
}
