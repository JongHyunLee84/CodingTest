#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;
int t, b;
string a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> t; 
    for(int i=0; i<t; i++){
        cin >> a;
        if(a != "all" && a != "empty")cin >> b;
        if(a == "add")mp[b] = 1;
        else if(a == "remove")mp[b] = 0;
        else if(a == "check"){
            if(mp[b])cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(a == "toggle"){
            if(mp[b])mp[b] = 0;
            else mp[b] = 1;
        }
        else if(a == "all"){for(int j=1; j<=20; j++)mp[j] = 1;}
        else mp.clear(); 
        //{for(int j=1; j<=20; j++)mp[j] = 0;}
    }
    return 0;
}
