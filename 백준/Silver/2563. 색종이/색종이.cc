#include <bits/stdc++.h>
using namespace std;

int n, ar[100][100], a, b, ret;
string s;


int main()
{
   cin >> n;
   for(int z=0; z<n; z++){
       cin >> a >> b; a--; b--;
       for(int i=a; i<a+10; i++){
           for(int j=b; j<b+10; j++){
               ar[i][j] = 1;
           }
       }
   }
   for(int i=0; i<100; i++){
       for(int j=0; j<100; j++){
           if(ar[i][j] == 1)ret ++;
       }
   }
   cout << ret << '\n';
    return 0;
}
